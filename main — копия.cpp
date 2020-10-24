#include "TXLib.h"
#include "stdlib.h"
#include <iostream>
#include <fstream>

using namespace std;


int main()
{

    char header[54];
    ifstream bmp;
    bmp.open("pic/Wheels/Continental.bmp", ios::in | ios::binary);

    if (!bmp) {
        cout << "Error" << endl;
        system("PAUSE");
        exit(1);
    }

    bmp.read(header, 54);

    char a = header[18];

    int b = *(int *)&header[18];
    cout << b << endl;

    system("PAUSE");

  return 0;
}
