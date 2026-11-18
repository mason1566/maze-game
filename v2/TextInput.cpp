#include "TextInput.h"

// Clears stream buffer
void TextInput::IgnoreLine() // From here: https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
}

// returns true if extraction failed, false otherwise
bool TextInput::ClearFailedExtraction() // From here: https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/
{
    // Check for failed extraction
    if (!std::cin) // If the previous extraction failed
    {
        if (std::cin.eof()) // If the stream was closed
        {
            std::exit(0); // Shut down the program now
        }

        std::cin.clear(); // Put us back in 'normal' operation mode
        TextInput::IgnoreLine();     // And remove the bad input

        return true;
    }

    return false;
}

// Returns a valid integer parsed from the user.
int TextInput::GetIntFromUser() {
    while (true) {
        int userInput{};
        std::cin >> userInput;

        if (TextInput::ClearFailedExtraction()) {
            std::cout << "Invalid input. Input must be a valid int. Please try again.\n";
            continue;
        }

        TextInput::IgnoreLine();
        return userInput;
    }
}

// Returns a valid integer in range parsed from the user. Expects minimum and maximum range values.
int TextInput::GetIntFromUserInRange(int min, int max) {
    while (true) {
        int userInt = TextInput::GetIntFromUser();
        if (userInt < min || userInt > max) {
            std::cout << "Invalid input. Range is [" << min << " to " << max << "]. Please try again\n";
            continue;
        }
        return userInt;
    }
}