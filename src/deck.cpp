#include "deck.h"
#include <ctime>

Deck::Deck(){

}

 Deck::Deck(int size){
    std::string suits[] = {"spades", "hearts", "clubs", "diamonds"};
    

    for (int k = 0; k < size; k++){
        for (int i = 0; i < 4; i++){
            for (int j = 1; j < 14; j++){
                Card newCard (j, suits[i]);
                deck.push_back(newCard);
            }
        }
 }

 }

 Card Deck::deal_card(){

    srand(time(0));
    int d = rand() % (deck.size() - 1);

    Card draw = deck[d];

    deck.erase(deck.begin() + d);

    return draw;

 }

 std::vector<Card> Deck::get_deck(){
    return deck;
 }

