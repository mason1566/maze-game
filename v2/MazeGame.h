#ifndef MAZEGAME
#define MAZEGAME

#include "Direction.h"
#include "Maze.h"

class MazeGame {
public:
    virtual Maze* CreateMaze() = 0;
    virtual void Move(Direction) = 0;
    virtual void PrintRoomDescription() = 0;
protected:
    Room* _currentRoom;
    Maze* _maze;
};

#endif