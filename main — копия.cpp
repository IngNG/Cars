#include "TXLib.h"
#include <stdlib.h>
#include <iostream>
#include <fstream> // подключаем библиотеку
using namespace std;

int main()
{

string address = "pic/wheels/continetal.bmp";
int pos1 = address.find("/",1);
int pos2 = address.find("/",pos1 + 1);
int pos3 = address.find(".",pos2 + 1);
cout << address.substr(0,pos1) <<endl;
cout << address.substr(pos1 + 1, pos2-pos1-1)<<endl;
cout << address.substr(pos2+1,pos3-pos2)<<endl;




    //Картинки можно и удалить
    return 0;
}
