#ifndef CAROFILE_H
#define CAROFILE_H
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <unordered_map>
#include "CaroMath.h"
#include "player.h"
//#define LOG cout<<__FUNCTION__<<":"<<__LINE__<<"\n";
//#define LOG2(x) cout<<__FUNCTION__<<":"<<__LINE__<<":"<<x<<"\n";
#define path "data.ini"
using namespace std;


class Carofile:public CaroMath
{
 public:
    Carofile();
    ~Carofile();
//    void createFile(string nameFile);
//    void writeMatchInfor(string name, int win, int lose, int draw);
    void readPlayerRankFromFile();
    void writePlayerRankToFile();
    void setNamePlayer();
    void showListPlayer();
    void setWinLossDraw(int playerWin);
    void readLastPlayerFromFile();

private:
    void writeLastPlayerToFile();
    std::vector<std::shared_ptr<Player>> vPlayers;
//    std::shared_ptr<Player> player;
    std::shared_ptr<Player> player1;
    std::shared_ptr<Player> player2;
    std::unordered_map<std::string, std::shared_ptr<Player>> mPlayers;
    std::ifstream ifListPlayer;
    std::ofstream ofListPlayer;
};
#endif // CAROFILE_H
