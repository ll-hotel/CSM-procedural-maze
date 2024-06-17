#include "app.h"

int	app_init(t_app *app)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (app_log("Unable to init video subsystem"), 0);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	app->window = SDL_CreateWindow("A Maze-ing", \
				SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, \
				app->window_width, app->window_height, \
				SDL_WINDOW_SHOWN);
	if (app->window == NULL)
	{
		app_log("Unable to create window");
		return 0;
	}
	// This is commented because association of a surface AND a renderer on a window is prohibited
	/*
	app->surface = SDL_GetWindowSurface(app->window);
	if (app->surface == NULL)
	{
		app_log("Unable to get window surface");
		return 0;
	}
	*/
	app->renderer = SDL_CreateRenderer(app->window, -1, SDL_RENDERER_ACCELERATED);
	if (app->renderer == NULL)
	{
		app_log("Unable to create renderer");
		return 0;
	}
	SDL_SetRenderDrawColor(app->renderer, 0x00, 0x00, 0x00, 0xFF);
	return 1;
}
