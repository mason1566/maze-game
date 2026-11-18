#ifndef BASICMAZEGAME
#define BASICMAZEGAME

#include "MazeGame.h"
#include <iostream>

class BasicMazeGame : public MazeGame {
public:
    Maze* CreateMaze() override;
    void Move(Direction direction) override;
    void PrintRoomDescription() override;
};

#endif