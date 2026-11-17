#ifndef MAZEGAME
#define MAZEGAME

#include "Maze.h"

class MazeGame {
public:
    MazeGame(Maze maze);

private:
    Maze _maze;
};

#endif