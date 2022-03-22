#include "player.h"
#include <sstream>
#include <string>
#include <string.h>
#include <unistd.h>
#include <iostream>
using namespace std;
int Player::getLose() const
{
    return lose;
}

void Player::setLose(int newLose)
{
    lose = newLose;
}

int Player::getDraw() const
{
    return draw;
}

void Player::setDraw(int newDraw)
{
    draw = newDraw;
}

Player::Player()
{
    lose=0;
    draw=0;
    win=0;

}

std::string Player::getName()
{
    return this->name;
}

int Player::getWin()
{
    return this->win;
}
void Player::setName(std::string name)
{
    this->name = name;
}
void Player::setWin(int win)
{
    this->win = win;
}
