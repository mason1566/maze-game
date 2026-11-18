#ifndef MAPSITE
#define MAPSITE

#include <string>
#include "Direction.h"

class MapSite {
public:
    virtual void Enter() = 0;
    std::string GetDescription() { return this->_description; }
protected:
    std::string _description = "";
};

class Room : public MapSite {
public:
    Room(int roomNo);

    void SetSide(Direction, MapSite*);
    MapSite* GetSide(Direction) const;

    virtual void Enter();

private:
    MapSite* _sides[4];
    int _roomNumber;
};

class Wall : public MapSite {
public:
    Wall();

    virtual void Enter();
};

class Door : public MapSite {
public:
    Door(Room* = 0, Room* = 0);

    virtual void Enter();

private:
    Room* _room1;
    Room* _room2;
    bool _isOpen;
};

#endif