
#include <iostream>
#include "CaroMath.h"
using namespace std;

CaroMath::CaroMath()
{
    player1 = "Play 1 ";
    player2 = "Play 2 ";
}


void CaroMath::print(){
    cout<<"Player 1 <X>"<<"-"<<"Player 2 <0>"<<endl;

}
void CaroMath::draw(){
    for(int i=0 ;i<COLUM;i++){
        for(int j=0;j<ROW;j++)
        {
            gameTABLE[i][j]=' ';
        }
    }
}
void CaroMath::display()
{

    cout << "    ";
    for (int iX = 0; iX < COLUM; iX++)
    {
        if (iX + 1 < 10)
        {
            cout << iX + 1 << "   ";
        }
        else
        {
            cout << iX + 1 << "  ";
        }
    }
    cout << endl;
    cout << "  ";
    for (int iX = 0; iX < 4 * COLUM + 1; iX++) {
        /*cout << "----";*/
        printf("%c", 196);
    }
    cout << endl;
    for (int iX = 0; iX < ROW; iX++) {
        if (iX + 1 < 10)
        {
            cout << iX + 1 << " ";
        }
        else
        {
            cout << iX + 1;
        }
        for (int iY = 0; iY < (COLUM+1); iY++) {
            cout << "| ";/* << gameTABLE[iX][iY] << " "*/
            if (iY != (COLUM)) {
                cout << gameTABLE[iX][iY] << " ";
            }
        }
        cout << endl;
        cout << "  ";
        for (int iY = 0; iY < 4*COLUM+1; iY++) {
            /*cout << "----";*/
            printf("%c", 196);
        }
        cout << endl;
    }
}
void CaroMath::Player1Move()
{
    int iX,iY;
    do
    {
        cout<<player1<<"input1:";
        cin>>iX>>iY;
        --iX;
        --iY;
    } while(((0>iX)||(COLUM-1<iX))||((0>iY)||(ROW-1<iY))||checkExist(iX,iY));
    b=new Block();
    b->x=iX;
    b->y=iY;
    Data.push_back(b);
    for(int i=0; i<COLUM;i++)
    {
        for(int j=0;j<ROW;j++){

            if(b->x==i&&b->y==j){
                gameTABLE[i][j]='X';
            }
        }
    }
}
void CaroMath::Player2Move()
{
    int iX,iY;
    do
    {
        cout<<player2<<"input2:";
        cin>>iX>>iY;
        --iX;
        --iY;
    }while(((0>iX)||(COLUM-1<iX))||((0>iY)||(ROW-1<iY))||checkExist(iX,iY));
    b=new Block();
    b->x=iX;
    b->y=iY;
    Data.push_back(b);
    for(int i=0; i<COLUM;i++)
    {
        for(int j=0;j<ROW;j++){
            if(b->x==i&&b->y==j){
                gameTABLE[i][j]='O';
            }
        }
    }

}
void CaroMath::playerInput()
{
    if(Data.size()==0){
        Player1Move();
    }
    else if((Data.size()-1)%2==0){
        Player2Move();
    }
    else if((Data.size()-1)%2!=0) {
        Player1Move();
    }
    system("cls");
}
bool CaroMath::checkLine(){
    int row=Data[Data.size()-1]->x;
    int colum =Data[Data.size()-1]->y;
    char kt= gameTABLE[row][colum];
    int count=1;
    int j=colum;
    while(j>0){
        j--;
        if(gameTABLE[row][j]==kt)
        {
            count++;
            cout << count << "1\n";
            if(count==GameWoncondition) return true;
        }
        else break;
    }
    j=colum;
    while(j<(COLUM-1)){
        j++;
        if(gameTABLE[row][j]==kt)
        {
            count++;
            cout << count << "2\n";
            if(count==GameWoncondition)   return true;
        }
        else break;
    }
    return false;
}
bool CaroMath::checkCross(){
    int row=Data[Data.size()-1]->x;
    int colum =Data[Data.size()-1]->y;
    char kt= gameTABLE[row][colum];
    int count=1;
    int i=row;
    while(i>0){
        i--;
        if(gameTABLE[i][colum]==kt)
        {
            count++;
            if(count==GameWoncondition) return true;
        }
        else break;
    }
    i=row;
    while(i<(ROW-1)){
        i++;
        if(gameTABLE[i][colum]==kt)
        {
            count++;
            if(count==GameWoncondition)   return true;
        }
        else break;
    }
    return false;
}
bool CaroMath::CheckDiagonal1(){
    int row =Data[Data.size()-1]->x;
    int colum =Data[Data.size()-1]->y;
    char kt=gameTABLE[row][colum];
    int count=1;
    int i=row;
    int j=colum;
    while(j>0 && i>0){
        i--;
        j--;
        if(gameTABLE[i][j]==kt){
            count++;
            if(count==GameWoncondition) return true;
        } else break;

    }
    i=row;
    j=colum;
    while((i<(COLUM-1))&&(j<(ROW-1))){
        i++;
        j++;
        if(gameTABLE[i][j]==kt){
            colum++;
            if(count==GameWoncondition) return true
                    ;            }
        else break;
    }
    return false;
}
bool CaroMath::CheckDiagonal2(){
    int row =Data[Data.size()-1]->x;
    int colum =Data[Data.size()-1]->y;
    char kt=gameTABLE[row][colum];
    int count=1;
    int i=row;
    int j=colum;
    while((i>0) && (j<(ROW-1))){
        i--;
        j++;
        if(gameTABLE[i][j]==kt){
            count++;
            if(count==GameWoncondition) return true;
        } else break;

    }
    i=row;
    j=colum;
    while((i<(ROW-1))&&(j>0)){
        i++;
        j--;
        if(gameTABLE[i][j]==kt){
            count++;
            if(count==GameWoncondition) return true
                    ;            }
        else break;
    }
    return false;
}
bool CaroMath::checkWin(){
    int play;
    if (Data.size() % 2 == 1) play = 1;
    if (Data.size() % 2 == 0) play = 2;
    if (checkCross())
    {
        cout << "Play " << play << " win!\n";
        return true;
    }
    else if (checkLine())
    {
        cout << "Play " << play << " win!\n";
        return true;
    }
    else if (CheckDiagonal1())
    {
        cout << "Play " << play << " win!\n";
        return true;
    }
    else if (CheckDiagonal2())
    {
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
CaroMath::~CaroMath(){
    delete b;
    b=nullptr;
}

