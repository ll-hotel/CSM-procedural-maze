#include "app.h"
#include <string.h>

int	main(void)
{
	t_app	app;

	memset(&app, 0, sizeof(app));
	app.window_width = 1080;
	app.window_height = 720;
	app_execute(&app);
	app_cleanup(&app);
	return (0);
}
