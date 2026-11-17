#ifndef MAZEGAME
#define MAZEGAME

#include "Maze.h"

#define VERSION 2

#if VERSION == 1

/* HARDCODED MAZE
    This function is pretty complicated, considering that all it does is create a maze with two rooms.
    The real problem with this member funciton isn't its size but its inflexibility.
    Changing the layout means changing this member function, either by overriding it, which means reimplementing
    the whole thing, or by changing parts of it, which is error-prone and doesn't promote reuse.

    The creational patterns show how to make this design more flexible, not necessarily smaller.
    In particular, they will make it easy to change the classes that define the components of a maze.
*/

class MazeGame {
public:
    MazeGame();

    Maze* CreateMaze();

private:
    Maze* _maze;
};

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

/* FACTORY METHOD
    If CreateMaze calls virtual functions instead of constructor calls to create the rooms, walls,and doors 
    it requires, then you can change the classes that get instantiated by making a subclass of MazeGame and
    redefining those virtual functions. This approach is an example of the Factory Method pattern.
*/

class MazeGame {
public:
    Maze* CreateMaze();

// factory methods:

    virtual Maze* MakeMaze() const { return new Maze; };
    virtual Room* MakeRoom(int n) const { return new Room(n); };
    virtual Wall* MakeWall() const { return new Wall; };
    virtual Door* MakeDoor(Room* r1, Room* r2) const { return new Door(r1, r2); };
};

/* Now we can rewrite CreateMaze to use these factory methods: */
Maze* MazeGame::CreateMaze() {
    Maze* aMaze = MakeMaze();
    
    Room* r1 = MakeRoom(1);
    Room* r2 = MakeRoom(2);
    Door* theDoor = MakeDoor(r1, r2);

    aMaze->AddRoom(r1);
    aMaze->AddRoom(r2);

    r1->SetSide(North, MakeWall());
    r1->SetSide(East, theDoor);
    r1->SetSide(South, MakeWall());
    r1->SetSide(West, MakeWall());

    r2->SetSide(North, MakeWall());
    r2->SetSide(East, MakeWall());
    r2->SetSide(South, MakeWall());
    r2->SetSide(West, theDoor);

    return aMaze;
};

/*
    Different games can subclass MazeGame to specialize parts of the maze. MazeGame subclasses can redefine some
    or all of the factory methods to specify variations in products.
*/

class BombedWall : public Wall {
public:
    BombedWall();

    virtual void Enter();
};

class RoomWithABomb : public Room {
public:
    RoomWithABomb(int roomNo);

    virtual void Enter();
};

// BombedMazeGame can redefine the Room and Wall products to return the bombed varieties:
class BombedMazeGame : public MazeGame {
public:
    BombedMazeGame();

    virtual Wall* MakeWall() const { return new BombedWall; };
    virtual Room* MakeRoom(int n) const { return new RoomWithABomb(n); };
};

/* An EnchantedMazeGame variant might be defined like this:
    class EnchantedMazeGame : public MazeGame {
    public:
        EnchantedMazeGame();

        virtual Room* MakeRoom(int n) const { return new EnchantedRoom(n, CastSpell()); }
        virtual Door* MakeDoor(Room* r1, Room* r2) const { return new DoorNeedingSpell(r1, r2); }
    protected:
        Spell* CastSpell() const;
    }
*/

#elif VERSION == 3

/* ABSTRACT FACTORY
    If CreateMaze is passed an object as a parameter to use to create rooms, walls, and doors, then you can
    change the classes of rooms, walls, and doors by passing a different parameter. This is an example of the
    Abstract Factory pattern.
*/


#elif VERSION == 4

/* BUILDER
    If CreateMaze is passed an object that can create a new maze in its entirety using operations for adding
    rooms, doors, and walls to the maze it builds, then you can use inheritance to change parts of the maze
    or the way the maze is built. This is an example of the Builder pattern.
*/


#elif VERSION == 5

/* PROTOTYPE
    if CrateMaze is parameterized by various prototypical room, door, and wall objects, which it then copies and
    adds to the maze, then you can change the maze's composition by replacing these prototypical objects with
    different ones. This is an example of the Prototype pattern.
*/

#elif VERSION == 6

/*SINGLETON
    The remaining creational pattern, Singleton, can ensure there's only one maze per game and that all game
    objects have ready access to it, without resorting to global variables or functions. Singleton also makes it
    easy to extend or replace the maze without touching existing code.
*/

#else
#endif

#endif