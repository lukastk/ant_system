#include "graphics.h"

using namespace std;

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 640;

Color trace_hue_function(double p, double pmin, double pmax) {
	Color c;
	c.G = 0;



	if (pmax != pmin) {
		c.R = char(255 * (p - pmin) / (pmax - pmin));
		c.B = 255 - c.R;
	} else {
		c.R = 0;
		c.B = 255;
	}

	return c;
}

int main( int argc, char* args[] ) {
	Simulation* sim = initalize_simulation();

	//The window we'll be rendering to
  SDL_Window* window = NULL;

  //The surface contained by the window
  SDL_Surface* screenSurface = NULL;

	//Initialize SDL
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );

		return 1;
    }

	//Create window
	window = SDL_CreateWindow( "Ant Simulation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	if( window == NULL )
	{
		printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		return 1;
	}

	//Get window surface
	screenSurface = SDL_GetWindowSurface( window );

	bool quit = false;
	int squareSize = 50;

	SDL_Event e;

	int time_n = 0;

	while (!quit) {

		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}
		}

		//double minTrace = 0;//sim->minTrace();
		//double maxTrace = 0.6;//sim->maxTrace();
		double minTrace = sim->minTrace();
		double maxTrace = sim->maxTrace();

		int minAnts = sim->minAnts();
		int maxAnts = sim->maxAnts();

		//std::cout << minTrace << " " << maxTrace << std::endl;

		int margin_x = 10;
		int margin_y = 10;

		SDL_Rect worldRect;
		worldRect.x = margin_x;
		worldRect.y = margin_y;
		worldRect.w = squareSize*sim->world_w;
		worldRect.h = squareSize*sim->world_h;

		SDL_FillRect( screenSurface, &worldRect, SDL_MapRGB( screenSurface->format, 11, 0xFF, 0xFF ) );

		for (int y = 0; y < sim->world_h; y++) {
			for (int x = 0; x < sim->world_w; x++) {

				//Draw traces

				SDL_Rect rect;
				rect.x = x*squareSize + margin_x;
				rect.y = y*squareSize + margin_y;
				rect.w = squareSize;
				rect.h = squareSize;

				Color c = trace_hue_function(sim->getTraceAt(y, x), minTrace, maxTrace);

				//Color c = Color(10*sim->getNumOfAntsAt(y, x), 0, 0);

				if (x == sim->getNest().x && y == sim->getNest().y) {
					c.R = 255;
					c.G = 0;
					c.B = 222;
				}
				if (x == sim->getFood().x && y == sim->getFood().y) {
					c.R = 0;
					c.G = 255;
					c.B = 0;
				}

				if (!sim->getBlockOpenAt(y, x)){
					c.R = 0;
					c.G = 0;
					c.B = 0;
				}

				SDL_FillRect( screenSurface, &rect, SDL_MapRGB( screenSurface->format, c.R, c.G, c.B ) );

				rect.x = x*squareSize + squareSize*(sim->world_w + 1) + margin_x;
				rect.y = y*squareSize + margin_y;
				rect.w = squareSize;
				rect.h = squareSize;

				int antnum = sim->getNumOfAntsAt(y, x);

				if (antnum != 0) {
					double r = 50 + char(205*( (antnum - minAnts ) / (maxAnts - minAnts) ));
					c = Color(r, r, r);
				} else {
					c = Color(0, 0, 0);
				}

				SDL_FillRect( screenSurface, &rect, SDL_MapRGB( screenSurface->format, c.R, c.G, c.B ) );
			}
		}

		SDL_UpdateWindowSurface( window );

		sim->update();
		SDL_Delay( 10 );

		std::cout << time_n << std::endl;
		time_n += 1;
	}

	//Destroy window
  SDL_DestroyWindow( window );

  //Quit SDL subsystems
  SDL_Quit();

	delete sim;

  return 0;
}
