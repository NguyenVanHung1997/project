#include"Carofile.h"
#include <iostream>

using namespace std;

Carofile::Carofile()
{

}

Carofile::~Carofile()
{

}

void Carofile::createFile(string nameFile){
    ostream writeFile(path, ios::out);
}

void Carofile::writeMatchInfor(string name, int win, int lose, int drawn){
    ostream myfile;
    myFile.open("D:\03_example\project\+getnameFile(),ios::app");
    myFile<<"Name: "<<name<<endl;
    myFile<<"Win: "<<win<<endl;
    myFile<<"Loose: "<<lose<<endl;
    myFile<<"Drawn: "<<drawn<<endl;
    myFile<<"..................."<<endl;
    myFile.close();
}
