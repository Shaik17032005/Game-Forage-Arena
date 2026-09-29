#include "Player.h"
#include <iostream>

// 1. The Constructors
// This sets up a BRAND NEW player
Player::Player(std::string playerName, int startingHealth, int startingAttack) {
    name = playerName;
    health = startingHealth;
    attackPower = startingAttack;
    score = 0;   // Everyone starts with 0 score
    wins = 0;    // Everyone starts with 0 wins
    losses = 0;  // Everyone starts with 0 losses
}

// This sets up a LOADED player
Player::Player(std::string playerName, int hp, int attack, int savedScore, int savedWins, int savedLosses) {
    name = playerName;
    health = hp;
    attackPower = attack;
    score = savedScore;
    wins = savedWins;
    losses = savedLosses;
}

// 2. Display Information Function
// This prints the player's stats to the screen nicely formatted.
void Player::displayInfo() {
    std::cout << "Player: " << name << std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Attack: " << attackPower << std::endl;
    std::cout << "Score: " << score << std::endl;
    std::cout << "Wins: " << wins << std::endl;
    std::cout << "Losses: " << losses << std::endl;
    std::cout << "-----------------------" << std::endl;
}

// 3. Simple Getters
std::string Player::getName() {
    return name;
}

int Player::getHealth() {
    return health;
}

int Player::getAttackPower() {
    return attackPower;
}

int Player::getScore() {
    return score;
}

int Player::getWins() {
    return wins;
}

int Player::getLosses() {
    return losses;
}

// 4. Action Functions
void Player::takeDamage(int damageAmount) {
    health = health - damageAmount;
    if (health < 0) {
        health = 0; // Health can't go below zero
    }
}

void Player::addWin() {
    wins = wins + 1;
    score = score + 50; // Earn 50 points for a win!
}

void Player::addLoss() {
    losses = losses + 1;
}
