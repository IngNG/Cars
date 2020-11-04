#include "TXLib.h"
#include <stdlib.h>
#include <iostream>
#include <fstream> // подключаем библиотеку
using namespace std;

//Можно и библиотеки создать под них
struct Button2
{
    const char* text;
    int n_pic;
    int x;
    int y;

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
    const char* text;
    int n_vars;
    Button2 variants[10];
    int x;
    int y;
    bool pressed;

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
    const char* address;
    HDC image;
    int width;
    int height;
    bool visible;
    const char* btn;
    const char* btn2;
};

void drawPicture(Picture pct)
{
    Win32::TransparentBlt(txDC(), pct.x, pct.y, pct.width, pct.height, pct.image, 0, 0, pct.width, pct.height, TX_WHITE);
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

int main()
{
    txCreateWindow(1200,720);

    int N_PICS = 10;
    Picture aPictures[N_PICS];
    //Кузова
    //Как насчет некого стандарта размеров и положения деталей?
    //Машины 800 шириной, колеса 100 шириной, бампер...
    aPictures[0] = {100, 400, "pic/Cars/Jeep Wrangler.bmp"};
    aPictures[1] = {100, 400, "pic/Cars/red car.bmp"      };
    aPictures[2] = {100, 400, "pic/Cars/Audi R8.bmp"      };
    aPictures[3] = {100, 400, "pic/Cars/Lamborghini.bmp"  };
    aPictures[4] = {100, 400, "pic/Cars/lg.bmp"           };

    //Колеса
    aPictures[5] = {150, 600, "pic/Wheels/volkte37.bmp"   };
    aPictures[6] = {150, 600, "pic/Wheels/Continental.bmp"};
    aPictures[7] = {150, 600, "pic/Wheels/bbs.bmp"        };
    aPictures[8] = {150, 600, "pic/Wheels/Hankook.bmp"    };
    aPictures[9] = {150, 600, "pic/Wheels/GoodYear.bmp"   };
    int nomer = -100;

    //Расчет ширины, высоты, загрузка картинок
    for (int z = 0; z < N_PICS; z = z + 1)
    {
        string address = aPictures[z].address;//"pic/wheels/continetal.bmp";
        int pos1 = address.find("/",1);
        int pos2 = address.find("/",pos1 + 1);
        int pos3 = address.find(".",pos2 + 1);
        cout << address.substr(0,pos1) <<endl;
        cout << address.substr(pos1 + 1, pos2-pos1-1)<<endl;
        cout << address.substr(pos2 + 1, pos3-pos2-1)<<endl;
        //aPictures[z].btn=...
        txSleep(100);

        aPictures[z].image = txLoadImage(aPictures[z].address);
        aPictures[z].height = getHeight(aPictures[z].address);
        aPictures[z].width = getWidth(aPictures[z].address);

        //Можно и координаты здесь же считать (если категорию добавить)
    }
//https://github.com/IngCenter/PixelCars
    int N_BTN = 6;
    Button btn[N_BTN];
    btn[0] = {  "колёса",  5,
                   {{ "колесо1" , 5},
                    { "Continental", 6},//И нет, я не просто так их переименовал
                    { "колесо3" , 7},
                    { "Hankook" , 8},
                    { "GoodYear", 9}}};
    //Когда уже остальные кнопки активируете?
    btn[1] = { "БАМПЕР ЗАД",  5,
                   {{ "лпмеуп1", 0},
                    { "лпмеуп2", 1},
                    { "лпмеуп3", 2},
                    { "лпмеуп4", 3},
                    { "лпмеуп5", 4}}};
    btn[2] = { "БАМПЕР ПЕР",  5,
                   {{ "лпмеуп1", 0},
                    { "лпмеуп2", 1},
                    { "лпмеуп3", 2},
                    { "лпмеуп4", 3},
                    { "лпмеуп5", 4}}};
    btn[3] = { "КОЛЁСА",      5,
                   {{ "лпмеуп1", 0},
                    { "лпмеуп2", 1},
                    { "лпмеуп3", 2},
                    { "лпмеуп4", 3},
                    { "лпмеуп5", 4}}};
    btn[4] = { "ШИПЫ",        5,
                   {{ "шипы1"  , 0},
                    { "шипы2"  , 1},
                    { "шипы3"  , 2},
                    { "шипы4"  , 3},
                    { "шипы5"  , 4}}};
    btn[5] = { "Кузов",       5,
                   {{ "Кузов1" , 0},          //!80 110 140 170
                    { "Кузов2" , 1},
                    { "Кузов3" , 2},
                    { "кузов4" , 3},
                    { "кузов5" , 4}}};

    //Координаты кнопок
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

    //Сам редактор
    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin ();
        txClear();

        //Кнопки рисуются
        txSetColour(TX_BLACK);
        for (int i = 0; i < N_BTN; i = i + 1)
            btn[i].draw();

        //Клик на кнопки
        for (int i = 0; i < N_BTN; i = i + 1)
        {
            //А как насчет деактивировать все остальные кнопки?
            if (btn[i].cliiiiick())
            {
                btn[i].pressed = !btn[i].pressed;
                txSleep(200);
            }
        }

        //Нажаты колеса
        for (int z = 0; z < N_BTN; z = z + 1)
        {
            if (btn[z].pressed)
            {
                //Фокусировка на варианты
                for (int i = 0; i < btn[0].n_vars; i = i + 1)
                {
                    if (btn[z].variants[i].focus())
                    {
                        int n = btn[z].variants[i].n_pic;
                        //А если учитывать пропорции?
                        Win32::TransparentBlt (txDC(),200,100,200,200,aPictures[n].image,0,0,aPictures[n].width,aPictures[n].height, TX_WHITE);
                    }
                }

                //Клик на варианты
                for (int i=0; i < btn[z].n_vars; i=i+1)
                {
                    if (btn[z].variants[i].cliiiick())
                    {
                        int n = btn[z].variants[i].n_pic;

                        //А как насчет деактивировать все остальные кузова, если кузов выбран?
                        aPictures[n].visible = !aPictures[n].visible;
                        txSleep(200);
                    }

                }

                //Рисование вариантов
                for (int i = 0; i < btn[z].n_vars; i = i + 1)
                    btn[z].variants[i].draw();
            }
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
        //У них вот прям такая ширина? 200?
            txMouseX() >= aPictures[i].x       &&  txMouseY() >= aPictures[i].y       &&
            txMouseX() <= aPictures[i].x + 200 &&  txMouseY() <= aPictures[i].y + 200 &&
            aPictures[i].visible)
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
    //Картинки можно и удалить
    return 0;
}
