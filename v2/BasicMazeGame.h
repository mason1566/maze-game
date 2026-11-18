#ifndef BASICMAZEGAME
#define BASICMAZEGAME

#include "MazeGame.h"
#include "Direction.h"
#include "Maze.h"
#include <iostream>

class BasicMazeGame : public MazeGame {
public:
    BasicMazeGame();
    Maze* CreateMaze() override;
    void Move(Direction direction) override;
    void PrintRoomDescription() override;
};

#endif