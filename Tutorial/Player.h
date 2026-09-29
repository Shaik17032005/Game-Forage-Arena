#ifndef PLAYER_H
#define PLAYER_H

#include <string>

// This is our blueprint (Class) for a Player
class Player {
private:
    // Attributes (data) hidden from the outside world
    std::string name;
    int health;
    int attackPower;
    int score;
    int wins;
    int losses;

public:
    // Constructor 1: Used when creating a BRAND NEW player.
    Player(std::string playerName, int startingHealth, int startingAttack);

    // Constructor 2: Used when LOADING an existing player from a file.
    Player(std::string playerName, int hp, int attack, int savedScore, int savedWins, int savedLosses);

    // Functions (methods) that let the player do things or share information
    void displayInfo();
    
    // Getters: Safely get the value of private variables
    std::string getName();
    int getHealth();
    int getAttackPower();
    int getScore();
    int getWins();
    int getLosses();

    // Setters or actions
    void takeDamage(int damageAmount);
    void addWin();
    void addLoss();
};

#endif // PLAYER_H
