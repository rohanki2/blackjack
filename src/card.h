#pragma once
#include <iostream>
#include <string>

class Card{

    public:

        Card (int rank_, std::string suit_);
        int get_rank();
        void print_flipped();
        std::string rankToString();
        std::string get_suit();




    private:
        int rank;
        std::string suit;


};