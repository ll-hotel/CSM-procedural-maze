#include "app.hpp"
#include <SDL2/SDL_error.h>
#include <iostream>

App::App(void) {
	window_width = 1080;
	window_height = 720;
}

App::App(const App &app) {
	window_width = app.window_width;
	window_height = app.window_height;
}

App::~App(void) {
	cleanup();
}

int
App::init(void) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		log("Unable to init video subsystem");
		return 0;
	}
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	window = SDL_CreateWindow("A Maze-ing", \
				SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, \
				window_width, window_height, \
				SDL_WINDOW_SHOWN);
	if (window == NULL) {
		log("Unable to create window");
		return 0;
	}
	// This is commented because association of a surface AND a renderer on a window is prohibited
	/*
	surface = SDL_GetWindowSurface(window);
	if (surface == NULL)
	{
		app_log("Unable to get window surface");
		return 0;
	}
	*/
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {
		log("Unable to create renderer");
		return 0;
	}
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
	return 1;
}

int
App::execute(void) {
	SDL_Event	event;

	if (!init())
		return 0;
	running = 1;
	while (running) {
		while (SDL_PollEvent(&event) != 0) {
			on_event(event);
			if (event.type == SDL_QUIT)
				running = 0;
		}
		loop();
		render();
		SDL_Delay(1); //Breath
	}
	cleanup();
	return 1;
}

void
App::on_event(const SDL_Event &event) {
	(void)event;
}

void
App::loop(void) {
	;
}

void
App::render(void) {
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

int
App::log(std::string s) {
	std::cerr << s << ": " << SDL_GetError() << std::endl;
	return (1);
}

void
App::cleanup(void) {
	if (renderer) {
		SDL_DestroyRenderer(renderer);
		renderer = NULL;
	}
	if (window) {
		SDL_DestroyWindow(window);
		window = NULL;
	}
	SDL_Quit();
}
