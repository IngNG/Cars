#include "TXLib.h"
#include <stdlib.h>
#include <iostream>
#include <fstream> // ���������� ����������
using namespace std;


struct Button2
{
    int x;
    int y;
    const char* text;
    int n_pic;

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

struct Button
{
    int x;
    int y;
    const char* text;
    bool pressed;
    int n_vars;
    Button2 variants[10];

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

struct Picture
{
    int x;
    int y;
    const char* address;
    HDC image;
    int width;
    int height;
    bool visible;
};

void drawPicture(Picture pct)
{
    Win32::TransparentBlt(txDC(), pct.x, pct.y, 100, 100, pct.image, 0, 0, pct.width, pct.height, TX_WHITE);
}

int getWidth(const char* adress)
{
    char header[54];
    ifstream bmp;
    bmp.open(adress, ios::in | ios::binary);
    bmp.read(header, 54);
    int shirina = *(int *)&header[18];
    return shirina;
}

int getHeight(const char* adress)
{
    char header[54];
    ifstream bmp;
    bmp.open(adress, ios::in | ios::binary);
    bmp.read(header, 54);
    int vysota = *(int *)&header[22];
    return vysota;
}

int main()
{
    txCreateWindow(1200,720);

    int N_PICS = 9;
    Picture aPictures[N_PICS];
    aPictures[0] = {00, 230, "pic/volkte37.bmp"};
    aPictures[1] = {00, 330, "pic/Wheels/Continental.bmp"};
    aPictures[2] = {00, 430, "pic/bbs.bmp"};
    aPictures[3] = {00, 530, "pic/Wheels/Hankook.bmp"};
    aPictures[4] = {00, 630, "pic/Wheels/GoodYear.bmp"};
    aPictures[5] = {00, 630, "pic/Cars/Jeep Wrangler.bmp"};
    aPictures[6] = {00,720 , "pic/Cars/red car.bmp"};
    aPictures[7] = {00,720 , "pic/Cars/Black car.bmp"};
    aPictures[8] = {00,720 , "pic/Cars/limuzin.bmp"};
    aPictures[9] = {00,720 , "pic/Cars/lg.bmp"};
    int nomer = -100;

    for (int z = 0; z < N_PICS; z = z + 1)
    {
        aPictures[z].image = txLoadImage(aPictures[z].address);
        aPictures[z].height = getHeight(aPictures[z].address);
        aPictures[z].width = getWidth(aPictures[z].address);
    }



    //int N_PICS = 3;
    //Picture cPictures[N_PICS];
    //cPictures[0] = {200, 200, 300, 300, txLoadImage("pic/volkte37.bmp")};
    //cPictures[1] = {400, 400, 430, 429, txLoadImage("pic/Wheels/Continental.bmp")};
    //cPictures[2] = {600, 600, 300, 300, txLoadImage("pic/bbs.bmp")};
    //int nomer = -100;

    int N_BTN = 6;
    Button btn[N_BTN];
    btn[0] = {0,    0, "�����", false, 5,
                   {{0,  80  , "������1", 0},
                    {0,  110 , "������2", 1},
                    {0,  140 , "������3", 2},
                    {0,  170 , "������4", 3},
                    {0,  200 , "������5", 4}}};
    btn[1] = {200,  0, "������ ���", false, 3,
                   {{0,  80  , "������1", 0},
                    {0,  110 , "������2", 1},
                    {0,  140 , "������3", 2},
                    {0,  170 , "������4", 3},
                    {0,  200 , "������5", 4}}};
    btn[2] = {400,  0, "������ ���", false};
    btn[3] = {600,  0, "��˨��", false};
    btn[4] = {800,  0, "����", false};
    btn[5] = {1000, 0, "�����", false, 5,
                   {{1000,  80  , "�����1", 5},
                    {1000,  110 , "�����2", 6},
                    {1000,  140 , "�����3", 7},
                    {1000,  170 , "������4",8},
                    {1000,  200 , "������5",9}}};


    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin ();

        txClear();
        txSetColour(TX_BLACK);
        for (int i = 0; i < N_BTN; i = i + 1)
            btn[i].draw();

        //�����
        for (int i = 0; i < N_BTN; i = i + 1)
        {
            if (btn[i].cliiiiick())
            {
                btn[i].pressed = !btn[i].pressed;
                txSleep(200);
            }
        }

        //������ ������
        if (btn[0].pressed == true)
        {
            //����������� ��������� �� ��������� �����
            for (int i = 0; i < btn[0].n_vars; i = i + 1)
            {
                if (btn[0].variants[i].focus())
                {
                    int n = btn[0].variants[i].n_pic;
                    Win32::TransparentBlt (txDC(),200,100,200,200,aPictures[n].image,0,0,aPictures[n].width,aPictures[n].height, TX_WHITE);
                }
            }
            //���� �� �������
            for (int i=0; i<5; i=i+1)
            {
                if (btn[0].variants[i].cliiiick())
                {
                    int n = btn[0].variants[i].n_pic;
                    aPictures[n].visible = !aPictures[n].visible;
                    txSleep(200);
                }
            }
            //��� ���� ����� ���� �������
            for (int i = 0; i < btn[0].n_vars; i = i + 1)
                btn[0].variants[i].draw();
        }
        //������ ������
        if (btn[5].pressed == true)
        {
            //����������� ��������� �� ��������� �����
            for (int i = 0; i < btn[5].n_vars; i = i + 1)
            {
                if (btn[5].variants[i].focus())
                {
                    int n = btn[5].variants[i].n_pic;
                    Win32::TransparentBlt (txDC(),200,100,200,200,aPictures[n].image,0,0,aPictures[n].width,aPictures[n].height, TX_WHITE);
                }
            }

            for (int i=0; i<btn[5].n_vars; i=i+1)
            {
                if (btn[5].variants[i].cliiiick())
                {
                    int n = btn[5].variants[i].n_pic;
                     aPictures[n].visible = !aPictures[n].visible;
                     txSleep(200);
                }
            }
            //��� ���� ����� ���� �������
            for (int i = 0; i < btn[5].n_vars; i = i + 1)
                btn[5].variants[i].draw();
        }



        //��������� ������ ������
        for (int i = 0; i < N_PICS; i = i + 1)
        {
           if (aPictures[i].visible)
           {
             drawPicture(aPictures[i]);
           }
        }


        //__�������� ��������__
        for (int i = 0; i< N_PICS; i = i + 1)
        if (txMouseButtons() == 1 &&
            txMouseX() >= aPictures[i].x        &&  txMouseY() >= aPictures[i].y     &&
            txMouseX() <= aPictures[i].x + 200 &&  txMouseY() <= aPictures[i].y + 200)
        {
            nomer = i;
        }

        if (GetAsyncKeyState(VK_LEFT) and nomer >= 0)
            aPictures[nomer].x = aPictures[nomer].x-2;
            if(GetAsyncKeyState(VK_RIGHT) and nomer >= 0)
            aPictures[nomer].x = aPictures[nomer].x+2;
            if(GetAsyncKeyState(VK_UP) and nomer >= 0)
            aPictures[nomer].y = aPictures[nomer].y-2;
            if(GetAsyncKeyState(VK_DOWN) and nomer >= 0)
            aPictures[nomer].y = aPictures[nomer].y+2;

         txSleep (15);
         txEnd ();
    }


  return 0;
}
