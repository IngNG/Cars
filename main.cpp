#include "TXLib.h"

void drawButton(int x, const char* text)
{
    txSelectFont("Arial", 30);
    txRectangle(x, 0, x + 200, 100);
    txDrawText (x, 0, x + 200, 100, text);
}

bool cliiiiick(int x)
{
        if (txMouseButtons() == 1 &&
            txMouseX() >= x       &&  txMouseY() >= 0   &&
            txMouseX() <= x + 200 &&  txMouseY() <= 100)
            return true;
        else
            return false;
}



int main()
{
    txCreateWindow(1280,720);

    HDC koleso1 = txLoadImage("pic/volkte37.bmp");
    bool drawKoleso1 = false;
    HDC koleso2 = txLoadImage("pic/kakietodiski.bmp");
    bool drawKoleso2 = false;
    HDC koleso3 = txLoadImage("pic/bbs.bmp");
    bool drawKoleso3 = false;

    HDC car0 = txLoadImage ("pic/car0.bmp");
    bool drawCar0 = false;
    HDC car1 = txLoadImage ("pic/car1.bmp");
    bool drawCar1 = false;
    HDC car2 = txLoadImage ("car2.bmp");
    bool drawCar2 = false;
    HDC car3 = txLoadImage ("car3.bmp");
    bool drawCar3 = false;
    HDC car4 = txLoadImage ("car4.bmp");
    bool drawCar4 = false;
    HDC car5 = txLoadImage ("car5.bmp");
    bool drawCar5 = false;
    HDC car6 = txLoadImage ("car6.bmp");
    bool drawCar6 = false;
    HDC car7 = txLoadImage ("car7.bmp");
    bool drawCar7 = false;

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin ();

        txClear();
        txSetColour(TX_BLACK);
        //Нопки
        drawButton(0,   "WHEELS");
        drawButton(200, "ENGINE");
        drawButton(400, "HOOD"  );
        drawButton(600, "ROOF"  );



        //Картинки
        //Win32::TransparentBlt (txDC(),900,20,200,200,koleso1,0,0,634,634, TX_WHITE);
        //Win32::TransparentBlt (txDC(),900,240,200,200,koleso2,0,0,430,429, TX_WHITE);
        //Win32::TransparentBlt (txDC(),900,480,200,200,koleso3,0,0,900,900, TX_WHITE);
        //Win32::TransparentBlt (txDC(),300,300,200,200,koleso1,0,0,634,634, TX_WHITE);

        //Клики
        if (cliiiiick(0))
        {
            drawKoleso1 = !drawKoleso1;
            txSleep(200);
        }



         if (cliiiiick(200))
           {
             drawKoleso3 = !drawKoleso3;
             txSleep(200);
           }

        if (drawKoleso1)
        {
            Win32::TransparentBlt (txDC(),900,20,200,200,koleso1,0,0,634,634, TX_WHITE);
            Win32::TransparentBlt (txDC(),900,240,200,200,koleso2,0,0,430,429, TX_WHITE);
        }


        if (drawKoleso3)
            txBitBlt(txDC() , 0, 400, 200, 200, koleso3);


         txSleep (1.5);
         txEnd ();
    }


        Win32::TransparentBlt (txDC(),196,140,200,100,car0,0,0,196,140, TX_WHITE);

  return 0;
}
