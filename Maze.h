#ifndef MAZE
#define MAZE

#include "MapSite.h"

class Maze {
public:
    Maze();

    void AddRoom(Room*);
    Room* RoomNo(int) const;
private:
    // ...
};

#endif