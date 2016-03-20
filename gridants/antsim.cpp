#include "antsim.h"
#include "maps.cpp"

using namespace std;

Point moves[] = { Point(0, 0), Point(0, -1), Point(1, 0), Point(0, 1), Point(-1, 0) };

Simulation::Simulation(
	double _backwardBias,
	double _traceIncrease,
	double _traceBaseLine,
	double _traceDecay,
	Point _nest, Point _food,
	int _world_w, int _world_h) :
	backwardBias(_backwardBias),
	traceIncrease(_traceIncrease),
	traceBaseLine(_traceBaseLine),
	traceDecay(_traceDecay),
	nest(_nest), food(_food),
	world_w(_world_w), world_h(_world_h) {

	// Set up the array for the map
	this->world = new BlockData*[this->world_h];
	for (int y = 0; y < this->world_h; y++) {
		this->world[y] = new BlockData[this->world_w];

		for (int x = 0; x < this->world_w; x++) {
			this->world[y][x].open = true;
			this->world[y][x].trace = 0.0;
		}
	}

	random = boost::random::mt19937();
}

Simulation::~Simulation() {
	for (int y = 0; y < this->world_h; y++) {
		delete world[y];
	}

	delete world;
}

void Simulation::init() {
	// Apply baseline
	for (int y = 0; y < this->world_h; y++) {
		for (int x = 0; x < this->world_w; x++) {
			this->world[y][x].trace = this->traceBaseLine;
		}
	}
}

/* Decay the world's traces */
void Simulation::decayWorld() {
	for (int y = 0; y < this->world_h; y++) {
		for (int x = 0; x < this->world_w; x++) {
			this->world[y][x].trace *= traceDecay;

		}
	}
}

void Simulation::addAntTraces() {
	for (std::vector<Ant*>::const_iterator it = ants.begin(), end = ants.end(); it != end; ++it) {
		world[(*it)->pos.y][(*it)->pos.x].trace += traceIncrease;
	}
}

void Simulation::addAnt(Ant* ant) {
	this->ants.push_back(ant);
}

Directions Simulation::getOppositeDirection(Directions d) {
	switch(d) {
		case LEFT:
			return RIGHT;
		case RIGHT:
			return LEFT;
		case UP:
			return DOWN;
		case DOWN:
			return UP;
		default:
			return NODIR;
	}
}

Point Simulation::getRandomMove(Ant* ant) {
	// Check available moves
	int numOfMoves = 0;
	std::vector<Directions> directions;
	std::list<double> traces;
	double totalTraces = 0;

	int backDirIndex = -1;
	double backDirTrace;

	Point randomMove(-100, -100);

	BlockData* block;

	block = &world[ant->pos.y][ant->pos.x - 1];
	if (ant->pos.x > 0 && block->open) {
		directions.push_back(LEFT);
		traces.push_back(block->trace);
		numOfMoves++;
		totalTraces += block->trace;

		if (LEFT == ant->prev_dir) {
			backDirIndex = numOfMoves - 1; // numOfMoves is effectively the index
			backDirTrace = block->trace;
		}
	}
	block = &world[ant->pos.y][ant->pos.x + 1];
	if (ant->pos.x < world_w-1 && block->open) {
		directions.push_back(RIGHT);
		traces.push_back(block->trace);
		numOfMoves++;

		if (RIGHT == ant->prev_dir) {
			backDirIndex = numOfMoves - 1;
			backDirTrace = block->trace;
		}
	}
	block = &world[ant->pos.y - 1][ant->pos.x];
	if (ant->pos.y > 0 && block->open) {
		directions.push_back(UP);
		traces.push_back(block->trace);
		numOfMoves++;
		totalTraces += block->trace;

		if (UP == ant->prev_dir) {
			backDirIndex = numOfMoves - 1;
			backDirTrace = block->trace;
		}
	}
	block = &world[ant->pos.y + 1][ant->pos.x];
	if (ant->pos.y < world_h-1 && block->open) {
		directions.push_back(DOWN);
		traces.push_back(block->trace);
		numOfMoves++;
		totalTraces += block->trace;

		if (DOWN == ant->prev_dir) {
			backDirIndex = numOfMoves - 1;
			backDirTrace = block->trace;
		}
	}

	Directions dir = NODIR;

	if (numOfMoves != 1) {
		std::list<double> probabilities;
		std::list<double>::const_iterator pher_it = traces.begin(), end = probabilities.end();
		double p = 0;
		double total_weights = 0;

		if (ant->prev_dir == NODIR ||
			(ant->pos == food && !ant->has_food) ||
			(ant->pos == nest && ant->has_food)) {

			if (ant->pos == this->nest) {
				ant->has_food = false;
			} else if (ant->pos == this->food) {
				ant->has_food = true;
			}

			for (int i = 0; i < numOfMoves; i++) {
				p = 1.0 / double(numOfMoves);
				p = p*( 1 + *pher_it);
				total_weights += p;
				probabilities.push_back(p);
				pher_it++;
			}
		} else {
			// Set the probability weights, with the backwardbias
			for (int i = 0; i < numOfMoves; i++) {
				if (i != backDirIndex) {
					p = 1.0 / double(numOfMoves) + (1 - backwardBias)/(double(numOfMoves)*(numOfMoves - 1));

				} else {
					p = backwardBias/double(numOfMoves);
				}

				p = p*( 1 + *pher_it);
				total_weights += p;
				probabilities.push_back(p);
				pher_it++;
			}
		}

		/*
		cout << ant->has_food << ": ";
		int j = 0;
		for (std::list<double>::const_iterator it = probabilities.begin(), end = probabilities.end(); it != end; ++it) {
			if (j == backDirIndex) {
				cout << "(" << *it << ")" << "-";
			} else {
				cout << *it << "-";
			}

			j++;
		}
		cout << endl;*/

		//double r = double(rand()) / double(RAND_MAX);
		boost::random::uniform_real_distribution<double> rand_dist = boost::random::uniform_real_distribution<double>(0, total_weights);
		double r = rand_dist(random);
		int i = 0;

		bool moved = false;

		for (std::list<double>::const_iterator it = probabilities.begin(), end = probabilities.end(); it != end; ++it) {
			if (r < *it) {
				moved = true;
				dir = directions[i];
				randomMove = moves[ dir ];
				break;
			} else {
				r -= *it;
			}

			i++;
		}

		if (!moved) {
			std::cerr << "Something wrong: Ant didn't move." << std::endl;
			std::cerr << r << std::endl;
		}

	} else {
		dir = directions[0];
		randomMove = moves[ dir ];
	}

	ant->prev_dir = getOppositeDirection(dir);

	return randomMove;
}

void Simulation::updateAnt(Ant* ant) {
	Point randomMove = this->getRandomMove(ant);
	ant->pos = ant->pos + randomMove;
}

void Simulation::update() {
	for (std::vector<Ant*>::const_iterator it = ants.begin(), end = ants.end(); it != end; ++it) {
		this->updateAnt(*it);
	}

	this->addAntTraces();
	this->decayWorld();

	//std::cout << ants[0]->pos.x << " " << ants[0]->pos.y << std::endl; //DEBUG
}

double Simulation::minTrace() {
	double minTrace = -1;

	for (int y = 0; y < world_h; y++) {
		for (int x = 0; x < world_w; x++) {
			if (!world[y][x].open) {
				continue;
			}

			if (minTrace == -1 || world[y][x].trace < minTrace) {
				minTrace = world[y][x].trace;
			}
		}
	}

	return minTrace;
}
double Simulation::maxTrace() {
	double maxTrace = 0;

	for (int y = 0; y < world_h; y++) {

		for (int x = 0; x < world_w; x++) {

			bool invisible_block = false;
			for (std::vector<Point>::const_iterator it = invisible_blocks.begin(), end = invisible_blocks.end(); it != end; ++it) {
				if ((*it).x == x && (*it).y == y) {
					invisible_block = true;
					break;
				}
			}

			if (invisible_block) {
				continue;
			}

			if (!world[y][x].open) {
				continue;
			}

			if (world[y][x].trace > maxTrace) {
				maxTrace = world[y][x].trace;
			}
		}
	}

	return maxTrace;
}

int Simulation::minAnts() {
	double minAnts = -1;

	for (int y = 0; y < world_h; y++) {
		for (int x = 0; x < world_w; x++) {
			if (!world[y][x].open) {
				continue;
			}

			int ants = getNumOfAntsAt(y, x);

			if (minAnts == -1 || ants < minAnts) {
				minAnts = ants;
			}
		}
	}

	return minAnts;
}
int Simulation::maxAnts() {
	double maxAnts = 0;

	for (int y = 0; y < world_h; y++) {
		for (int x = 0; x < world_w; x++) {
			if (!world[y][x].open) {
				continue;
			}

			int ants = getNumOfAntsAt(y, x);

			if (ants > maxAnts) {
				maxAnts = ants;
			}
		}
	}

	return maxAnts;
}

double Simulation::getTraceAt(int y, int x) {
	return world[y][x].trace;
}

bool Simulation::getBlockOpenAt(int y, int x) {
	return world[y][x].open;
}
void Simulation::setBlockOpenAt(int y, int x, bool val) {
	world[y][x].open = val;
}

void Simulation::setBlockVerticalLine(int y0, int x0, int length, bool val) {
	if (length > 0) {
		for (int y = y0; y < y0 + length; y++) {
			setBlockOpenAt(y, x0, val);
		}
	} else {
		for (int y = y0; y > y0 + length; y--) {
			setBlockOpenAt(y, x0, val);
		}
	}
}
void Simulation::setBlockHorizontalLine(int y0, int x0, int length, bool val) {
	if (length > 0) {
		for (int x = x0; x < x0 + length; x++) {
			setBlockOpenAt(y0, x, val);
		}
	} else {
		for (int x = x0; x > x0 + length; x--) {
			setBlockOpenAt(y0, x, val);
		}
	}
}

int Simulation::getNumOfAntsAt(int y, int x) {
	int numOfAnts = 0;

	for (std::vector<Ant*>::const_iterator it = ants.begin(), end = ants.end(); it != end; ++it) {
		if ((*it)->pos.x == x && (*it)->pos.y == y) {
			numOfAnts++;
		}
	}

	return numOfAnts;
}

std::vector<Ant*>* Simulation::getAnts() {
	return &this->ants;
}

Simulation* initalize_simulation() {
	Simulation* sim = map1();
	return sim;
}
