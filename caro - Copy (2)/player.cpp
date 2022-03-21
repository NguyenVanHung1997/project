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
    name = "";
    win = 0;
    total = 0;
    mark = 0;
    type = LocalPlayer;
    int socket = 0;
}

std::string Player::getName()
{
    return this->name;
}

int Player::getWin()
{
    return this->win;
}

int Player::getTotal()
{
    return this->total;
}

int Player::getMark()
{
    return this->mark;
}

PlayerType Player::getType()
{
    return this->type;
}

int Player::getSock()
{
    return this->socket;
}

void Player::setName(std::string name)
{
    this->name = name;
}

void Player::setWin(int win)
{
    this->win = win;
}

void Player::setTotal(int total)
{
    this->total = total;
}

void Player::setMark(int mark)
{
    this->mark = mark;
}
void Player::setType(PlayerType type)
{
    this->type = type;
}

//void Player::setSock(int sock)
//{
//    this->socket = sock;
//}
