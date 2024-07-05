#include "Sdl.hpp"
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <iostream>

Sdl::Sdl(void)
{
	this->width = 1080;
	this->height = 720;
}

Sdl::Sdl(const Sdl &sdl)
{
	this->width = sdl.width;
	this->height = sdl.height;
}

Sdl::~Sdl(void)
{
	this->quit();
}

bool
Sdl::init(void)
{
	if (SDL_VideoInit(NULL) < 0)
	{
		std::cerr << SDL_GetError() << std::endl;
		return false;
	}

	this->window = SDL_CreateWindow("Maze",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			this->width,
			this->height,
			SDL_WINDOW_RESIZABLE);
	if (this->window == NULL)
	{
		std::cerr << SDL_GetError() << std::endl;
		this->quit();
		return false;
	}

	this->renderer = SDL_CreateRenderer(this->window,
			-1, // don't care of this
			SDL_RENDERER_ACCELERATED // for use of graphic card
			| SDL_RENDERER_PRESENTVSYNC // to use VSync (sync fps w/ screen refresh rate)
			);
	if (this->renderer == NULL)
	{
		std::cerr << SDL_GetError() << std::endl;
		this->quit();
		return false;
	}

	return true;
}

void
Sdl::quit(void)
{
	// Destruction du renderer et de la fenêtre :
	if (this->renderer != NULL)
	{
		SDL_DestroyRenderer(this->renderer);
		this->renderer = NULL;
	}
	if (this->window != NULL)
	{
		SDL_DestroyWindow(this->window);
		this->window = NULL;
	}
	SDL_Quit(); // On quitte la SDL
}

int
Sdl::set_color(u_char r, u_char g, u_char b, u_char a)
{
	return SDL_SetRenderDrawColor(this->renderer, r, g, b, a);
}

void
Sdl::render(void)
{
	SDL_RenderPresent(this->renderer);
}

int
Sdl::clear(void)
{
	return SDL_RenderClear(this->renderer);
}
int
Sdl::draw_point(int x, int y)
{
	return SDL_RenderDrawPoint(this->renderer, x, y);
}

int
Sdl::draw_line(int x0, int y0, int x1, int y1)
{
	return SDL_RenderDrawLine(this->renderer, x0, y0, x1, y1);
}

int
Sdl::draw_rect(int x, int y, int h, int w)
{
	SDL_Rect r;

	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;
	return SDL_RenderDrawRect(this->renderer, &r);
}

int
Sdl::draw_rect(const SDL_Rect &rect)
{
	return SDL_RenderDrawRect(this->renderer, &rect);
}

int
Sdl::fill_rect(int x, int y, int h, int w)
{
	SDL_Rect r;

	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;
	return SDL_RenderFillRect(this->renderer, &r);
}

int
Sdl::fill_rect(const SDL_Rect &rect)
{
	return SDL_RenderFillRect(this->renderer, &rect);
}
