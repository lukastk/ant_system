#include "tsp_ants.cpp"
#include "wstp.h"

/*** Main ***/

int main(int argc, char* argv[]) {
	return WSMain(argc, argv);
}

/*** Global variables ***/

Simulation* sim;

/*** Mathematica methods ***/

/*
 * Initializes the simulation with the given parameters
 */
int startSimulation(
		double* edge_distances_data,
		long edge_distances_data_length,
		double base_trail,
		double alpha,
		double beta,
		double q,
		double trace_decay) {

		// Form edge distance array

		int towns = int(sqrt(edge_distances_data_length)); // Due to the fact that it's a square matrix.
		double** edge_distances = new double*[towns];
		int index = 0;
		for (int i = 0; i < towns; i++) {
			edge_distances[i] = new double[towns];

			for (int j = 0; j < towns; j++) {
				edge_distances[i][j] = edge_distances_data[index];
				index++;
			}
		}

		sim = new Simulation(towns, edge_distances, base_trail, alpha, beta, q, trace_decay);

		for (int i = 0; i < towns; i++) {
			free(edge_distances[i]);
		}
		free(edge_distances);

		return 1;
}

/*
 * Returns a matrix of the level of trace on each edge
 */
void getEdgeTraces() {
	int towns = sim->get_number_of_towns();
	double edges[towns][towns];

	for (int i = 0; i < towns; i++) {
		for (int j = 0; j < towns; j++) {
			edges[i][j] = sim->get_edge_at(i, j).trace;
		}
	}

	int dims[] = {towns, towns};

	WSPutReal64Array(stdlink, (double *)edges, dims, NULL, 2);
}

/*
 * Updates the simulation for one cycle.
 */
double updateSimulation() {
	return sim->update();
}

/*
 * Updates the simulation for the specified amount of cycles..
 */
int updateSimulation(int ticks) {
	sim->update(ticks);
}

/*
 * Adds an ant to the specified town.
 */
int addAnt(int town) {
	sim->addAnt(town);

	return 1;
}

/*
 * Returns the number of ants.
 */
int getNumberOfAnts() {
	return sim->get_number_of_towns();
}

/*
 * Returns the number of towns.
 */
int getNumberOfTowns() {
	return sim->get_number_of_towns();
}

/*
 * Returns the number of cycles so far.
 */
int getNumberOfCycles() {
	return sim->get_number_of_cycles();
}

/*
 * Returns the path histories of all the ants.
 */
void getAntPathHistories() {
	std::vector<double> allpaths_vec;

	for (int i = 0; i < sim->get_number_of_ants(); i++) {
		std::vector<int*> paths = sim->get_ant_path_history(i);
		for (std::vector<int*>::iterator it = paths.begin() ; it != paths.end(); ++it) {
			for (int j = 0; j < (sim->get_number_of_towns() + 1); j++){
				allpaths_vec.push_back((*it)[j] + 1); // +1 because of Mathematica index notation.
			}
		}
	}

	double* allpaths = new double[allpaths_vec.size()];
	std::copy(allpaths_vec.begin(), allpaths_vec.end(), allpaths);

	sim->clear_ant_path_history();

	WSPutReal64List(stdlink, allpaths, allpaths_vec.size());
}

/*
 * Returns the path length histories of all the ants.
 */
void getAntPathLengthHistories() {
	std::vector<double> allpaths_vec;

	for (int i = 0; i < sim->get_number_of_ants(); i++) {
		std::vector<double> lengths = sim->get_ant_path_length_history(i);

		for (std::vector<double>::iterator it = lengths.begin() ; it != lengths.end(); ++it) {
			allpaths_vec.push_back(*it);
		}
	}

	double* allpaths = new double[allpaths_vec.size()];
	std::copy(allpaths_vec.begin(), allpaths_vec.end(), allpaths);

	sim->clear_ant_path_length_history();

	WSPutReal64List(stdlink, allpaths, allpaths_vec.size());
}

/*
 * Ends simulation
 */
int endSimulation() {
	free(sim);
	return 1;
}
