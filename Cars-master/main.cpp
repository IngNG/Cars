#include "TXLib.h"

int main() //interesting fact you gay
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
    txRectangle(0, 0, 200, 100);
    txDrawText (0, 0, 200, 100, "Wheels");
    txRectangle(200, 0, 400, 100);
    txDrawText (200, 0, 400, 100, "Engine");
    txRectangle(400, 0, 600, 100);
    txDrawText (400, 0, 600, 100, "Hood");
    txRectangle(600, 0, 800, 100);
    txDrawText (600, 0, 800, 100, "Roof");
    Win32::TransparentBlt (txDC(),900,20,200,200,koleso1,0,0,634,634, TX_WHITE);
    Win32::TransparentBlt (txDC(),900,240,200,200,koleso2,0,0,430,429, TX_WHITE);
    Win32::TransparentBlt (txDC(),900,480,200,200,koleso3,0,0,900,900, TX_WHITE);
    Win32::TransparentBlt (txDC(),300,300,200,200,koleso1,0,0,634,634, TX_WHITE);

    if (txMouseButtons() == 1 &&
        txMouseX() >= 200 &&
        txMouseX() <= 400 &&
        txMouseY() >= 0 &&
        txMouseY() <= 100)
       {
         drawKoleso1 = true;
       }

     if (drawKoleso1)
         txBitBlt(txDC() , 0, 400, 200, 200, koleso1);

     if (txMouseButtons() == 1 &&
        txMouseX() >= 200 &&
        txMouseX() <= 400 &&
        txMouseY() >= 0 &&
        txMouseY() <= 100)
       {
         drawKoleso2 = true;
       }

      if (drawKoleso2)
         txBitBlt(txDC() , 0, 400, 200, 200, koleso2);

     if (txMouseButtons() == 1 &&
        txMouseX() >= 200 &&
        txMouseX() <= 400 &&
        txMouseY() >= 0 &&
        txMouseY() <= 100)
       {
         drawKoleso3 = true;
       }

      if (drawKoleso3)
         txBitBlt(txDC() , 0, 400, 200, 200, koleso3);

     if (txMouseButtons() == 1 &&
        txMouseX() >= 200 &&
        txMouseX() <= 400 &&
        txMouseY() >= 0 &&
        txMouseY() <= 100)
       {
         drawCar0 = true;
       }

       if (drawCar0)
         txBitBlt(txDC() , 0, 400, 200, 200, car0);


     if (txMouseButtons() == 1 &&
        txMouseX() >= 200 &&
        txMouseX() <= 400 &&
        txMouseY() >= 0 &&
        txMouseY() <= 100)
       {
         drawCar1 = true;
       }


       if (drawCar1)
         txBitBlt(txDC() , 0, 400, 200, 200, car1);


     if (txMouseButtons() == 1 &&
        txMouseX() >= 200 &&
        txMouseX() <= 400 &&
        txMouseY() >= 0 &&
        txMouseY() <= 100)
       {
         drawCar2 = true;
       }

      if (drawCar2)
         txBitBlt(txDC() , 0, 400, 200, 200, car2);

     if (txMouseButtons() == 1 &&
        txMouseX() >= 200 &&
        txMouseX() <= 400 &&
        txMouseY() >= 0 &&
        txMouseY() <= 100)
       {
         drawCar3 = true;
       }

       if (drawCar3)
         txBitBlt(txDC() , 0, 400, 200, 200, car3);

    if (txMouseButtons() == 1 &&
        txMouseX() >= 200 &&
        txMouseX() <= 400 &&
        txMouseY() >= 0 &&
        txMouseY() <= 100)
       {
         drawCar4 = true;
       }

       if (drawCar4)
         txBitBlt(txDC() , 0, 400, 200, 200, car4);

     if (txMouseButtons() == 1 &&
        txMouseX() >= 200 &&
        txMouseX() <= 400 &&
        txMouseY() >= 0 &&
        txMouseY() <= 100)
       {
         drawCar5 = true;
       }

      if (drawCar5)
         txBitBlt(txDC() , 0, 400, 200, 200, car5);

     if (txMouseButtons() == 1 &&
        txMouseX() >= 200 &&
        txMouseX() <= 400 &&
        txMouseY() >= 0 &&
        txMouseY() <= 100)
       {
         drawCar6 = true;
       }

       if (drawCar6)
         txBitBlt(txDC() , 0, 400, 200, 200, car6);


     if (txMouseButtons() == 1 &&
        txMouseX() >= 200 &&
        txMouseX() <= 400 &&
        txMouseY() >= 0 &&
        txMouseY() <= 100)
       {
         drawCar7 = true;
       }

       if (drawCar7)
         txBitBlt(txDC() , 0, 400, 200, 200,car7);


     txSleep (1.5);
     txEnd ();
    }


        Win32::TransparentBlt (txDC(),196,140,200,100,car0,0,0,196,140, TX_WHITE);

  return 0;
}
