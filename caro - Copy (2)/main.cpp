#include <iostream>
#include "CaroMath.h"
#include "Carofile.h"
using namespace std;
CaroMath CM;
Carofile CF;

void play();
int main()
{
    int opt=0;
    do {
//        system("clear");
        cout << "---- caro game ----\n";
        cout << "Please chose number for each function\n";
        cout << "1. Play\n";
        cout << "2. List player\n";
        cout << "0. Exit\n";
        cin >> opt;
        switch (opt) {
        case 1:
            play();
            break;
        case 2:
            CF.showListPlayer();
        default:
            break;
        }
    } while(opt);
    return 0;
}
void play() {
    CF.loadPlayerRank();
    CF.setNamePlayer();
    CM.print();
    CM.draw();
    CM.display();
    int result=0;
    do{
        CM.playerInput();
        CM.checkWin();
        CM.display();
        result = CM.checkWin();
    }while(result==0);
    CF.setWinLossDraw(result);
    CF.storePlayerRank();
}
