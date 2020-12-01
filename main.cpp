#include "TXLib.h"
#include "Button.cpp"
#include <stdlib.h>
#include <dirent.h>
#include <iostream>
#include <fstream> // ���������� ����������
using namespace std;

//����� � ���������� ������� ��� ���
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

int readFiles(const char* address, Picture* aPictures, int N)
{
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (address)) != NULL) {
     /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL) {
            string s = ent->d_name;
            s = address + s;
            if(s.find (".bmp") != -1 )
            {
                 //cout << s << endl;
                aPictures[N] = {100, 100, s};
                N = N + 1;
            }
         }
        closedir (dir);
     }

     return N;
}

int main()
{
    txCreateWindow(1200,720);

    int N_PICS = 0;
    Picture aPictures[1123];
    N_PICS = readFiles("pic/Cars/", aPictures, N_PICS);
    N_PICS = readFiles("pic/Gun/", aPictures, N_PICS);
    N_PICS = readFiles("pic/Wheels/", aPictures, N_PICS);
    N_PICS = readFiles("pic/Wheels2/", aPictures, N_PICS);
    N_PICS = readFiles("pic/SideS/", aPictures, N_PICS);

    //��� ������ ������� ��������� 20 �����?
    //������
    //��� ������ ������ ��������� �������� � ��������� �������?
    //������ 800 �������, ������ 100 �������, ������...
    /*aPictures[0] = {100, 400, "pic/Cars/Audi R8.bmp"};
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
    aPictures[13] = {150, 600, "pic/Wheels/GoodYear.bmp"   };*/
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

        aPictures[z].image = txLoadImage(aPictures[z].address.c_str());
        aPictures[z].height = getHeight(aPictures[z].address.c_str());
        aPictures[z].width = getWidth(aPictures[z].address.c_str());
        aPictures[z].heightPic = getHeight(aPictures[z].address.c_str());
        aPictures[z].widthPic = getWidth(aPictures[z].address.c_str());

        if (aPictures[z].btn == "Cars")
        {
            aPictures[z].x = 150;
            aPictures[z].y = 400;
        }

           if (aPictures[z].btn == "Wheels")
        {
            aPictures[z].x = 200;
            aPictures[z].y = 500;
        }
           if (aPictures[z].btn == "Wheels2")
        {
            aPictures[z].x = 700;
            aPictures[z].y = 500;
        }
            if (aPictures[z].btn == "SideS")
        {
            aPictures[z].x = 400;
            aPictures[z].y = 500;
        }

        //����� � ���������� ����� �� ������� (���� ��������� ��������)
    }
//https://github.com/IngCenter/PixelCars
    //���-�� ����������, ��� ������ ������ �����?
    int N_BTN = 7;
    Button btn[N_BTN];
    btn[0] = {  "Wheels",  0 };
    //����� ��� ��������� ������ �����������?
    btn[1] = { "Wheels2",  0};
    btn[2] = { "SideS",  0,};
    btn[3] = { "��˨��",      5,
                   {{ "������1", 0},
                    { "������2", 1},
                    { "������3", 2},
                    { "������4", 3},
                    { "������5", 4}}};
    //����� �������� ��
    btn[4] = { "Gun",   0,};
    btn[5] = { "Cars",       0};
    btn[6] = { "� ����",     0};

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

        if (strcmp(aPictures[z].btn.c_str(), "Gun") == 0)
        {
            int nomer = btn[4].n_vars;
            btn[4].variants[nomer]={aPictures[z].btn2.c_str(), z};
            btn[4].n_vars = btn[4].n_vars + 1;
        }

        //��������� ������ �����
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


    string PAGE = "��������";
    //�� ��� ������ ���������� ��� ���� ��?
    bool Help = false;


    //��� ��������
    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin ();
        txClear();

        if (Help)
        {
            txBegin();
            if (PAGE == "�������")
            {
                txSetFillColor(TX_WHITE);
                txSetColor(TX_BLACK);
                txClear();
                txDrawText(1000, 600, 1200, 700, "������!");
                txDrawText(100, 100, 1200, 500,
                      "������, ���������. \n"

                );

                //������, ��� ���������� � ����� � ������ �� ����������?
                if (txMouseButtons() == 1 &&
                    txMouseX() >= 500 && txMouseY() >= 600 &&
                    txMouseX() <= 500 && txMouseY() <= 600)
                {
                    PAGE = "��������";
                    txSleep(500);

                    //����� �� ������ �������������, ����� ������� �� ��������
                    txSetFillColour(TX_GRAY);
                    txSetColour(TX_BLACK);
                    txRectangle(0,0,1532,150);
                }
            }
        }

        if (PAGE == "��������")
        {
            //��-������� � ��� ���� �� ������ �������
            /*if (Click(btn[6].x, btn[6].y))
            {
                PAGE = "�������";
                txSleep(500);
            } */



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

        //����� � txClear � ���� ������� �����
        txSleep (15);
        txEnd ();
    }

    //�������� ����� � �������
    //txDeleteDC...

    return 0;
}
