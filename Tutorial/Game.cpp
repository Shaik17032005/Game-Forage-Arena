#include "Game.h"
#include <iostream>

void Game::startBattle(Player& p1, Player& p2) {
    std::cout << "\n--- BATTLE START ---" << std::endl;
    std::cout << p1.getName() << " VS " << p2.getName() << std::endl;

    // Loop until one player's health reaches 0
    while (p1.getHealth() > 0 && p2.getHealth() > 0) {
        // Player 1 attacks Player 2
        int damage1 = p1.getAttackPower();
        p2.takeDamage(damage1);
        std::cout << p1.getName() << " attacks " << p2.getName() << "! ";
        std::cout << p2.getName() << " loses " << damage1 << " HP." << std::endl;

        // Check if Player 2 died
        if (p2.getHealth() == 0) {
            std::cout << "\nWinner: " << p1.getName() << "!" << std::endl;
            p1.addWin();
            p2.addLoss();
            break; // Stop the battle
        }

        // Player 2 attacks Player 1
        int damage2 = p2.getAttackPower();
        p1.takeDamage(damage2);
        std::cout << p2.getName() << " attacks " << p1.getName() << "! ";
        std::cout << p1.getName() << " loses " << damage2 << " HP." << std::endl;

        // Check if Player 1 died
        if (p1.getHealth() == 0) {
            std::cout << "\nWinner: " << p2.getName() << "!" << std::endl;
            p2.addWin();
            p1.addLoss();
            break; // Stop the battle
        }
    }
}
