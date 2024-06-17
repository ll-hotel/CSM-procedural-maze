#include "app.h"

void	app_cleanup(t_app *app)
{
	if (app->renderer)
	{
		SDL_DestroyRenderer(app->renderer);
		app->renderer = NULL;
	}
	if (app->window)
	{
		SDL_DestroyWindow(app->window);
		app->window = NULL;
	}
	SDL_Quit();
}
