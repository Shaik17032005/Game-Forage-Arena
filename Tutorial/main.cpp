#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Needed for std::sort
#include <fstream>   // Needed for file reading/writing (ifstream, ofstream)
#include "Player.h"
#include "Game.h"

// A custom rule for sorting: we want the player with the higher score to go first
bool comparePlayers(Player& p1, Player& p2) {
    return p1.getScore() > p2.getScore();
}

int main() {
    // A vector is a dynamic list that can grow or shrink
    std::vector<Player> playersList;
    bool gameRunning = true;

    while (gameRunning) {
        std::cout << "\n=== GAMEFORGE ARENA - MAIN MENU ===" << std::endl;
        std::cout << "1. Create Player" << std::endl;
        std::cout << "2. View Players" << std::endl;
        std::cout << "3. Start Match" << std::endl;
        std::cout << "4. View Leaderboard (Coming Soon)" << std::endl;
        std::cout << "5. Save Players (Coming Soon)" << std::endl;
        std::cout << "6. Load Players (Coming Soon)" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Choose an option: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name;
                int hp, attack;
                std::cout << "Enter Player Name: ";
                std::cin >> name;
                std::cout << "Enter Health: ";
                std::cin >> hp;
                std::cout << "Enter Attack Power: ";
                std::cin >> attack;

                // Create player and add to our list (vector)
                Player newPlayer(name, hp, attack);
                playersList.push_back(newPlayer);
                std::cout << "Player created successfully!" << std::endl;
                break;
            }
            case 2: {
                std::cout << "\n--- ALL PLAYERS ---" << std::endl;
                for (int i = 0; i < playersList.size(); i++) {
                    // We use playersList[i] to get the player at index 'i'
                    playersList[i].displayInfo();
                }
                break;
            }
            case 3: {
                if (playersList.size() < 2) {
                    std::cout << "Not enough players to start a match! Create at least 2." << std::endl;
                    break;
                }
                // For simplicity, we just grab the first two players in the list
                std::cout << "Starting match between " << playersList[0].getName() 
                          << " and " << playersList[1].getName() << "!" << std::endl;
                Game::startBattle(playersList[0], playersList[1]);
                break;
            }
            case 4: {
                std::cout << "\n--- LEADERBOARD ---" << std::endl;
                
                // 1. Make a copy of our list so we don't accidentally mess up the original order
                std::vector<Player> sortedPlayers = playersList;

                // 2. Sort the copy using our custom comparePlayers rule
                std::sort(sortedPlayers.begin(), sortedPlayers.end(), comparePlayers);

                // 3. Print the top bar
                std::cout << "Rank | Player | Score | Wins | Losses" << std::endl;
                std::cout << "---------------------------------------" << std::endl;

                // 4. Print each player
                for (int i = 0; i < sortedPlayers.size(); i++) {
                    std::cout << (i + 1) << "    | " 
                              << sortedPlayers[i].getName() << " | "
                              << sortedPlayers[i].getScore() << "   | "
                              << sortedPlayers[i].getWins() << "    | "
                              << sortedPlayers[i].getLosses() << std::endl;
                }
                break;
            }
            case 5: {
                // ofstream = Output File Stream (Used to WRITE to a file)
                std::ofstream outFile("players.txt");
                
                if (outFile.is_open()) {
                    for (int i = 0; i < playersList.size(); i++) {
                        // Write player data separated by spaces
                        outFile << playersList[i].getName() << " "
                                << playersList[i].getHealth() << " "
                                << playersList[i].getAttackPower() << " "
                                << playersList[i].getScore() << " "
                                << playersList[i].getWins() << " "
                                << playersList[i].getLosses() << "\n";
                    }
                    outFile.close(); // ALWAYS close the file when done
                    std::cout << "Players saved successfully to players.txt!" << std::endl;
                } else {
                    std::cout << "Error: Could not open file to save." << std::endl;
                }
                break;
            }
            case 6: {
                // ifstream = Input File Stream (Used to READ from a file)
                std::ifstream inFile("players.txt");
                
                if (inFile.is_open()) {
                    playersList.clear(); // Empty our current list before loading
                    
                    std::string name;
                    int hp, attack, score, wins, losses;

                    // Read until the end of the file
                    while (inFile >> name >> hp >> attack >> score >> wins >> losses) {
                        // Use our new Constructor 2 to restore their exact stats!
                        Player loadedPlayer(name, hp, attack, score, wins, losses);
                        playersList.push_back(loadedPlayer);
                    }
                    inFile.close();
                    std::cout << "Players loaded successfully from players.txt!" << std::endl;
                } else {
                    std::cout << "Error: Could not open players.txt. Maybe it doesn't exist yet?" << std::endl;
                }
                break;
            }
            case 7:
                std::cout << "Thanks for playing GameForge Arena!" << std::endl;
                gameRunning = false; // This stops the while loop
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }

    return 0;
}
