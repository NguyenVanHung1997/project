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
        CM.playerInput();
        CM.checkWin();
        CM.display();
    }while(CM.checkWin()==false);
}
