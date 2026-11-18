#ifndef MAZE
#define MAZE

#include "MapSite.h"
#include <vector>

class Maze {
public:
    Maze() {};

    void AddRoom(Room* room) { _rooms.push_back(room); }
    // Room* RoomNo(int) const;
private:
    std::vector<Room*> _rooms {};
};

#endif