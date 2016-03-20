#include "tsp_ants.cpp"

using namespace std;

Simulation* sim;

void print_traces() {
  for (int i = 0; i < sim->get_number_of_towns(); i++) {
    for (int j = 0; j <= i; j++) {
      printf("%.2f ", sim->get_edge_at(i, j).trace);
    }
    cout << endl;
  }

  cout << endl;
}

void updateAndPrint() {
  sim->update();
  print_traces();
}
void updateAndPrint(int ticks) {
  sim->update(ticks);
  print_traces();
}

int* getAntPathHistories() {
	int allpaths_length = sim->get_number_of_towns()*sim->get_number_of_cycles()*sim->get_number_of_ants();
	int* allpaths = new int[allpaths_length];
	int index = 0;

	for (int i = 0; i < sim->get_number_of_ants(); i++) {
		std::vector<int*> paths = sim->get_ant_path_history(i);
		for (std::vector<int*>::iterator it = paths.begin() ; it != paths.end(); ++it) {
			for (int j = 0; j < sim->get_number_of_towns(); j++){
				allpaths[index ] = (*it)[j];
				index++;
			}
		}
	}

	return allpaths;
}

int startSimulation() {
    int towns = 4;
		double base_trail = 0.1;
		double alpha = 1;
		double beta = 1;
		double q = 1;
		double trace_decay = 0.99;
		double** edge_distances = new double*[towns];

		int index = 0;
		for (int i = 0; i < towns; i++) {
			edge_distances[i] = new double[towns];

			for (int j = 0; j < towns; j++) {
				edge_distances[i][j] = 1;
			}
		}

    edge_distances[0][3] = edge_distances[3][0] = 1.4;
    edge_distances[1][2] = edge_distances[2][1] = 1.4;

		sim = new Simulation(towns, edge_distances, base_trail, alpha, beta, q, trace_decay);

    sim->addAnt(0);
    sim->addAnt(1);
    sim->addAnt(2);

    print_traces();

    for (int i = 0; i < 100; i++) {
      sim->update();
    }

    /*std::vector<double> lengths = sim->get_ant_path_length_history(0);
    for (std::vector<double>::iterator it = lengths.begin() ; it != lengths.end(); ++it) {
			std::cout << *it << std::endl;
		}*/

    /*
    int allpaths_length = sim->get_number_of_towns()*sim->get_number_of_cycles()*sim->get_number_of_ants();
    int* hist = getAntPathHistories();
    for (int i=0; i < allpaths_length; i++) {
      std::cout << hist[i] << " ";
    }
    std::cout << std::endl;
    */

		for (int i = 0; i < towns; i++) {
			free(edge_distances[i]);
		}
		free(edge_distances);

    free(sim);

		return 1;
}

int main(int argc, char* argv[]) {
  startSimulation();
}
