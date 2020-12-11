///\file main.cpp

// Библиотеки
#include "TXLib.h"
#include "Button.cpp"
#include "Files.cpp"
#include <stdlib.h>
#include <dirent.h>
#include <iostream>
#include <fstream>
using namespace std;


int main()
{
    txCreateWindow(1200,720);
    txTextCursor(false);

    //Массив вариантов деталей
    Picture aPictures[1123];
    int N_PICS = fillPictures(aPictures);

    int nomer = -100;

    int N_BTN = 7;
    Button btn[N_BTN];
    btn[0] = {  "Wheels",  0 };
    btn[1] = { "Wheels2",  0};
    btn[2] = { "SideS",  0,};
    btn[3] = { "КОЛЁСА",      0,};
    ///Пушки обрезать бы
    btn[4] = { "Gun",   0,};
    btn[5] = { "Cars",       0};
    btn[6] = { "СправОЧКА",     0};

    ///Формируем кнопки к разделам
    for (int z = 0; z < N_PICS; z = z + 1)
    {
        if (strcmp(aPictures[z].btn.c_str(), "Cars") == 0)
        {
            int nomer = btn[5].n_vars;
            btn[5].variants[nomer]={aPictures[z].btn2.c_str(), z};
            btn[5].n_vars = btn[5].n_vars + 1;
        }

        if (strcmp(aPictures[z].btn.c_str(), "Gun") == 0)
        {
            int nomer = btn[4].n_vars;
            btn[4].variants[nomer]={aPictures[z].btn2.c_str(), z};
            btn[4].n_vars = btn[4].n_vars + 1;
        }

        if (strcmp(aPictures[z].btn.c_str(), "Wheels") == 0)
        {
            int nomer = btn[0].n_vars;
            btn[0].variants[nomer]={aPictures[z].btn2.c_str(), z};
            btn[0].n_vars = btn[0].n_vars + 1;
        }

         if (strcmp(aPictures[z].btn.c_str(), "Wheels2") == 0)
        {
            int nomer = btn[1].n_vars;
            btn[1].variants[nomer]={aPictures[z].btn2.c_str(), z};
            btn[1].n_vars = btn[1].n_vars + 1;
        }

         if (strcmp(aPictures[z].btn.c_str(), "SideS") == 0)
        {
            int nomer = btn[2].n_vars;
            btn[2].variants[nomer]={aPictures[z].btn2.c_str(), z};
            btn[2].n_vars = btn[2].n_vars + 1;
        }
    }


    ///Координаты кнопок
    for (int i = 0; i < N_BTN; i++)
    {
        btn[i].pressed = false;
        btn[i].x = 160 * i;
        btn[i].y = 0;
        for (int j = 0; j < btn[i].n_vars; j++)
        {
            btn[i].variants[j].x = btn[i].x;
            btn[i].variants[j].y = 80 + 30 * j;
        }
    }


    string PAGE = "Редактор";

    ///редактор
    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin ();
        txClear();

        if (PAGE == "Справка")
        {
            txSetFillColor(TX_WHITE);
            txSetColor(TX_BLACK);
            txClear();
            txDrawText(100, 600, 900, 700, "Назад");
            txDrawText(100, 100, 1000, 500,
                  "Привет, Страдалец. \n"
                  "Это редактор машин\n"
                  "Если хочешь двигать детальки или машины, нажми на обьект, чтобы выделить его и используй стрелки на клавиатуре \n"
                  "Чтобы Увеличить/уменьшить детальки или машины, нажми на обьект, чтобы выделить его, и используй Кнопки + и - на нампаде \n"

            );


            if (txMouseButtons() == 1 &&
                txMouseX() >= 100 && txMouseY() >= 600 &&
                txMouseX() <= 900 && txMouseY() <= 700)
            {
                PAGE = "Редактор";
                txSleep(500);
            }
        }

        if (PAGE == "Редактор")
        {
            if (btn[6].click())
            {
                PAGE = "Справка";
                txSleep(500);
            }


            ///Рисование кнопок
            txSetColour(TX_BLACK);
            for (int i = 0; i < N_BTN; i = i + 1)
                btn[i].draw();

            ///Клик на кнопки
            for (int i = 0; i < N_BTN; i = i + 1)
            {
                if (btn[i].click())
                {
                    btn[i].pressed = !btn[i].pressed;
                    txSleep(200);
                }
            }

            ///Нажаты колеса
            for (int z = 0; z < N_BTN; z = z + 1)
            {
                if (btn[z].pressed)
                {
                    ///Фокусиров
                    for (int i = 0; i < btn[0].n_vars; i = i + 1)
                    {
                        if (btn[z].variants[i].focus())
                        {
                            int n = btn[z].variants[i].n_pic;
                            Win32::TransparentBlt (txDC(),200,100,200,200,aPictures[n].image,0,0,aPictures[n].width,aPictures[n].height, TX_WHITE);
                        }
                    }


                    ///Клик на варианты
                    for (int i=0; i < btn[z].n_vars; i=i+1)
                    {
                        if (btn[z].variants[i].click())
                        {
                            int n = btn[z].variants[i].n_pic;


                            for (int k = 0; k < N_PICS; k++)
                                if (aPictures[n].btn == aPictures[k].btn && n != k)
                                    aPictures[k].visible = false;

                            aPictures[n].visible = !aPictures[n].visible;
                            txSleep(200);
                        }
                    }

                    ///Рисование вариантов
                    for (int i = 0; i < btn[z].n_vars; i = i + 1)
                        btn[z].variants[i].draw();
                }
            }

            ///Рисование частей машины
            for (int i = 0; i < N_PICS; i = i + 1)
            {
                if (aPictures[i].visible)
                {
                    drawPicture(aPictures[i]);
                }
            }

            ///Движение картинки
            for (int i = 0; i< N_PICS; i = i + 1)
            if (txMouseButtons() == 1 &&
                txMouseX() >= aPictures[i].x       &&  txMouseY() >= aPictures[i].y       &&
                txMouseX() <= aPictures[i].x + 200 &&  txMouseY() <= aPictures[i].y + 200 &&
                aPictures[i].visible)
            {
                nomer = i;
            }

            if (GetAsyncKeyState(VK_LEFT) and nomer >= 0)
                aPictures[nomer].x = aPictures[nomer].x-5;
            if(GetAsyncKeyState(VK_RIGHT) and nomer >= 0)
                aPictures[nomer].x = aPictures[nomer].x+5;
            if(GetAsyncKeyState(VK_UP) and nomer >= 0)
                aPictures[nomer].y = aPictures[nomer].y-5;
            if(GetAsyncKeyState(VK_DOWN) and nomer >= 0)
                aPictures[nomer].y = aPictures[nomer].y+5;

            if (GetAsyncKeyState(VK_ADD))
            {
                aPictures[nomer].widthPic = aPictures[nomer].widthPic + 15;
                aPictures[nomer].heightPic = aPictures[nomer].heightPic + 5;
            }

            if (GetAsyncKeyState(VK_SUBTRACT))
            {
                aPictures[nomer].widthPic = aPictures[nomer].widthPic - 15;
                aPictures[nomer].heightPic = aPictures[nomer].heightPic - 5;
            }

        }

        txSleep (15);
        txEnd ();
    }

    return 0;
}
