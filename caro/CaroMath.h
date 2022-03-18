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
    char gamePAD[COLUM][ROW]{""};
    vector<Block*> Data;
    vector<Block*>Replay;

public:
    CaroMath();
    void print();
    void draw();
    void display();
    void addPlayerAToVector();
    void addPlayerBToVector();
    void playerInput();
    bool checkWinNgang();
    bool checkWinDoc();
    bool checkWincheo1();
    bool checkWincheo2();
    bool checkWin(string play="");
    bool checkExist(int x, int y);
};


