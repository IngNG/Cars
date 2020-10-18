#include "TXLib.h"

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
                txMouseX() <= x + 200 &&  txMouseY() <= 100)
                return true;
            else
                return false;
    }
};

struct Picture
{
    int x;
    int y;
    int width;
    int height;
    HDC image;
    bool visible;
};

void drawPicture(Picture pct)
{
    Win32::TransparentBlt(txDC(), pct.x, pct.y, 100, 100, pct.image, 0, 0, pct.width, pct.height, TX_WHITE);
}

int main()
{
    txCreateWindow(1200,720);

    Picture aPictures[10];
    aPictures[0] = {00, 230, 300, 300, txLoadImage("pic/volkte37.bmp")};
    aPictures[1] = {00, 330, 430, 429, txLoadImage("pic/Wheels/Continental.bmp")};
    aPictures[2] = {00, 430, 300, 300, txLoadImage("pic/bbs.bmp")};
    aPictures[3] = {00, 530, 200, 200, txLoadImage("pic/Wheels/Hankook.bmp")};
    aPictures[4] = {00, 630, 200, 200, txLoadImage("pic/rjktcj.bmp")};


    int N_PICS = 3;
    Picture cPictures[N_PICS];
    cPictures[0] = {200, 200, 300, 300, txLoadImage("pic/volkte37.bmp")};
    cPictures[1] = {400, 400, 430, 429, txLoadImage("pic/Wheels/Continental.bmp")};
    cPictures[2] = {600, 600, 300, 300, txLoadImage("pic/bbs.bmp")};
    int nomer = -100;

    Button btn[6];
    btn[0] = {0,    0, "�����", 5,
                   {{0,  80  , "������1", 0},
                    {0,  110 , "������2", 1},
                    {0,  140 , "������3", 2},
                    {0,  170 , "������4", 3},
                    {0,  200 , "������5", 4}}};
    btn[1] = {200,  0, "������ ���", 3,
                   {{0,  80  , "������1", 0},
                    {0,  110 , "������2", 1},
                    {0,  140 , "������3", 2},
                    {0,  170 , "������4", 3},
                    {0,  200 , "������5", 4}}};
    btn[2] = {400,  0, "������ ���"};
    btn[3] = {600,  0, "��˨��"};
    btn[4] = {800,  0, "����"};
    btn[5] = {1000, 0, "����������"};

    bool kolVisible = false;
    bool kolVisible1 = false;

    HDC koleso1 = txLoadImage("pic/volkte37.bmp");
    bool drawKoleso1 = false;
    HDC koleso2 = txLoadImage("pic/Wheels/Continental.bmp");
    bool drawKoleso2 = false;
    HDC koleso3 = txLoadImage("pic/bbs.bmp");
    bool drawKoleso3 = false;
    HDC koleso4 = txLoadImage("pic/Wheels/Hankook.bmp");
    bool drawKoleso4 = false;
    HDC koleso5 = txLoadImage("pic/rjktcj.bmp");
    bool drawKoleso5 = false;

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin ();

        txClear();
        txSetColour(TX_BLACK);
        for (int i = 0; i < 6; i = i + 1)
            btn[i].draw();

        //�����
        if (btn[0].cliiiiick())
        {
            kolVisible = !kolVisible;
            txSleep(200);
        }

        if (btn[1].cliiiiick())
        {
            kolVisible1 = !kolVisible1;
            txSleep(200);
        }

        if (kolVisible == true)
        {
            //����������� ��������� �� ��������� �����
            if (btn[0].variants[0].focus())
            {
                Win32::TransparentBlt (txDC(),200,100,200,200,koleso1,0,0,300,300, TX_WHITE);
            }

            if (btn[0].variants[1].focus())
            {
                Win32::TransparentBlt (txDC(),200,100,200,200,koleso2,0,0,430,429, TX_WHITE);
            }

            if (btn[0].variants[2].focus())
            {
                Win32::TransparentBlt (txDC(),200,100,200,200,koleso3,0,0,300,300, TX_WHITE);
            }

            if (btn[0].variants[3].focus())
            {
                Win32::TransparentBlt (txDC(),200,100,200,200,koleso4,0,0,200,200, TX_WHITE);
            }

            if (btn[0].variants[4].focus())
            {
                Win32::TransparentBlt (txDC(),200,100,200,200,koleso5,0,0,200,200, TX_WHITE);
            }

            //���� �� ������� (����� ������)
            if (btn[0].variants[0].cliiiick())
            {
                drawKoleso1 = !drawKoleso1;
                txSleep(200);
            }

            if (btn[0].variants[1].cliiiick())
            {
                drawKoleso2 = !drawKoleso2;
                txSleep(200);
            }

            if (btn[0].variants[2].cliiiick())
            {
                drawKoleso3 = !drawKoleso3;
                txSleep(200);
            }

            if (btn[0].variants[3].cliiiick())
            {
                drawKoleso4 = !drawKoleso4;
                txSleep(200);
            }

            if (btn[0].variants[4].cliiiick())
            {
                drawKoleso5 = !drawKoleso5;
                txSleep(200);
            }

            //��� ���� ����� ���� �������
            if (kolVisible)
            {
                for (int i = 0; i < btn[0].n_vars; i = i + 1)
                    btn[0].variants[i].draw();
            }
            if (drawKoleso1)
            {
                drawPicture(aPictures[0]);
            }

            if (drawKoleso2)
            {
                drawPicture(aPictures[1]);
            }

            if (drawKoleso3)
            {
                drawPicture(aPictures[2]);
            }

            if (drawKoleso4)
            {
                drawPicture(aPictures[3]);
            }

            if (drawKoleso5)
            {
                drawPicture(aPictures[4]);
            }
        }

        if (kolVisible1 == true)
        {

        }




        if (btn[0].cliiiiick())
        {
            cPictures[0].visible = !cPictures[0].visible;
            txSleep(200);
        }
        if (btn[1].cliiiiick())
        {
            cPictures[1].visible = !cPictures[1].visible;
            txSleep(200);
        }
        if (btn[2].cliiiiick())
        {
            cPictures[2].visible = !cPictures[2].visible;
            txSleep(200);
        }



            if (cPictures[0].visible)
                drawPicture(cPictures[0]);
            if (cPictures[1].visible)
                drawPicture(cPictures[1]);
            if (cPictures[2].visible)
                drawPicture(cPictures[2]);


        //__�������� ��������__
        for (int i = 0; i< N_PICS; i = i + 1)
        if (txMouseButtons() == 1 &&
            txMouseX() >= cPictures[i].x        &&  txMouseY() >= cPictures[i].y     &&
            txMouseX() <= cPictures[i].x + 200 &&  txMouseY() <= cPictures[i].y + 30)
        {
            nomer = i;
        }

        if (GetAsyncKeyState(VK_LEFT) and nomer >= 0)
            cPictures[nomer].x = cPictures[nomer].x-2;
            if(GetAsyncKeyState(VK_RIGHT) and nomer >= 0)
            cPictures[nomer].x = cPictures[nomer].x+2;
            if(GetAsyncKeyState(VK_UP) and nomer >= 0)
            cPictures[nomer].y = cPictures[nomer].y-2;
            if(GetAsyncKeyState(VK_DOWN) and nomer >= 0)
             cPictures[nomer].y = cPictures[nomer].y+2;


//for (int i = 0; i < //COUNT_PICTURES ; i++)
      //  if (cPictures[i].category ==
     //       centePictures [npict].
     //       i != nPict)
     //   {
     //   centerPicter[i].visible = false;
     //   }
//}

         txSleep (15);
         txEnd ();
    }


  return 0;
}
