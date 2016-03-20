#include "tsp_ants.h"

using namespace std;

/*** Other members ***/

Ant::~Ant() {
	tabu_list.clear();

	for (std::vector<int*>::iterator it = path_history.begin() ; it != path_history.end(); ++it) {
		free(*it);
	}

	path_history.clear();
	path_lengths.clear();
}

/*** Simulation Members ***/

Simulation::Simulation(const int towns,
		double** edge_distances,
		const double base_trail,
		const double alpha,
		const double beta,
		const double q,
		const double _trace_decay) {
	n_time = 0;
	n_cycles = 0;
	n_towns = towns;
	alpha_param = alpha;
	beta_param = beta;
	q_param = q;
	trace_decay = _trace_decay;

	set_up_edge_array(n_towns, edge_distances, base_trail);
}

Simulation::~Simulation() {
	ants.clear();

	for (int i = 0; i < n_towns; i++) {
		free(edges[i]);
	}
	free(edges);
}

void Simulation::addAnt(int town) {
	Ant* ant = new Ant(town);
	ants.push_back(ant);
}

double Simulation::update() {
	double shortest_path = -1;

	// Iterate through ants, and add their current town to their tabu list
	for (std::vector<Ant*>::iterator it = ants.begin() ; it != ants.end(); ++it) {
		(*it)->tabu_list.push_back((*it)->town);
	}

	// Move the ants across the towns
	for (int i = 0; i < n_towns - 1; i++) {

		for (std::vector<Ant*>::iterator it = ants.begin() ; it != ants.end(); ++it) {
			double* edge_probabilities = get_all_edge_weights(*it);
			int next_town = make_ant_random_move(edge_probabilities);
			free(edge_probabilities);
			(*it)->town = next_town;
			(*it)->tabu_list.push_back(next_town);
		}

		n_time += 1; // Update time
	}

	// Add the starting town to the end of the taboo list, to form a complete tour
	for (std::vector<Ant*>::iterator it = ants.begin() ; it != ants.end(); ++it) {
		(*it)->tabu_list.push_back((*it)->tabu_list.at(0));
		//(*it)->tabu_list.push_back(2);
	}

	// Decay all traces
	decay_traces();

	// Relocate each ant to their original positition (first element of their
	// tabu list). And add trace to each edge.
	Ant* ant;
	for (std::vector<Ant*>::iterator it = ants.begin() ; it != ants.end(); ++it) {
		ant = *it;

		// Relocate ant to first town
		ant->town = ant->tabu_list.front();

		// Add trace

		double path_length = calculate_ant_path_length(&ant->tabu_list);
		ant->path_lengths.push_back(path_length);

		if (shortest_path == -1 || path_length < shortest_path) {
			shortest_path = path_length;
		}

		double trace_add = q_param / path_length;
		std::vector<int>::iterator last_town = ant->tabu_list.end();
		std::vector<int>::iterator next_town = ant->tabu_list.begin();
		std::vector<int>::iterator town = next_town;
		next_town++;
		double trace;

		for (std::vector<int>::iterator town = ant->tabu_list.begin() ; next_town != last_town; town = next_town++) {
			Edge edge = get_edge_at(*town, *next_town);
			trace = edge.trace + trace_add;
			set_edge_at(*town, *next_town, edge.distance, trace);
		}

		// Add tour to path registry
		int* antpath = new int[n_towns + 1]; //+1 because we include the last town
		std::copy(ant->tabu_list.begin(), ant->tabu_list.end(), antpath);
		ant->path_history.push_back(antpath);

		// Clear tabu list
		ant->tabu_list.clear();
	}

	n_cycles += 1;

	return shortest_path;
}

void Simulation::update(int time_ticks) {
	for (int i = 0; i < time_ticks; i++) {
		update();
	}
}

void Simulation::decay_traces() {
	for (int i = 0; i < n_towns; i++) {
		for (int j = 0; j <= i; j++) {
			edges[i][j].trace = edges[i][j].trace*trace_decay;
		}
	}
}

void Simulation::set_up_edge_array(int n, double** edge_distances, double base_trail) {
	/*
	 * Note that the trail tensor is symmetric. This means that we only need to
	 * consider "half" of a regular matrix. We'll therefore only construct a
	 * triangular set of arrays, and we'll use the convention that the first
	 * index of the array should always be less than the second one.
	 */

	edges = new Edge*[n];

	for (int i = 0; i < n; i++) {
		edges[i] = new Edge[n];

		// Add the edge visibilities and base-trails to each edge
		for (int j = 0; j <= i; j++) {
			edges[i][j] = Edge(edge_distances[i][j], base_trail);
		}
	}
}

Edge Simulation::get_edge_at(int i, int j) {
	// These steps are necessary, as the trace matrix is lower triangular
	int a, b;

	if (i >= j) {
		a = i;
		b = j;
	} else {
		a = j;
		b = i;
	}

	return edges[a][b];
}

void Simulation::set_edge_at(int i, int j, double distance, double trace) {
	// These steps are necessary, as the trace matrix is lower triangular
	int a, b;

	if (i >= j) {
		a = i;
		b = j;
	} else {
		a = j;
		b = i;
	}

	edges[a][b].distance = distance;
	edges[a][b].trace = trace;
}

std::vector<int*> Simulation::get_ant_path_history(int ant_index) {
	return ants.at(ant_index)->path_history;
}

std::vector<double> Simulation::get_ant_path_length_history(int ant_index) {
	return ants.at(ant_index)->path_lengths;
}

void Simulation::clear_ant_path_history() {
	for (std::vector<Ant*>::iterator it = ants.begin() ; it != ants.end(); ++it) {
		(*it)->path_history.clear();
	}
}
void Simulation::clear_ant_path_length_history() {
	for (std::vector<Ant*>::iterator it = ants.begin() ; it != ants.end(); ++it) {
		(*it)->path_lengths.clear();
	}
}

double Simulation::edge_weight(int i, int j, Ant* ant) {
	// An ant can't loop back to the same city
	if (i == j) {
		return 0;
	}

	// Check to see if town j is in tabu list. If true, return 0 probability.
	if(std::find( ant->tabu_list.begin(), ant->tabu_list.end(), j) != ant->tabu_list.end()) {
		return 0;
	}

 // Calculate probability as determined by formula.

	Edge e = get_edge_at(i, j);

	return pow(e.trace, alpha_param) * pow(e.get_visibility(), beta_param);
}

double* Simulation::get_all_edge_weights(Ant* ant) {
	double* edge_weights = new double[n_towns];
	int i = (*ant).town;
	double weight_sum = 0;

	for (int j = 0; j < n_towns; j++) {
		edge_weights[j] = edge_weight(i, j, ant);
		weight_sum += edge_weights[j];
	}

	// Normalize
	for (int n = 0; n < n_towns; n++) {
		edge_weights[n] /= weight_sum;
	}

	return edge_weights;
}

int Simulation::make_ant_random_move(double* edge_probabilities) {
	boost::random::uniform_real_distribution<double> urd = boost::random::uniform_real_distribution<double>(0, 1);
	double r = urd(random); // Get a random floating point number between 0 and 1.

	// Algorithm for choosing an edge at random.
	for (int i = 0; i < n_towns; i++) {
		if (edge_probabilities[i] > r) {
			return i;
		} else {
			r -= edge_probabilities[i];
		}
	}

	// If function reach this point, something went wrong
	std::cerr << "ERROR: Something went wrong at \"makeRandomMove\"." << std::endl;
	return -1;
}

double Simulation::calculate_ant_path_length(std::vector<int>* antpath) {
	double length = 0;

	std::vector<int>::iterator it = antpath->begin();
	int last_town = *it;
	int town;
	++it;

	for ( ; it != antpath->end(); ++it) {
		town = *it;
		length += get_edge_at(last_town, town).distance;
		last_town = town;
	}

	return length;
}
