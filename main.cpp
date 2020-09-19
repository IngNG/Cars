#include "TXLib.h"

int main()
{
    txCreateWindow(1280,720);
    txClear();
    txSetColour(TX_BLACK);

    txRectangle(0, 0, 200, 100);
    txDrawText (0, 0, 200, 100, "kolesa");
    txRectangle(200, 0, 400, 100);
    txDrawText (200, 0, 400, 100, "motor");
    txRectangle(400, 0, 600, 100);
    txDrawText (400, 0, 600, 100, "kapot");
    txRectangle(600, 0, 800, 100);
    txDrawText (600, 0, 800, 100, "krisha");
    txRectangle(1000, 0, 800, 100);
    txDrawText (800, 0, 1000, 100, "Machina");




        HDC car0 = txLoadImage ("car0.bmp");
        HDC car1 = txLoadImage ("car1.bmp");
        HDC car2 = txLoadImage ("car2.bmp");
        HDC car3 = txLoadImage ("car3.bmp");
        HDC car4 = txLoadImage ("car4.bmp");
        HDC car5 = txLoadImage ("car5.bmp");
        HDC car6 = txLoadImage ("car6.bmp");
        HDC car7 = txLoadImage ("car7.bmp");



        Win32::TransparentBlt (txDC(),196,140,200,100,car0,0,0,196,140, TX_WHITE);

        //Win32::TransparentBlt (txDC(),600,240,200,100,car1,0,0,615,369, TX_WHITE);
        //if (drawcar2)
        //Win32::TransparentBlt (txDC(),325,250,200,100,car2,0,0,615,369, TX_WHITE);
        //if (drawcar3)
        //Win32::TransparentBlt (txDC(),325,250,200,100,car3,0,0,615,369, TX_WHITE);
        //if (drawcar4)
       // Win32::TransparentBlt (txDC(),325,250,200,100,car4,0,0,615,369, TX_WHITE);
        //if (drawcar5)
        //Win32::TransparentBlt (txDC(),325,250,200,100,car5,0,0,615,369, TX_WHITE);
        //if (drawcar6)
       // Win32::TransparentBlt (txDC(),325,250,200,100,car6,0,0,615,369, TX_WHITE);

  return 0;
}
