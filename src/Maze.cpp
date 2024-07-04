#include "Maze.hpp"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_video.h>

Maze::Maze(void)
{
}

Maze::Maze(const Maze &)
{
}

Maze::~Maze(void)
{
}

bool
Maze::run(void)
{

	if (this->sdl.init() == false)
		return false;
	this->running = true;

	while (this->running)
	{
		this->sdl.render();
		SDL_Delay(10); // 100 fps (10ms = 1s/100)

		this->handle_events();
	}

	this->stop();
	return true;
}

void
Maze::handle_events(void)
{
	SDL_Event event{};

	while (SDL_PollEvent(&event) == 1)
	{
		if (event.type == SDL_QUIT)
		{
			this->running = false;
			break ;
		}
		else if (event.type == SDL_WINDOWEVENT)
		{
			if (event.window.event == SDL_WINDOWEVENT_CLOSE)
			{
				this->running = false;
				break ;
			}
		}
	}
}

void
Maze::stop(void)
{
	this->sdl.quit();
}