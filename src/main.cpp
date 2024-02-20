#include "game.h"
#include <iostream>
#include <vector>


int main(){
    

    int players;
    std::cout << "Welcome to BlackJack!" << std::endl;
    std::cout << "Enter Number of Players. (Max 5)" << std::endl;
    std::cin >> players;

    while (players < 1 || players > 5){
        if (players < 1){
            std::cout << "Error: At least 1 player is needed to start the game." << std::endl;
        }

        else if (players > 5){
            std::cout << "Error: Too many Players." << std::endl;
        }

        std::cout << "Enter Number of Players. (Max 5)" << std::endl;

        std::cin >> players;
    }
    std::vector<std::string> p;
    p.assign(players, "Default"); 

    int num = 0;

std::cout << "Enter Player Names." << std::endl;
    while (num < p.size()){
        std::cin >> p[num];
        
        num++;
    }

int decks;
    std::cout << "Enter Number of Decks to be used. (Max 8)" << std::endl;
    std::cin >> decks;

    while (decks < 1 || decks > 8){
        if (decks < 1){
            std::cout << "Error: At least 1 deck is needed to start the game." << std::endl;
        }

        else if (decks > 8){
            std::cout << "Error: Too many decks." << std::endl;
        }

        std::cout << "Enter Number of Decks to be used. (Max 8)" << std::endl;

        std::cin >> decks;
    }

    std::vector<float> stacks;
    stacks.assign(players, 0.0);
    std::vector<Player> table;

    for (int i = 0; i < players; i++){
        std::cout << "How much will " << p[i] << " start with?" << std::endl;
        std::cin >> stacks[i];
        Player n (p[i], stacks[i]);
        table.push_back(n);
    }

Game game (table, decks);

game.play_game();











   

}