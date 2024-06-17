#include "app.h"

void	app_render(t_app *app)
{
	SDL_RenderClear(app->renderer);
	SDL_RenderPresent(app->renderer);
}
