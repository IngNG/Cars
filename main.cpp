#include "TXLib.h"
#include <stdlib.h>
#include <iostream>
#include <fstream> // ���������� ����������
using namespace std;

//����� � ���������� ������� ��� ���
struct Button2
{
    const char* text;
    int n_pic;
    int x;
    int y;

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
    const char* text;
    int n_vars;
    Button2 variants[10];
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

struct Picture
{
    int x;
    int y;
    const char* address;
    HDC image;
    int width;
    int height;
    int widthPic;
    int heightPic;
    bool visible;
    string btn;
    string btn2;
};

void drawPicture(Picture pct)
{
    Win32::TransparentBlt(txDC(), pct.x, pct.y, pct.widthPic, pct.heightPic, pct.image, 0, 0, pct.width, pct.height, TX_WHITE);
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

    int N_PICS = 14;
    Picture aPictures[N_PICS];
    //������
    //��� ������ ������ ��������� �������� � ��������� �������?
    //������ 800 �������, ������ 100 �������, ������...
    aPictures[0] = {100, 400, "pic/Cars/Audi R8.bmp"};
    aPictures[1] = {100, 400, "pic/Cars/Chery Tiggo.bmp"};
    aPictures[2] = {100, 400, "pic/Cars/Dodge Ram.bmp"};
    aPictures[3] = {100, 400, "pic/Cars/Formula E.bmp"};
    aPictures[4] = {100, 400, "pic/Cars/Jeep Wrangler.bmp"};
    aPictures[5] = {100, 400, "pic/Cars/Lamborghini Aventador.bmp"};
    aPictures[6] = {100, 400, "pic/Cars/Mercedes G-klasse.bmp"};
    aPictures[7] = {100, 400, "pic/Cars/Mercedes GLS.bmp"};
    aPictures[8] = {100, 400, "pic/Cars/Volkswagen Beetle.bmp"};

    //������
    aPictures[9] = {150, 600, "pic/Wheels/volkte37.bmp"   };
    aPictures[10] = {150, 600, "pic/Wheels/Continental.bmp"};
    aPictures[11] = {150, 600, "pic/Wheels/bbs.bmp"        };
    aPictures[12] = {150, 600, "pic/Wheels/Hankook.bmp"    };
    aPictures[13] = {150, 600, "pic/Wheels/GoodYear.bmp"   };
    int nomer = -100;

    //������ ������, ������, �������� ��������
    for (int z = 0; z < N_PICS; z = z + 1)
    {
        string address = aPictures[z].address;//"pic/wheels/continetal.bmp";
        int pos1 = address.find("/",1);
        int pos2 = address.find("/",pos1 + 1);
        int pos3 = address.find(".",pos2 + 1);

        //���������
        aPictures[z].btn = address.substr(pos1 + 1, pos2-pos1-1);
        //������
        aPictures[z].btn2 = address.substr(pos2 + 1, pos3-pos2-1);

        aPictures[z].image = txLoadImage(aPictures[z].address);
        aPictures[z].height = getHeight(aPictures[z].address);
        aPictures[z].width = getWidth(aPictures[z].address);
        aPictures[z].heightPic = getHeight(aPictures[z].address);
        aPictures[z].widthPic = getWidth(aPictures[z].address);

        //����� � ���������� ����� �� ������� (���� ��������� ��������)
    }
//https://github.com/IngCenter/PixelCars
    int N_BTN = 6;
    Button btn[N_BTN];
    btn[0] = {  "Wheels",  0 };
    //����� ��� ��������� ������ �����������?
    btn[1] = { "������ ���",  5,
                   {{ "������1", 0},
                    { "������2", 1},
                    { "������3", 2},
                    { "������4", 3},
                    { "������5", 4}}};
    btn[2] = { "������ ���",  5,
                   {{ "������1", 0},
                    { "������2", 1},
                    { "������3", 2},
                    { "������4", 3},
                    { "������5", 4}}};
    btn[3] = { "��˨��",      5,
                   {{ "������1", 0},
                    { "������2", 1},
                    { "������3", 2},
                    { "������4", 3},
                    { "������5", 4}}};
    btn[4] = { "����",        5,
                   {{ "����1"  , 0},
                    { "����2"  , 1},
                    { "����3"  , 2},
                    { "����4"  , 3},
                    { "����5"  , 4}}};
    btn[5] = { "Cars",       0};

    //��������� ������ � ��������
    for (int z = 0; z < N_PICS; z = z + 1)
    {
        //��������� ������ �������
        if (strcmp(aPictures[z].btn.c_str(), "Cars") == 0)
        {
            int nomer = btn[5].n_vars;
            btn[5].variants[nomer]={aPictures[z].btn2.c_str(), z};
            btn[5].n_vars = btn[5].n_vars + 1;
        }

        //��������� ������ �����
        if (strcmp(aPictures[z].btn.c_str(), "Wheels") == 0)
        {
            int nomer = btn[0].n_vars;
            btn[0].variants[nomer]={aPictures[z].btn2.c_str(), z};
            btn[0].n_vars = btn[0].n_vars + 1;
        }
    }


    //���������� ������ (������ ����� ����� ���������� � ������ ����)
    for (int i = 0; i < N_BTN; i++)
    {
        btn[i].pressed = false;
        btn[i].x = 200 * i;
        btn[i].y = 0;
        for (int j = 0; j < btn[i].n_vars; j++)
        {
            btn[i].variants[j].x = btn[i].x;      //!
            btn[i].variants[j].y = 80 + 30 * j;      //!
        }
    }

    //��� ��������
    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin ();
        txClear();

        //������ ��������
        txSetColour(TX_BLACK);
        for (int i = 0; i < N_BTN; i = i + 1)
            btn[i].draw();

        //���� �� ������
        for (int i = 0; i < N_BTN; i = i + 1)
        {
            //� ��� ������ �������������� ��� ��������� ������?
            if (btn[i].cliiiiick())
            {
                btn[i].pressed = !btn[i].pressed;
                txSleep(200);
            }
        }

        //������ ������
        for (int z = 0; z < N_BTN; z = z + 1)
        {
            if (btn[z].pressed)
            {
                //����������� �� ��������
                for (int i = 0; i < btn[0].n_vars; i = i + 1)
                {
                    if (btn[z].variants[i].focus())
                    {
                        int n = btn[z].variants[i].n_pic;
                        //� ���� ��������� ���������?
                        Win32::TransparentBlt (txDC(),200,100,200,200,aPictures[n].image,0,0,aPictures[n].width,aPictures[n].height, TX_WHITE);
                    }
                }


                //���� �� ��������
                for (int i=0; i < btn[z].n_vars; i=i+1)
                {
                    if (btn[z].variants[i].cliiiick())
                    {
                        int n = btn[z].variants[i].n_pic;


                        //��� ���1 � ����� �� ���������� ������
                        for (int k = 0; k < N_PICS; k++)
                            if (aPictures[n].btn == aPictures[k].btn && n != k)
                                aPictures[k].visible = false;

                        aPictures[n].visible = !aPictures[n].visible;
                        txSleep(200);
                    }
                }

                //��������� ���������
                for (int i = 0; i < btn[z].n_vars; i = i + 1)
                    btn[z].variants[i].draw();
            }
        }

        if(GetAsyncKeyState(VK_ADD))
        {
            aPictures[nomer].widthPic = aPictures[nomer].widthPic * 1.01;
            aPictures[nomer].heightPic = aPictures[nomer].heightPic * 1.01;
        }

        if(GetAsyncKeyState(VK_SUBTRACT))
        {
            aPictures[nomer].widthPic = aPictures[nomer].widthPic / 1.01;
            aPictures[nomer].heightPic = aPictures[nomer].heightPic / 1.01;
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
        //� ��� ��� ���� ����� ������? 200?
            txMouseX() >= aPictures[i].x       &&  txMouseY() >= aPictures[i].y       &&
            txMouseX() <= aPictures[i].x + 200 &&  txMouseY() <= aPictures[i].y + 200 &&
            aPictures[i].visible)
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
    //�������� ����� � �������
    return 0;
}
