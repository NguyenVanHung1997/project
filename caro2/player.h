#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <string>

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

    void setName(std::string name);
    void setWin(int win);
    void setTotal(int total);
//    void setSock(int sock);
    //    void takeAMark(BoardGame &board, UI &ui, Connection *conn);
    int getLose() const;
    void setLose(int newLose);
    int getDraw() const;
    void setDraw(int newDraw);
};

#endif
