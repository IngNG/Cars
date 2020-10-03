#include "TXLib.h"

struct Button
{
    int x;
    int y;
    const char* text;

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
};

void drawPicture(Picture pct)
{
    Win32::TransparentBlt(txDC(), pct.x, pct.y, 100, 100, pct.image, 0, 0, pct.width, pct.height, TX_WHITE);
}

int main()
{
    txCreateWindow(1200,720);


    Picture aPictures[10];
    aPictures[0] = {900, 200, 634, 634, txLoadImage("pic/volkte37.bmp")};
    aPictures[1] = {900, 400, 430, 429, txLoadImage("pic/kakietodiski.bmp")};
    aPictures[2] = {900, 600, 900, 900, txLoadImage("pic/bbs.bmp")};


    Button btn1 = {0,    0, "ÊÐÛØÀ"};
    Button btn2 = {200,  0, "ÁÀÌÏÅÐ ÇÀÄ"};
    Button btn3 = {400,  0, "ÁÀÌÏÅÐ ÏÅÐ"};
    Button btn4 = {600,  0, "ÊÎË¨ÑÀ"};
    Button btn5 = {800,  0, "ØÈÏÛ"};
    Button btn6 = {1000, 0, "ÏÏÏÏÏÏÏÏÏÏ"};


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
        btn1.draw();
        btn2.draw();
        btn3.draw();
        btn4.draw();
        btn5.draw();
        btn6.draw();

        //Íîïêè
        //drawButton(0,   "WHEELS");
        //drawButton(200, "ENGINE");
        //drawButton(400, "HOOD"  );
        //drawButton(600, "ROOF"  );



        //Êàðòèíêè
        //Win32::TransparentBlt (txDC(),900,20,200,200,koleso1,0,0,634,634, TX_WHITE);
        //Win32::TransparentBlt (txDC(),900,240,200,200,koleso2,0,0,430,429, TX_WHITE);
        //Win32::TransparentBlt (txDC(),900,480,200,200,koleso3,0,0,900,900, TX_WHITE);
        //Win32::TransparentBlt (txDC(),300,300,200,200,koleso1,0,0,634,634, TX_WHITE);

        //Êëèêè
        if (btn1.cliiiiick())
        {
            //TABLICA
            drawKoleso1 = !drawKoleso1;
            txSleep(200);
        }



        if (drawKoleso1)
        {
            drawPicture(aPictures[0]);
            //drawPicture(aPictures[1]);
            //drawPicture(aPictures[2]);
        }


         txSleep (1.5);
         txEnd ();
    }


        Win32::TransparentBlt (txDC(),196,140,200,100,car0,0,0,196,140, TX_WHITE);

  return 0;
}
