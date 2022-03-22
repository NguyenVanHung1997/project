#include <iostream>
#include "CaroMath.h"
#include "Carofile.h"
#define LOG cout<<__FUNCTION__<<":"<<__LINE__<<"\n";
#define LOG2(x) cout<<__FUNCTION__<<":"<<__LINE__<<":"<<x<<"\n";
using namespace std;
CaroMath CM;
Carofile CF;

void play();
void rePlay();
int main()
{
    int opt=0;
    do {
//        system("clear");
        cout << "---- caro game ----\n";
        cout << "Please chose number for each function\n";
        cout << "1. Play\n";
        cout << "2. List player\n";
        cout << "3. RePlay\n";
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
            rePlay();
            break;
        default:
            break;
        }
    } while(opt);
    return 0;
}
void play() {
    CM.resetData();
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
    CM.writeDataMap(result);
    CF.writePlayerRankToFile();
}
void rePlay()
{
    CM.readDataMap();
    CF.readLastPlayerFromFile();
    if(CM.isContinue()) {
        CM.display();
        int result=0;
        do{
            CM.playerInput();
            CM.checkWin();
            CM.display();
            result = CM.checkWin();
        }while(result==0);
        CF.setWinLossDraw(result);
        CM.writeDataMap(result);
        CF.writePlayerRankToFile();
    } else {
        cout << "No continue\nPlease choose play\n";
    }

}
