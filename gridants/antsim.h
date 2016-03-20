#ifndef ANTSIM_H
#define ANTSIM_H

#define NO_STDIO_REDIRECT

#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <random>

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_real_distribution.hpp>

enum Directions {NODIR, UP, RIGHT, DOWN, LEFT};

/*
 * Struct to contain a 2D cartesian coordinate.
 */
struct Point {
	int x;
	int y;

	Point() {};
	Point(int _x, int _y) : x(_x), y(_y) {}

	bool operator==(const Point &other) const {
		return other.x == this->x && other.y == this->y;
	}
};
typedef struct Point Point;

/* Point addition */
inline Point operator+(Point lhs, const Point& rhs) {
	return Point(lhs.x + rhs.x, lhs.y + rhs.y);
}

/*
 * The data structure for each block of the grid.
 */
struct BlockData {
	bool open;
	double trace;
};
typedef struct BlockData BlockData;

/*
 * Struct to maintain the information of the ant.
 */
struct Ant {
	Point pos;
	Directions prev_dir;
	bool has_food;

	Ant(Point _pos, Directions _prev_dir, bool _has_food)
	  : pos(_pos), prev_dir(_prev_dir), has_food(_has_food) {}
};
typedef struct Ant Ant;

/*
 * Simulation class, in which all the logic of the algorithm is executed.
 */
class Simulation {
	double backwardBias;
	double traceIncrease;
	double traceBaseLine;
	double traceDecay;
	Point nest;
	Point food;
	BlockData** world;
	std::vector<Ant*> ants;

	std::vector<Point> invisible_blocks;

	public:
		const int world_w;
		const int world_h;

		Simulation( double _backwardBias,
					double _traceIncrease,
					double _traceBaseLine,
					double _traceDecay,
					Point _nest, Point _food,
					int _world_w, int _world_h);

		~Simulation();

		/* Initialize the simulation */
		void init();

		/* Add ant traces to each block */
		void addAntTraces();

		/* Decay all ant traces */
		void decayWorld();

		/* Adds an ant to the simulation */
		void addAnt(Ant* ant);

		/* Returns a random move for a specified ant */
		Point getRandomMove(Ant* ant);

		/* Update the position of an ant */
		void updateAnt(Ant* ant);

		/* Updates the simulation */
		void update();

		/* Returns the minimum trace found in the map */
		double minTrace();

		/* Returns th maximum trace found in the map */
		double maxTrace();

		/* Returns the minimum amount of ants found in a block */
		int minAnts();

		/* Returns the maximum amount of ants found in a blok */
		int maxAnts();

		/* Returns the trace at the specified coordinates */
		double getTraceAt(int y, int x);

		/* Returns true if the block is open at the specified coordinates */
		bool getBlockOpenAt(int y, int x);

		/* Sets the block's accesibility at the specified coorindates to val */
		void setBlockOpenAt(int y, int x, bool val);

		/* Returns a vector of the ants */
		std::vector<Ant*>* getAnts();

		/* Sets the accesibility of a horizontal line of blocks to val */
		void setBlockHorizontalLine(int y0, int x0, int length, bool val);

		/* Sets the accesibility of a vertical line of blocks to val */
		void setBlockVerticalLine(int y0, int x0, int length, bool val);

		/* Returns the number of ants at the specified coorindates */
		int getNumOfAntsAt(int y, int x);

		/* Returns the location of the nest */
		Point getNest() { return nest; }

		/* Returns the location of the food source */
		Point getFood() { return food; }

		/* Returns the total number of ants */
		int getAntNum() { return ants.size(); }

		/* Adds a block that won't be considered into the heat map */
		void add_invisible_block(Point p) { invisible_blocks.push_back(p); }

	private:

		Directions getOppositeDirection(Directions d);
		boost::random::mt19937 random;
};

Simulation* initialize_simulation();

#endif
