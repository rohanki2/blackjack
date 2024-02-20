#include <iostream>
#include <string>
#include "card.h"


    Card::Card (int rank_, std::string suit_){
    rank = rank_;
    suit = suit_;
}


    int Card::get_rank(){
    if (rank > 10){
        return 10;
    }
    else{
        return rank;
    }
};

void Card::print_flipped(){

        std::cout << " _______ \n";
        std::cout << "|_______|\n";
        std::cout << "|_______|\n";
        std::cout << "|_______|\n";
        std::cout << "|_______|\n";

}

std::string Card::rankToString(){

    if (rank > 1 && rank < 10){
        return std::to_string(rank);
    }
    else if (rank == 1){
        return "A";
    }

    else if (rank == 10){
        return "T";
    }

    else if (rank == 11){
        return "J";
    }

    else if (rank == 12){
        return "Q";
    }

    else{
        return "K";
    }


}

std::string Card :: get_suit(){
    if (suit == "spades"){
        return "s";
    }
    else if (suit == "clubs"){
        return "c";
    }

    else if (suit == "hearts"){
        return "h";
    }

    else{
        return "d";
    }
}

        



