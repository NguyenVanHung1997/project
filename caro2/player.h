#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <string>
//#include <ui.hpp>
//#include <connection.hpp>

enum PlayerType
{
    LocalPlayer = 0,
    RemotePlayer = 1
};

class Player
{

    std::string name;
    int win;
    int lose;
    int draw;

    int total;
    int mark;
    PlayerType type;
    int socket = 0;

public:
    Player();
    std::string getName();
    int getWin();
    int getTotal();
    PlayerType getType();
    int getSock();
    void setName(std::string name);
    void setWin(int win);
    void setTotal(int total);
    void setType(PlayerType type);
//    void setSock(int sock);
    //    void takeAMark(BoardGame &board, UI &ui, Connection *conn);
    int getLose() const;
    void setLose(int newLose);
    int getDraw() const;
    void setDraw(int newDraw);
};

#endif
