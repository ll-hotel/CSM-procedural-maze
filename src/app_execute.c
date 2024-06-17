#include "app.h"

int	app_execute(t_app *app)
{
	SDL_Event	event;

	if (!app_init(app))
		return 0;
	app->running = 1;
	while (app->running)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			app_on_event(&event);
			if (event.type == SDL_QUIT)
				app->running = 0;
		}
		app_loop(app);
		app_render(app);
		SDL_Delay(1); //Breath
	}
	app_cleanup(app);
	return 1;
}
