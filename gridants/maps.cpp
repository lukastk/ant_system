#include "antsim.h"

Simulation* map1() {
	int worldw = 11;
	int worldh = 11;

	double backwardbias = 0.1;
	double traceIncrease = 0.5;
	double traceBaseLine = 0;
	double traceDecay = 0.99;
	Point nest(0, 0);
	Point food(worldw - 1, 0);

	int numOfAnts = 1000;
	Point antOrigin1(0, 0);
	Point antOrigin2(0, 0);

	Simulation* sim = new Simulation(backwardbias,
									traceIncrease,
									traceBaseLine,
									traceDecay,
									nest, food,
									worldw, worldh);

	for (int y = 1; y < worldh - 1; y++) {
		for (int x = 1; x < worldw - 1; x++) {
			sim->setBlockOpenAt(y, x, false);
		}
	}



	// Set up ants
	for (int i = 0; i < numOfAnts; i++) {
			Ant* ant = new Ant(antOrigin2, NODIR, false);
			sim->addAnt(ant);
	}
	for (int i = 0; i < numOfAnts; i++) {
			Ant* ant = new Ant(antOrigin1, NODIR, false);
			sim->addAnt(ant);
	}

	/*
	// Set up ants
  // Uncomment for random placement of ants.
	for (int i = 0; i < numOfAnts; i++) {
		Point p;
		int n = (rand() % worldw);

		if ( (rand() % 2) == 1 ) {
			p.x = (rand() % 2) * (worldw - 1);
			p.y = n;
		} else {
			p.y = (rand() % 2) * (worldh - 1);
			p.x = n;
		}

		Ant* ant = new Ant(p, NODIR, false);
		sim->addAnt(ant);
	}*/

	return sim;
}

Simulation* map2() {
	int worldw = 11;
	int worldh = 11;

	double backwardbias = 0.1;
	double traceIncrease = 0.5;
	double traceBaseLine = 0;
	double traceDecay = 0.99;
	Point nest(0, 5);
	Point food(10, 5);

	int numOfAnts = 1000;
	Point antOrigin1(0, 5);
	Point antOrigin2(1, 5);

	Simulation* sim = new Simulation(backwardbias,
									traceIncrease,
									traceBaseLine,
									traceDecay,
									nest, food,
									worldw, worldh);

	for (int y = 0; y < worldh; y++) {
		for (int x = 0; x < worldw; x++) {
			sim->setBlockOpenAt(y, x, false);
		}
	}

	sim->setBlockHorizontalLine(5, 0, 3, true);
	sim->setBlockVerticalLine(5, 3, 3, true);
	sim->setBlockVerticalLine(5, 3, -4, true);
	sim->setBlockHorizontalLine(1, 3, 5, true);
	sim->setBlockHorizontalLine(7, 3, 5, true);
	sim->setBlockVerticalLine(1, 8, 7, true);
	sim->setBlockHorizontalLine(5, 9, 2, true);

	sim->add_invisible_block(Point(3, 5));
	sim->add_invisible_block(Point(8, 5));

	// Set up ants
	for (int i = 0; i < numOfAnts; i++) {
			Ant* ant = new Ant(antOrigin2, NODIR, false);
			sim->addAnt(ant);
	}
	for (int i = 0; i < numOfAnts; i++) {
			Ant* ant = new Ant(antOrigin1, NODIR, false);
			sim->addAnt(ant);
	}

	return sim;
}

Simulation* map3() {
	int worldw = 11;
	int worldh = 11;

	double backwardbias = 0.1;
	double traceIncrease = 0.5;
	double traceBaseLine = 0;
	double traceDecay = 0.99;
	Point nest(0, 5);
	Point food(8, 5);

	int numOfAnts = 1000;
	Point antOrigin1(0, 5);
	Point antOrigin2(1, 5);

	Simulation* sim = new Simulation(backwardbias,
									traceIncrease,
									traceBaseLine,
									traceDecay,
									nest, food,
									worldw, worldh);

	for (int y = 0; y < worldh; y++) {
		for (int x = 0; x < worldw; x++) {
			sim->setBlockOpenAt(y, x, false);
		}
	}

	sim->setBlockHorizontalLine(5, 0, 4, true);
	sim->setBlockVerticalLine(5, 3, 2, true);
	sim->setBlockVerticalLine(5, 3, -2, true);
	sim->setBlockHorizontalLine(4, 3, 3, true);
	sim->setBlockHorizontalLine(6, 3, 3, true);
	sim->setBlockVerticalLine(4, 5, 3, true);
	sim->setBlockHorizontalLine(5, 5, 4, true);

	sim->add_invisible_block(Point(3, 5));
	sim->add_invisible_block(Point(5, 5));

	// Set up ants
	for (int i = 0; i < numOfAnts; i++) {
			Ant* ant = new Ant(antOrigin2, NODIR, false);
			sim->addAnt(ant);
	}
	for (int i = 0; i < numOfAnts; i++) {
			Ant* ant = new Ant(antOrigin1, NODIR, false);
			sim->addAnt(ant);
	}

	return sim;
}

Simulation* map4() {
	int worldw = 11;
	int worldh = 11;

	double backwardbias = 0.1;
	double traceIncrease = 0.5;
	double traceBaseLine = 0;
	double traceDecay = 0.99;
	Point nest(0, 0);
	Point food(3, 5);

	int numOfAnts = 1000;
	Point antOrigin1(0, 5);
	Point antOrigin2(0, 6);

	Simulation* sim = new Simulation(backwardbias,
									traceIncrease,
									traceBaseLine,
									traceDecay,
									nest, food,
									worldw, worldh);

	for (int y = 1; y < worldh - 1; y++) {
		for (int x = 1; x < worldw - 1; x++) {
			sim->setBlockOpenAt(y, x, false);
		}
	}

	sim->setBlockVerticalLine(0, 3, 10, true);

	sim->add_invisible_block(Point(3, 0));
	sim->add_invisible_block(Point(3, 10));

	// Set up ants
	for (int i = 0; i < numOfAnts; i++) {
			Ant* ant = new Ant(antOrigin2, NODIR, false);
			sim->addAnt(ant);
	}
	for (int i = 0; i < numOfAnts; i++) {
			Ant* ant = new Ant(antOrigin1, NODIR, false);
			sim->addAnt(ant);
	}

	return sim;
}
