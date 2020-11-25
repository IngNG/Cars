#include "TXLib.h"
#include <stdlib.h>
#include <iostream>
#include <fstream> // подключаем библиотеку
using namespace std;


int main()
{
    txCreateWindow(1200,720);

    const char* typeFile = "";

    try

    {
        OPENFILENAME sfn;
        ZeroMemory( &sfn , sizeof( sfn));
        sfn.lStructSize = sizeof ( sfn );
        sfn.hwndOwner = NULL ;
        wchar_t w_syFile[MAX_PATH];

        //TypeFile
        sfn.lpstrFilter = TEXT("Microsoft Office Word Documents (*.xlsx)\0*.XLSX\0");

        sfn.nFilterIndex =1;
        sfn.lpstrFileTitle = NULL ;
        sfn.nMaxFileTitle = 0 ;
        sfn.lpstrInitialDir=NULL;

        //sfn.Flags = OFN_PATHMUSTEXIST | OFN_OVERWRITEPROMPT|OFN_EXPLORER | OFN_ENABLEHOOK ;
        sfn.Flags = OFN_PATHMUSTEXIST|OFN_FILEMUSTEXIST|OFN_NOVALIDATE|OFN_HIDEREADONLY  ;
        if (GetOpenFileName( &sfn ) != TRUE)
        {
                //sfn.lpstrfile;
        }


    }
            catch (...)
            {

            }


    return 0;
}
