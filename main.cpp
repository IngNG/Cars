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
    int width;
    int height;
    HDC image;
    bool visible;
};

void drawPicture(Picture pct)
{
    Win32::TransparentBlt(txDC(), pct.x, pct.y, pct.width, pct.height, pct.image, 0, 0, pct.width, pct.height, TX_WHITE);
}

int main()
{
    txCreateWindow(1200,720);

    int N_PICS = 7;
    Picture aPictures[N_PICS];
    //Колеса
    aPictures[0] = {100, 400, 709, 309, txLoadImage("pic/Cars/Jeep Wrangler.bmp")};
    aPictures[1] = {100,720,800,252,txLoadImage("pic/Cars/red car.bmp")};
    aPictures[2] = {100,720,600,240,txLoadImage("pic/Cars/Black car.bmp")};

    aPictures[3] = {150, 600, 100, 100, txLoadImage("pic/volkte37.bmp")};
    aPictures[4] = {150, 600, 100, 100, txLoadImage("pic/Wheels/Continental.bmp")};
    aPictures[5] = {150, 600, 100, 100, txLoadImage("pic/bbs.bmp")};
    aPictures[6] = {150, 600, 100, 100, txLoadImage("pic/Wheels/Hankook.bmp")};
    aPictures[7] = {150, 600, 188, 188, txLoadImage("pic/Wheels/GoodYear.bmp")};


    int nomer = -100;

    //int N_PICS = 3;
    //Picture cPictures[N_PICS];
    //cPictures[0] = {200, 200, 300, 300, txLoadImage("pic/volkte37.bmp")};
    //cPictures[1] = {400, 400, 430, 429, txLoadImage("pic/Wheels/Continental.bmp")};
   // cPictures[2] = {600, 600, 300, 300, txLoadImage("pic/bbs.bmp")};
   // int nomer = -100;

    Button btn[6];
    btn[0] = {0,    0, "колёса", 5,
                   {{0,  80  , "колесо1", 7},
                    {0,  110 , "колесо2", 6},
                    {0,  140 , "колесо3", 5},
                    {0,  170 , "колесо4", 4},
                    {0,  200 , "колесо5", 3}}};
    btn[1] = {200,  0, "БАМПЕР ЗАД", 3,
                   {{0,  80  , "лпмеуп1", 7},
                    {0,  110 , "лпмеуп2", 6},
                    {0,  140 , "лпмеуп3", 5},
                    {0,  170 , "лпмеуп4", 4},
                    {0,  200 , "лпмеуп5", 3}}};
    btn[2] = {400,  0, "БАМПЕР ПЕР"};
    btn[3] = {600,  0, "КОЛЁСА"};
    btn[4] = {800,  0, "ШИПЫ"};
    btn[5] = {1000, 0, "Кузов", 5,
                   {{1000,  80  , "Кузов1", 2},
                    {1000,  110 , "Кузов2", 1},
                    {1000,  140 , "Кузов3", 0},
                    {0,  170 , "колесо4", 3},
                    {0,  200 , "колесо5", 4}}};

    bool kolVisible = false;
    bool kolVisible1 = false;
    bool kolVisible5 = false;
    bool kolVisible6 = false;
    bool kolVisible7 = false;

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

        if (btn[5].cliiiiick())
        {
            kolVisible5 = !kolVisible5;
            txSleep(200);
        }

           if (btn[6].cliiiiick())
                {
            kolVisible6 = !kolVisible6;
            txSleep(200);
        }

        if (btn[7].cliiiiick())
                {
            kolVisible7 = !kolVisible7;
            txSleep(200);
        }

        //Колеса
        if (kolVisible == true)
        {
            //Всплывающая подсказка по наведению мышки
            for (int i = 0; i < btn[0].n_vars; i = i + 1)
            {
                if (btn[0].variants[i].focus())
                {
                    int n = btn[0].variants[i].n_pic;
                    Win32::TransparentBlt (txDC(),200,100,200,200,aPictures[n].image,0,0,aPictures[n].width,aPictures[n].height, TX_WHITE);
                }
            }

            for (int i=0; i<5; i=i+1)
            {
                if (btn[0].variants[i].cliiiick())
                {
                    int n = btn[0].variants[i].n_pic;
                     aPictures[n].visible = !aPictures[n].visible;
                     txSleep(200);
                }
            }


            //Тут тоже может быть коммент
            for (int i = 0; i < btn[0].n_vars; i = i + 1)
                btn[0].variants[i].draw();

        }

        //Кузов
        if (kolVisible5 == true)
        {
            //Всплывающая подсказка по наведению мышки
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


            //Тут тоже может быть коммент
            for (int i = 0; i < btn[5].n_vars; i = i + 1)
                btn[5].variants[i].draw();

        }



        //Рисование частей машины
        for (int i = 0; i < N_PICS; i = i + 1)
        {
           if (aPictures[i].visible)
           {
             drawPicture(aPictures[i]);
           }
        }





        //__Движение картинки__
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
