
#include <iostream>

#include <tiki/config.h>
#include <tiki/version.h>

#define SDL_MAIN_HANDLED
#include <SDL.h>

int main(char* args, int argc)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		return 1;

	SDL_Window* sdlWindow = SDL_CreateWindow("Tiki Hunt",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		800,
		600,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE );

	if (sdlWindow == nullptr)
		return 1;

	SDL_Delay(5000);
	SDL_Quit();
	return 0;
}

