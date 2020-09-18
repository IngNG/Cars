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

  return 0;
}
