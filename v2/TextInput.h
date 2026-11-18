#ifndef TEXTINPUT
#define TEXTINPUT

    #include <iostream>
    #include <string>
    #include <limits>

class TextInput {
public:
    // Returns a valid integer parsed from the user.
    static int GetIntFromUser();

    // Returns a valid integer in range parsed from the user. Expects minimum and maximum range values.
    static int GetIntFromUserInRange(int min, int max);
private:
    // Clears stream buffer
    static void IgnoreLine();

    // returns true if extraction failed, false otherwise
    static bool ClearFailedExtraction();
};

#endif