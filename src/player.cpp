#include "player.h"

Player :: Player(std::string name_, float starting_stack){
    name = name_;
    coin = starting_stack;
}

 void Player :: set_coin(float coin_){
    coin = coin_;
}

std::string Player :: get_name(){
    return name;
}

float Player :: get_coin(){
    return coin;
}