#include <iostream>
#include "CaroMath.h"
using namespace std;
int main()
{

    CaroMath CM;
    CM.print();

    CM.draw();
    CM.display();
    do{
//        CM.display();
//        CM.addPlayerAToVector();
//        CM.checkWin("X");
//        CM.addPlayerBToVector();
        CM.playerInput();
        CM.checkWin("O");
        CM.display();
    }while(CM.checkWin()==false);
}
