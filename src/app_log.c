#include <SDL2/SDL.h>
#include <stdio.h>

int	app_log(const char *s)
{
	return (dprintf(2, "%s: %s\n", s, SDL_GetError()));
}
