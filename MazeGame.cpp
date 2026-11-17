#include "MazeGame.h"

#define VERSION 1

#if VERSION == 1

/* 
    This function is pretty complicated, considering that all it does is create a maze with two rooms.
    The real problem with this member funciton isn't its size but its inflexibility.
    Changing the layout means changing this member function, either by overriding it, which means reimplementing
    the whole thing, or by changing parts of it, which is error-prone and doesn't promote reuse.

    The creational patterns show how to make this design more flexible, not necessarily smaller.
    In particular, they will make it easy to change the classes that define the components of a maze.
*/

Maze* MazeGame::CreateMaze() {
    Maze* aMaze = new Maze;
    Room* r1 = new Room(1);
    Room* r2 = new Room(2);
    Door* theDoor = new Door(r1, r2);

    aMaze->AddRoom(r1);
    aMaze->AddRoom(r2);

    r1->SetSide(North, new Wall);
    r1->SetSide(East, theDoor);
    r1->SetSide(South, new Wall);
    r1->SetSide(West, new Wall);

    r2->SetSide(North, new Wall);
    r2->SetSide(East, new Wall);
    r2->SetSide(South, new Wall);
    r2->SetSide(West, theDoor);
};

#elif VERSION == 2
#else
#endif