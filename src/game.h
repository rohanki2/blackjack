#pragma once
#include "card.h"
#include "deck.h"
#include "player.h"

class Game {
    public:
        Game (std::vector<Player> players_, int decks_);
        void print_hand(std::vector<Card> hand, int dealer, Player p, int bet);
        void set_hand(std::vector<Card> hand, std::string name);
        void play_game();
        void deal_hands();
        int sum(std::vector<Card> hand);
        void print_all();

    private:
        std::vector<Player> players;
        Deck deck;
        std::vector<float> bets;
        std::vector<std::vector<Card> > hands;
        std::vector<Card> dealer;

};