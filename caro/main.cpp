#include <iostream>
#include "CaroMath.h"
#include "Carofile.h"
using namespace std;
CaroMath CM;
Carofile CF;
int main()
{
    void play();
    void Replay();
    int opt=0;
    do {
//        system("clear");
        cout << "---- caro game ----\n";
        cout << "Please chose number for each function\n";
        cout << "1. Play\n";
        cout << "2. List player\n";
        cout << "3. Replay\n";
        cout << "0. Exit\n";
        cin >> opt;
        switch (opt) {
        case 1:
            play();
            break;
        case 2:
            CF.showListPlayer();
            break;
        case 3:
            Replay();
            break;
        default:
            break;
        }
    } while(opt);
    return 0;
}
void play() {
    CF.readPlayerRank();
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
    CF.writePlayerRank();
    CM.reset();
}
void Replay()
{
    CM.readDataMap();

//    CM.print();
//    CM.draw();
    CM.display();
    int result=0;
    do{
        CM.playerInput();
        CM.checkWin();
        CM.display();
        result = CM.checkWin();
    }while(result==0);
    CF.setWinLossDraw(result);
    CF.writePlayerRank();
    CM.reset();
}
