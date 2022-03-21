#ifndef CAROFILE_H
#define CAROFILE_H
#include <iostream>
#include <fstream>
#include <string>
#include "CaroMath.h"
#define path "data.ini"
using namespace std;

class Carofile:public CaroMath
{
 public:
    Carofile();
    ~Carofile();
    void createFile(string nameFile);
    void writeMatchInfor(string name, int win, int lose, int drawn);

};
#endif // CAROFILE_H
