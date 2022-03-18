
#include <iostream>
#include "CaroMath.h"
using namespace std;

CaroMath::CaroMath()
{
    player1 = "Play 1 ";
    player2 = "Play 1 ";
}

void CaroMath::print(){
    cout<<"Player 1 <X>"<<"-"<<"Player 2 <0>"<<endl;

}
void CaroMath::draw(){
    for(int i=0 ;i<COLUM;i++){
        for(int j=0;j<ROW;j++)
        {
            gamePAD[i][j]=' ';
        }
    }
}
void CaroMath::display()
{

    cout << "    ";
        for (int iX = 0; iX < COLUM; iX++)
        {
            if(iX + 1 < 10)
            {
                cout << iX + 1 << "   ";
            }
            else
            {
                cout << iX + 1 << "  ";
            }
        }
        cout << endl;
        for (int iY = 0; iY < ROW; iY++){
            if (iY + 1 < 10)
            {
                cout << iY + 1 << " ";
            }
            else
            {
                cout << iY + 1;
            }
            for (int iX = 0; iX < COLUM + 1; iX++){
                cout << "| " << gamePAD[iX][iY] << " ";
            }
            cout << endl;
            cout << "   ";
            for (int iX = 0; iX < COLUM; iX++){
                cout << "----";
            }
            cout << endl;
        }
}
void CaroMath::addPlayerAToVector()
{
    int x,y;
    do
    {
        cout<<player1<<"input1:";
        cin>>x>>y;
        --x;
        --y;
    } while(((0>x)||(COLUM-1<x))||((0>y)||(ROW-1<y))||checkExist(x,y));

    Block *b=new Block();
    b->x=x;
    b->y=y;
    Data.push_back(b);
    for(int i=0; i<COLUM;i++)
    {
        for(int j=0;j<ROW;j++){

            if(b->x==i&&b->y==j){
                gamePAD[i][j]='X';
            }
        }
    }

}
void CaroMath::addPlayerBToVector()
{
    int x,y;
    do
    {
        cout<<player2<<"input2:";
        cin>>x>>y;
        --x;
        --y;
    }while(((0>x)||(COLUM-1<x))||((0>y)||(ROW-1<y))||checkExist(x,y));
    for(int i=0;i < Data.size();i++)
    {
        if(Data[i]->x==x && Data[i]->y==y)
        {
            cout<<" 0 khong hop le!"<<endl;
            return;
        }
    }
    Block *b=new Block();
    b->x=x;
    b->y=y;
    Data.push_back(b);
    for(int i=0; i<COLUM;i++)
    {
        for(int j=0;j<ROW;j++){
            if(b->x==i&&b->y==j){
                gamePAD[i][j]='O';
            }
        }
    }

}
void CaroMath::playerInput()
{
    if(Data.size()==0){
        addPlayerAToVector();
    }
    else if((Data.size()-1)%2==0){
        addPlayerBToVector();
    }
    else if((Data.size()-1)%2!=0) {
        addPlayerAToVector();
    }
    system("cls");
}
bool CaroMath::checkWinNgang(){
    int don=Data[Data.size()-1]->x;
    int co =Data[Data.size()-1]->y;
    char kt= gamePAD[don][co];
    int dem=1;
    int j=co;
    while(j>0){
        j--;
        if(gamePAD[don][j]==kt)
        {
            dem++;
            cout << dem << "1\n";
            if(dem==GameWoncondition) return true;
        }
        else break;
    }
    j=co;
    while(j<(COLUM-1)){
        j++;
        cout << "dong: " << don << " - j: " << j << '\n';
        cout << "gamePad " << gamePAD[don][j] << '\n';
        if(gamePAD[don][j]==kt)
        {
            dem++;
            cout << dem << "2\n";
            if(dem==GameWoncondition)   return true;
        }
        else break;
    }
    return false;
}
bool CaroMath::checkWinDoc(){
    int don=Data[Data.size()-1]->x;
    int co =Data[Data.size()-1]->y;
    char kt= gamePAD[don][co];
    int dem=1;
    int i=co;
    while(i>0){
        i--;
        if(gamePAD[i][co]==kt)
        {
            dem++;
            if(dem==GameWoncondition) return true;
        }
        else break;
    }
    i=co;
    while(i<(ROW-1)){
        i++;
        if(gamePAD[i][co]==kt)
        {
            dem++;
            if(dem==GameWoncondition)   return true;
        }
        else break;
    }
    return false;
}
bool CaroMath::checkWincheo1(){
    int don =Data[Data.size()-1]->x;
    int co =Data[Data.size()-1]->y;
    char kt=gamePAD[don][co];
    int dem=1;
    int i=don;
    int j=co;
    while(j>0 && i>0){
        i--;
        j--;
        if(gamePAD[i][j]==kt){
            dem++;
            if(dem==GameWoncondition) return true;
        } else break;

    }
    i=don;
    j=co;
    while((i<(COLUM-1))&&(j<(ROW-1))){
        i++;
        j++;
        if(gamePAD[i][j]==kt){
            dem++;
            if(dem==GameWoncondition) return true
                    ;            }
        else break;
    }
    return false;
}
bool CaroMath::checkWincheo2(){
    int don =Data[Data.size()-1]->x;
    int co =Data[Data.size()-1]->y;
    char kt=gamePAD[don][co];
    int dem=1;
    int i=don;
    int j=co;
    while((i>0) && (j<(ROW-1))){
        i--;
        j++;
        if(gamePAD[i][j]==kt){
            dem++;
            if(dem==GameWoncondition) return true;
        } else break;

    }
    i=don;
    j=co;
    while((i<(ROW-1))&&(j>0)){
        i++;
        j--;
        if(gamePAD[i][j]==kt){
            dem++;
            if(dem==GameWoncondition) return true
                    ;            }
        else break;
    }
    return false;
}
bool CaroMath::checkWin(string play){
//    if(play == "X")
    if (checkWinDoc())
    {
        cout << "asdf 1\n";
        cout << "Play " << play << " win!\n";
        return true;
    }
    else if (checkWinNgang())
    {
        cout << "asdf 2\n";
        cout << "Play " << play << " win!\n";
        return true;
    }
    else if (checkWincheo1())
    {
        cout << "asdf 3\n";
        cout << "Play " << play << " win!\n";
        return true;
    }
    else if (checkWincheo2())
    {
        cout << "asdf 4\n";
        cout << "Play " << play << " win!\n";
        return true;
    }
    return false;
}

bool CaroMath::checkExist(int x, int y)
{
    for(int i=0;i < Data.size();i++)
    {
        if(Data[i]->x==x&& Data[i]->y==y)
        {
            cout<<" 0 khong hop le!"<<endl;
            return true;
        }
    }
    return false;
}


