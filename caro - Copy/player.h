
#ifndef PLAYER_H
#define PLAYER_H

#include"CaroMath.h"
#include"Carofile.h"

enum Index{
    PLAYER1_WIN,
    PLAYER2_WIN,
    PLAYER1_LOSE,
    PLAYER2_LOSE,
    PLAYER1_AND_PLAYER2_DRAWN
};

class Player
{
private:
    std::string name;
    int win;
    int lose;
    int draw;
public:
    void
};

#endif // PLAYER_H
