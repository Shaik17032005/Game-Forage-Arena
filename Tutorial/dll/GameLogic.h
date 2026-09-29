#ifndef GAMELOGIC_H
#define GAMELOGIC_H

// This macro helps Windows understand if we are exporting (building the DLL)
// or importing (using the DLL).
#ifdef BUILD_MY_DLL
    #define EXPORT_API __declspec(dllexport)
#else
    #define EXPORT_API __declspec(dllimport)
#endif

// We use 'extern "C"' to stop C++ from "mangling" (renaming) our function behind the scenes.
// This makes it easy for other languages (like Java or Python) to find the function later!
extern "C" {
    
    // A simple exported function that calculates match damage
    EXPORT_API int calculateDamage(int attackPower, int defense);

}

#endif // GAMELOGIC_H
