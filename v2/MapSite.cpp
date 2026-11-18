#include "MapSite.h"

// ROOM
Room::Room(int roomNo) {
    this->_roomNumber = roomNo;
    this->_description = "Room";
};

void Room::SetSide(Direction direction, MapSite* mapSite) {
    this->_sides[static_cast<int>(direction)] = mapSite;
};

MapSite* Room::GetSide(Direction direction) const {
    return this->_sides[static_cast<int>(direction)];
}

void Room::Enter() {
    return;
}

// WALL
Wall::Wall() {
    this->_description = "Wall";
}

void Wall::Enter() {
    return;
}

// DOOR
Door::Door(Room* r1, Room* r2) {
    this->_description = "Door";
    this->_room1 = r1;
    this->_room2 = r2;
    this->_isOpen = true;
}

void Door::Enter() {
    return;
}