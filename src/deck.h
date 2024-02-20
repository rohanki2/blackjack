#pragma once
#include <vector>
#include "card.h"




class Deck{
    public:
        Deck();
        Deck(int size);
        std::vector<Card> get_deck();
        Card deal_card();




    private:
        std::vector<Card> deck;
};