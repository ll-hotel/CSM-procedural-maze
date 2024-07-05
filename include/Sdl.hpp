#ifndef MAZE_SDL_H
# define MAZE_SDL_H
# include <SDL2/SDL.h>
#include <sys/types.h>

class Sdl
{
public:
	Sdl(void);
	Sdl(const Sdl &);
	~Sdl(void);

	bool init(void);
	void quit(void);

	int set_color(u_char r, u_char g, u_char b, u_char a);
	int draw_point(int x, int y);
	int draw_line(int x0, int y0, int x1, int y1);
	int draw_rect(int x, int y, int h, int w);
	int draw_rect(const SDL_Rect &rect);
	int fill_rect(int x, int y, int h, int w);
	int fill_rect(const SDL_Rect &rect);

	void render(void);
	int clear(void);
private:
	SDL_Window *window;
	SDL_Renderer *renderer;
	int height;
	int width;
};

#endif
