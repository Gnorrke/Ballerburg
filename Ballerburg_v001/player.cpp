#include "player.h"
#include <iostream>

Player::Player(int player): player(player)
{


}
void Player::setTurn(){

    turn = true;
    std::cout << "Player" << player << std::endl;
}

void Player::resetTurn(){

    turn = false;

}

bool Player::getTurn(){

    return turn;

}

