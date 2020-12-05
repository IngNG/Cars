/// \file Files.cpp
#include "TXLib.h"
#include "Picture.cpp"

///Чтение списка файлов из папки
int readFiles(const char* address, Picture* aPictures, int N)
{
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (address)) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            string s = ent->d_name;
            s = address + s;
            if(s.find (".bmp") != -1 )
            {
                aPictures[N] = {100, 100, s};
                N = N + 1;
            }
         }
        closedir (dir);
     }

     return N;
}

///Поиск картинок
///\param aPictures Массив картинок
///\return N_PICS КОличество картинок
int fillPictures(Picture* aPictures)
{
    int N_PICS = 0;
    N_PICS = readFiles("pic/Cars/", aPictures, N_PICS);
    N_PICS = readFiles("pic/Gun/", aPictures, N_PICS);
    N_PICS = readFiles("pic/Wheels/", aPictures, N_PICS);
    N_PICS = readFiles("pic/Wheels2/", aPictures, N_PICS);
    N_PICS = readFiles("pic/SideS/", aPictures, N_PICS);

    ///Расчет ширины, высоты, загрузка картинок
    for (int z = 0; z < N_PICS; z = z + 1)
    {
        string address = aPictures[z].address;//"pic/wheels/continetal.bmp";
        int pos1 = address.find("/",1);
        int pos2 = address.find("/",pos1 + 1);
        int pos3 = address.find(".",pos2 + 1);

        ///Категория
        aPictures[z].btn = address.substr(pos1 + 1, pos2-pos1-1);
        ///модель
        aPictures[z].btn2 = address.substr(pos2 + 1, pos3-pos2-1);

        aPictures[z].image = txLoadImage(aPictures[z].address.c_str());
        aPictures[z].height = getHeight(aPictures[z].address.c_str());
        aPictures[z].width = getWidth(aPictures[z].address.c_str());
        aPictures[z].heightPic = getHeight(aPictures[z].address.c_str());
        aPictures[z].widthPic = getWidth(aPictures[z].address.c_str());

        if (aPictures[z].btn == "Cars")
        {
            aPictures[z].x = 150;
            aPictures[z].y = 400;
        }

           if (aPictures[z].btn == "Wheels")
        {
            aPictures[z].x = 200;
            aPictures[z].y = 500;
        }
           if (aPictures[z].btn == "Wheels2")
        {
            aPictures[z].x = 700;
            aPictures[z].y = 500;
        }
            if (aPictures[z].btn == "SideS")
        {
            aPictures[z].x = 400;
            aPictures[z].y = 500;
        }
    }

    return N_PICS;
}
