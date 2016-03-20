#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "antsim.h"
#include <SDL2/SDL.h>
#include <stdio.h>

int graphics_init(Simulation* sim);

struct Color {
	char R;
	char G;
	char B;

	Color() : R(0), G(0), B(0) {}
	Color(char _R, char _G, char _B) : R(_R), G(_G), B(_B) {}
};
typedef struct Color Color;

#endif
