#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

#define  COLUM 10
#define  ROW 10
#define GameWoncondition 4

class CaroMath
{
private:
    string player1;
    string player2;
    struct Block
    {
        int x;
        int y;
    };
    char gameTABLE[COLUM][ROW];
    vector<Block*> Data;


public:
    CaroMath();
    void print();
    void draw();
    void display();
    void Player1Move();
    void Player2Move();
    void playerInput();
    bool checkLine();
    bool checkCross();
    bool CheckDiagonal1();
    bool CheckDiagonal2();
    bool checkWin(string play="");
    bool checkExist(int x, int y);
};


