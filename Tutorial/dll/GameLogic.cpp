// We define this so our header knows to use dllexport
#define BUILD_MY_DLL 

#include "GameLogic.h"

extern "C" {

    // The actual implementation of our exported function
    EXPORT_API int calculateDamage(int attackPower, int defense) {
        // Simple logic: Attack minus defense. If defense is higher, damage is 0 (not negative)
        int damage = attackPower - defense;
        
        if (damage < 0) {
            return 0;
        }
        return damage;
    }

}
