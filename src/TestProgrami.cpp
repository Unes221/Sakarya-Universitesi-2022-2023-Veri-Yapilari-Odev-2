/**
* @file Test_Programı.hpp
* @description Test Programı tanımlar
* @course 2_B
* @assignment 2
* @date 14.12.2022
* @author Enes_IŞIK enes.isik2@ogr.sakarya.edu.tr
*/
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h> 
#include "Kontrol.hpp"
using namespace std;
int main()
{
    
    Kontrol* dentleyici= new Kontrol();
    dentleyici->DosyaOku();
    system("cls");
    cout<<"                    ORGANIZMA"<<endl;
    dentleyici->varlik->yazdir();
    int karakter=getch();
    if(karakter==13)
    {
    dentleyici->varlik->mutasyon();
    system("cls");
    cout<<"                  ORGANIZMA(MUTASYONA UGRADI)"<<endl;
    dentleyici->varlik->yazdir();
    }
    delete dentleyici;

}
