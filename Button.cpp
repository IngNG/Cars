#include "TXLib.h"

///Кнопка для варианта детали (Лада 2105)
struct Button2
{
    ///Текст кнопки (название детали)
    const char* text;
    ///Номер картинки, которая связана с кнопкой
    int n_pic;
    int x;
    int y;

    ///Рисование кнопки
    void draw()
    {
        txSelectFont("Comic Sans MS", 20);
        txRectangle(x, y, x + 200, y + 30);
        txDrawText (x, y, x + 200, y + 30, text);
    }

    bool cliiiick()
    {
            if (txMouseButtons() == 1 &&
                txMouseX() >= x       &&  txMouseY() >= y     &&
                txMouseX() <= x + 200 &&  txMouseY() <= y + 30)
                return true;
            else
                return false;
    }

    bool focus()
    {
            if (txMouseX() >= x       &&  txMouseY() >= y   &&
                txMouseX() <= x + 200 &&  txMouseY() <= y + 30)
                return true;
            else
                return false;
    }
};

///Кнопка для категории (колеса)
struct Button
{
    const char* text;
    int n_vars;
    Button2 variants[100];
    int x;
    int y;
    bool pressed;

    void draw()
    {
        txSelectFont("Comic Sans MS", 30);
        txRectangle(x, y, x + 200, y + 80);
        txDrawText (x, y, x + 200, y + 80, text);
    }

    bool cliiiiick()
    {
            if (txMouseButtons() == 1 &&
                txMouseX() >= x       &&  txMouseY() >= 0   &&
                txMouseX() <= x + 200 &&  txMouseY() <= 80)
                return true;
            else
                return false;
    }
};
