#include <iostream>
#include "SDL.h"
#include "SDL_opengl.h"

int main(int argc, char ** argv)
{
	printf("Testing SDL...!\n");

	SDL_Init(SDL_INIT_VIDEO);

	// Try to create window
	SDL_Window *window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
	if (!window)
	{
		fprintf(stderr, "Cannot create window: %s\n", SDL_GetError());
		return 1;
	}

	// Setup renderer
	SDL_Renderer* renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	// Bckg color
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderClear(renderer);

	// Creat a rect at pos ( 120, 100 ) that's 80 pixels wide and 80 pixels high.
	SDL_Rect rect = { 120, 100, 80, 80 };

	// Square color
	SDL_SetRenderDrawColor(renderer, 255, 128, 0, 255);

	// Now render
	SDL_RenderFillRect(renderer, &rect);
	SDL_RenderPresent(renderer);

	//Clean up
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}