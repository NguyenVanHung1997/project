#include"Carofile.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Carofile::Carofile()
{
}
Carofile::~Carofile()
{
}
void Carofile::readPlayerRank()
{
    string buffer;
    ifListPlayer.open(".ini");
    while(!ifListPlayer.eof())
    {
        getline(ifListPlayer,buffer);
        if(buffer.length()==0)
            break;
        stringstream strstream(buffer);
        string name,win,lose,draw;
        getline(strstream,name,' ');
        getline(strstream,win,' ');
        getline(strstream,lose,' ');
        getline(strstream,draw,' ');
        if(name.length()<=0||win.length()<=0||lose.length()<=0||draw.length()<=0)
            continue;
        shared_ptr<Player> newPlayer = make_shared<Player>();
        newPlayer->setName(name);
        newPlayer->setWin(stoi(win));
        newPlayer->setWin(stoi(lose));
        newPlayer->setWin(stoi(draw));
        vPlayers.emplace_back(newPlayer);
    }
    ifListPlayer.close();
    for(size_t i=0;i<vPlayers.size();i++)
    {
        mPlayers[vPlayers[i]->getName()]=vPlayers[i];
    }

}
void Carofile::writePlayerRank()
{
    ofListPlayer.open(".ini");
        for (size_t i = 0; i < vPlayers.size(); i++)
        {
            ofListPlayer << vPlayers[i]->getName() << " ";
            ofListPlayer << vPlayers[i]->getWin() << " ";
            ofListPlayer << vPlayers[i]->getLose() << " ";
            ofListPlayer << vPlayers[i]->getDraw() << endl;
        }
        ofListPlayer.close();
}
void Carofile::setNamePlayer()
{
    string name1, name2;
    cout<<"----Set name player----\n";
    cout<<"Player 1 is: "<<name1;
    cin>>name1;
    cout<<"Player 2 is: "<<name2;
    cin>>name2;
    if(mPlayers[name1] !=NULL && mPlayers[name1]->getName().compare(name1)==0)
    {
        player1 =mPlayers[name1];
    }
    else
    {
        player1=make_shared<Player>();
        player1->setName(name1);
        vPlayers.emplace_back(player1);
        mPlayers[name1]=player1;
    }
    if(mPlayers[name2] !=NULL && mPlayers[name2]->getName().compare(name2)==0)
    {
        player2 =mPlayers[name2];
    }
    else
    {
        player2=make_shared<Player>();
        player2->setName(name2);
        vPlayers.emplace_back(player2);
        mPlayers[name2]=player2;
    }
}
void Carofile::showListPlayer()
{
    cout<<"Name\t\t"<<"win\t\t"<<"lose\t\t"<<"draw\n";
//    readPlayerRank();
    for(auto &i:vPlayers){
        cout<<i->getName()<<"\t\t"<<i->getWin()<<"\t\t"<<i->getLose()<<"\t\t"<<i->getDraw()<<'\n';
    }
}
void Carofile::setWinLossDraw(int playerWin)
{
    if(playerWin==1){
        player1->setWin(player1->getWin()+1);
        player2->setLose(player2->getLose()+1);
    }else if (playerWin==2){
        player2->setWin(player2->getWin()+1);
                player1->setLose(player1->getLose()+1);
    }else {
        player1->setDraw(player1->getDraw()+1);
        player2->setDraw(player2->getDraw()+1);
    }
}

