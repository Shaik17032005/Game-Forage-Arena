#ifndef GAME_H
#define GAME_H

#include "Player.h"

class Game {
public:
    // This function takes two players and starts a battle.
    // We use '&' (references) so we modify the ORIGINAL players, not copies.
    static void startBattle(Player& p1, Player& p2);
};

#endif // GAME_H
