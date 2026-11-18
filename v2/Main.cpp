#include <iostream>
#include <string>
#include "TextInput.h"
#include "BasicMazeGame.h"

int main()
{
    // Setup
    BasicMazeGame mazeGame;

    // Main Game Loop
    while (true) {
        std::cout << "Enter a number: ";
        int response = TextInput::GetIntFromUserInRange(1, 10);
        std::cout << "\n Your response was: " << std::to_string(response) << "\n";
        mazeGame.PrintRoomDescription();
    }

    return 0;
}