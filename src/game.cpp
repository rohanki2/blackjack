#include "game.h"


Game::Game(std::vector<Player> players_, int decks_) : deck(decks_){
        players = players_;
        bets.assign(players.size(), 0.0);
        

}

void Game :: print_hand(std::vector<Card> hand, int dealer, Player p, int bet){
    
     for (int i = 0; i < hand.size(); i++){
        std::cout << " ______   ";
        
    }

    std::cout << std::endl;
    for (int j = 0; j < 4; j++){

    for (int i = 0; i < hand.size(); i++){

        if (dealer == 1 && i == 0){
            std::cout << "|______|  ";
        }

        else if (j == 2){
            std::cout << "|  " << hand[i].rankToString() << hand[i].get_suit() <<  "  |  ";
        }

        else{
        std::cout << "|      |  ";
        }

        if (i == hand.size() - 1 && j == 2){
            if (dealer == 1){
            std::cout << "Dealer";
            }
            else{
                std::cout << p.get_name() << " " << p.get_coin();
            }
        }
        else if (i == hand.size() - 1 && dealer == 0 && j == 0){
            std::cout << "Wager: " << bets[bet];
        }
    }

     std::cout << std::endl;
    }

   for (int i = 0; i < hand.size(); i++){
        std::cout << "|______|  ";
    }

    std:: cout << sum(hand);

    std::cout << std::endl;

}

void Game :: set_hand(std::vector<Card> hand, std::string name){

    int i;
    for (i = 0; i < players.size(); i++){
        if (players[i].get_name() == name){
            break;
        }
    }

    hands[i] = hand;
}

void Game :: deal_hands(){
    for (int i = 0; i < players.size(); i++){
        std::vector<Card> h;
        h.push_back(deck.deal_card());
        h.push_back(deck.deal_card());
        hands.push_back(h);
    }

    dealer.push_back(deck.deal_card());
    dealer.push_back(deck.deal_card());

}

int Game :: sum(std::vector<Card> hand){
    int sum = 0;
    for (int i = 0; i < hand.size(); i++){
        sum = sum + hand[i].get_rank();
    }

    return sum;
}

void Game :: print_all(){
    print_hand(dealer, 1, players[0], 0);

    for (int i = 0; i < hands.size(); i++){
        print_hand(hands[i], 0, players[i], i);
    }
}


void Game :: play_game(){



    for (int i = 0; i < players.size(); i++){
        std::cout << players[i].get_name() << ", how much will you wager?" << std::endl;
        std::cin >> bets[i];
        players[i].set_coin(players[i].get_coin() - bets[i]);
    }

    deal_hands();

    print_all();

    int choice;

    for (int i = 0; i < hands.size(); i++){
        std::cout << players[i].get_name() << ", what would you like to do?  (0 - stand, 1 - hit, 2 - double down, 3 - split)" << std::endl;
        std::cin >> choice;

        if (choice == 1){
            int c = 5;
            while (c != 0){
                hands[i].push_back(deck.deal_card());
                print_all();

            if (sum(hands[i]) > 21){
                break;
            }
                std::cout << players[i].get_name() << ", what would you like to do?  (0 - stand, 1 - hit, 2 - double down)" << std::endl;
                std::cin >> c;
            }
            
                
            }
        
        if (choice == 2){
            bets[i] = bets[i] * 2;
        }

        else if (choice == 3){
            if (hands[i][0].get_rank() == hands[i][1].get_rank()){
                std::vector<Card> n;
                n.push_back(hands[i][1]);
                hands.insert(hands.begin() + i, n);
                players.insert(players.begin() + i, players[i]);
            }
        }
    }

    



}
