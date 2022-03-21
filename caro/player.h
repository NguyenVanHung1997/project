#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <string>
//#include <ui.hpp>
//#include <connection.hpp>


class Player
{
    std::string name;
    int win;
    int lose;
    int draw;

public:
    Player();
    std::string getName();
    int getWin();
    int getTotal();
    int getMark();
    void setName(std::string name);
    void setWin(int win);
    int getLose() const;
    void setLose(int newLose);
    int getDraw() const;
    void setDraw(int newDraw);
};
#endif