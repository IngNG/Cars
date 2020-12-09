/// \file Picture.cpp
///Библиотека работы с картинками
#include "TXLib.h"

///Структура "картинка"
struct Picture
{
    int x;
    int y;
    string address;
    HDC image;
    int width;
    int height;
    int widthPic;
    int heightPic;
    bool visible;
    string btn;
    string btn2;
};


///Рисуем картинку
void drawPicture(Picture pct)
{
    Win32::TransparentBlt(txDC(), pct.x, pct.y, pct.widthPic, pct.heightPic, pct.image, 0, 0, pct.width, pct.height, TX_WHITE);
}

