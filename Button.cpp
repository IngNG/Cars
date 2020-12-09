#include "TXLib.h"

///������ ��� �������� ������ (���� 2105)
struct Button2
{
    ///����� ������ (�������� ������)
    const char* text;
    ///����� ��������, ������� ������� � �������
    int n_pic;
    int x;
    int y;

    ///��������� ������
    void draw()
    {
        txSelectFont("Comic Sans MS", 20);
        txRectangle(x, y, x + 160, y + 30);
        txDrawText (x, y, x + 160, y + 30, text);
    }

    bool click()
    {
        if (txMouseButtons() == 1 &&
            txMouseX() >= x       &&  txMouseY() >= y     &&
            txMouseX() <= x + 160 &&  txMouseY() <= y + 30)
            return true;
        else
            return false;
    }

    bool focus()
    {
        if (txMouseX() >= x       &&  txMouseY() >= y   &&
            txMouseX() <= x + 160 &&  txMouseY() <= y + 30)
            return true;
        else
            return false;
    }
};

///������ ��� ��������� (������)
struct Button
{
    const char* text;
    int n_vars;
    Button2 variants[100];
    int x;
    int y;
    bool pressed;
///��������� ������
    void draw()
    {
        txSelectFont("Comic Sans MS", 30);
        txRectangle(x, y, x + 160, y + 80);
        txDrawText (x, y, x + 160, y + 80, text);
    }
///���� �� ������
    bool click()
    {
            if (txMouseButtons() == 1 &&
                txMouseX() >= x       &&  txMouseY() >= 0   &&
                txMouseX() <= x + 160 &&  txMouseY() <= 80)
                return true;
            else
                return false;
    }
};
