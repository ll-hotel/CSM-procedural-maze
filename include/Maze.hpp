#ifndef MAZE_HPP
# define MAZE_HPP
# include "Sdl.hpp"

class Maze
{
public:
	Maze(void);
	Maze(const Maze &);
	~Maze(void);

	bool run(void);

private:
	Sdl sdl;
	bool running;

	void stop(void);
	void handle_events(void);
};

#endif
