#include "Maze.hpp"

int
main(void)
{
	Maze	maze{};

	if (!maze.run())
		return 1;
	return 0;
}
