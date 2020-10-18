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
    aPictures[4] = {00, 630, 188, 188, txLoadImage("pic/Wheels/GoodYear.bmp")};

    int N_PICS = 3;
    Picture cPictures[N_PICS];
    cPictures[0] = {200, 200, 300, 300, txLoadImage("pic/volkte37.bmp")};
    cPictures[1] = {400, 400, 430, 429, txLoadImage("pic/Wheels/Continental.bmp")};
    cPictures[2] = {600, 600, 300, 300, txLoadImage("pic/bbs.bmp")};
    int nomer = -100;

    Button btn[6];
    btn[0] = {0,    0, "колёса", 5,
                   {{0,  80  , "колесо1", 0},
                    {0,  110 , "колесо2", 1},
                    {0,  140 , "колесо3", 2},
                    {0,  170 , "колесо4", 3},
                    {0,  200 , "колесо5", 4}}};
    btn[1] = {200,  0, "БАМПЕР ЗАД", 3,
                   {{0,  80  , "лпмеуп1", 0},
                    {0,  110 , "лпмеуп2", 1},
                    {0,  140 , "лпмеуп3", 2},
                    {0,  170 , "лпмеуп4", 3},
                    {0,  200 , "лпмеуп5", 4}}};
    btn[2] = {400,  0, "БАМПЕР ПЕР"};
    btn[3] = {600,  0, "КОЛЁСА"};
    btn[4] = {800,  0, "ШИПЫ"};
    btn[5] = {1000, 0, "ПППППППППП"};

    bool kolVisible = false;
    bool kolVisible1 = false;

    //HDC koleso1 = txLoadImage("pic/volkte37.bmp");
    //bool drawKoleso1 = false;
    HDC koleso2 = txLoadImage("pic/Wheels/Continental.bmp");
    bool drawKoleso2 = false;
    HDC koleso3 = txLoadImage("pic/bbs.bmp");
    bool drawKoleso3 = false;
    HDC koleso4 = txLoadImage("pic/Wheels/Hankook.bmp");
    bool drawKoleso4 = false;
    HDC koleso5 = txLoadImage("pic/Wheels/GoodYear.bmp");
    bool drawKoleso5 = false;

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin ();

        txClear();
        txSetColour(TX_BLACK);
        for (int i = 0; i < 6; i = i + 1)
            btn[i].draw();

        //Клики
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
            //Всплывающая подсказка по наведению мышки
            for (int i = 0; i < 5; i = i + 1)
            {
                if (btn[0].variants[i].focus())
                {
                    int n = btn[0].variants[i].n_pic;
                    Win32::TransparentBlt (txDC(),200,100,200,200,aPictures[n].image,0,0,aPictures[n].width,aPictures[n].height, TX_WHITE);
                }
            }


            //Клик на вариант (выбор колеса)
            if (btn[0].variants[0].cliiiick())
            {
                aPictures[0].visible = !aPictures[0].visible;
                txSleep(200);
            }

            if (btn[0].variants[1].cliiiick())
            {
                aPictures[1].visible = !aPictures[1].visible;
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

            //Тут тоже может быть коммент
            if (kolVisible)
            {
                for (int i = 0; i < btn[0].n_vars; i = i + 1)
                    btn[0].variants[i].draw();
            }

            if (aPictures[0].visible)
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


        //__Движение картинки__
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
