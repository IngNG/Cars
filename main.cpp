#include "TXLib.h"

int main()
{
    txCreateWindow(1280,720);
    txClear();
    txSetColour(TX_BLACK);

    HDC koleso1 = txLoadImage("pic/volkte37.bmp");
    HDC koleso2 = txLoadImage("pic/kakietodiski.bmp");
    HDC koleso3 = txLoadImage("pic/bbs.bmp");

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

        HDC car0 = txLoadImage ("pic/car0.bmp");
        HDC car1 = txLoadImage ("pic/car1.bmp");
        HDC car2 = txLoadImage ("car2.bmp");
        HDC car3 = txLoadImage ("car3.bmp");
        HDC car4 = txLoadImage ("car4.bmp");
        HDC car5 = txLoadImage ("car5.bmp");
        HDC car6 = txLoadImage ("car6.bmp");
        HDC car7 = txLoadImage ("car7.bmp");



        Win32::TransparentBlt (txDC(),196,140,200,100,car0,0,0,196,140, TX_WHITE);

  return 0;
}
