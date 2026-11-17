#ifndef MAZEGAME
#define MAZEGAME

#include "Maze.h"

class MazeGame {
public:
    MazeGame();

    Maze* CreateMaze();

private:
    Maze* _maze;
};

#endif