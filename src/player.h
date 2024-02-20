#pragma once
#include <string>

class Player {

    public:
        Player(std::string name, float starting_stack);
        void set_coin(float coin_);
        std::string get_name();
        float get_coin();

    private:
        std::string name;
        float coin;

};