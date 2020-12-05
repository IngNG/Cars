/// \file Picture.cpp
///���������� ������ � ����������
#pragma once
#include "TXLib.h"

///��������� "��������"
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


///������ ��������
void drawPicture(Picture pct)
{
    Win32::TransparentBlt(txDC(), pct.x, pct.y, pct.widthPic, pct.heightPic, pct.image, 0, 0, pct.width, pct.height, TX_WHITE);
}

