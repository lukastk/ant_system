#ifndef TSP_ANTS_H
#define TSP_ANTS_H

#define NO_STDIO_REDIRECT

#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <ctime>

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_real_distribution.hpp>

struct Ant {
	int town;
	std::vector<int> tabu_list;
	std::vector<int*> path_history;
	std::vector<double> path_lengths;

	Ant(int _town) : town(_town) {}
	~Ant();
};
typedef struct Ant Ant;

struct Edge {
	double distance;
	double trace;

	Edge() {}
	Edge(double _distance, double _trace) : distance(_distance), trace(_trace) {}

	double get_visibility() { return 1.0/distance; }
};
typedef struct Edge Edge;

class Simulation {

	/* The ants used in the simulation. */
	std::vector<Ant*> ants;

	/* A two-dimensional matrix of the edge weights. */
	Edge** edges;

	/* Random number generator. */
	boost::random::mt19937 random = boost::random::mt19937{static_cast<std::uint32_t>(std::time(0))};

	/* Number of towns */
	int n_towns;

	/* Number of time-steps run in simulation. */
	int n_time;

	/* Number of cycles run in simulation. */
	int n_cycles;

	/* The alpha parameter decides the importance of trace. */
	double alpha_param;

	/* The beta parameter decides the importance of visibility. */
	double beta_param;

	/* The Q parameter is a multiplicative constant of the trace accumulation. */
	double q_param;

	/* Phereomone decay */
	double trace_decay;

public:

	Simulation(const int towns,
			double** edge_distances,
			const double base_trail,
			const double alpha,
			const double beta,
			const double q,
			const double _trace_decay);

	~Simulation();

	/*
	 * Add ant to the ant list.
	 */
	void addAnt(int town);

	/*
	 * Move the simulation to the next timestep.
	 */
	double update();

	/*
	 * Update *time_ticks* times.
	 */
	void update(int time_ticks);

	/*
	 * Returns the number of towns
	 */
	int get_number_of_towns() { return n_towns; }

	/*
	 * Returns the number of towns
	 */
	int get_number_of_cycles() { return n_cycles; }

	/*
	 * Gets the trace on edge (i, j). Note that the trace tensor is symmetric.
	 * Meaning that getTraceAt(i, j) == getTraceAt(j, i).
	 */
	Edge get_edge_at(int i, int j);

	/*
	 * Sets the trace on edge (i, j). Note that the trace tensor is symmetric.
	 * Meaning that getTraceAt(i, j) == getTraceAt(j, i).
	 */
	void set_edge_at(int i, int j, double distance, double trace);

	/*
	 * Returns the number of ants
	 */
	int get_number_of_ants() { return ants.size(); }

	/*
	 * Returns the path history of the specified ant
	 */
	std::vector<int*> get_ant_path_history(int ant_index);

	/*
	 * Returns the history of the lengths of the paths of the specified ant
	 */
	std::vector<double> get_ant_path_length_history(int ant_index);

	/*
	 * Clears ant path history
	 */
	void clear_ant_path_history();

	/*
	 * Clears ant path length history
	 */
	void clear_ant_path_length_history();

private:

	/*
	 * Decay traces
	 */
	void decay_traces();

	/*
	 * Dynamically create array to represent the n*n edges of n towns.
	 */
	void set_up_edge_array(int n, double** edge_distances, double base_trail);

	/*
	 * Return the probabalistic weight of an ant traversing across an edge.
	 * i - signifies the current position of the ant
	 * j - signifies the town that the ant would move to
	 * Note that the weight returned isn't normalized
	 */
	 double edge_weight(int i, int j, Ant* ant);

	 /*
	  * Returns a double array of N elements (where N is the number of towns).
		* Where each element represents the normalized probabality of the ant
		* traversing the corresponding edge.
		*/
	 double* get_all_edge_weights(Ant* ant);

	 /*
	  * Based on the edge probabilities, it'll return a random town for the
		* ant to move to.
		*/
	 int make_ant_random_move(double* edgeProbabilities);

	 /*
	  * Returns the path length of an ant, based on a list of towns its visited.
		*/
	 double calculate_ant_path_length(std::vector<int>* antpath);
};

#endif
