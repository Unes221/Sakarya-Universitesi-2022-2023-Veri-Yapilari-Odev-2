/**
* @file Bagli.hpp
* @description Bagli liste yapısını ve foksuyonları tanımlar
* @course 2_B
* @assignment 2
* @date 14.12.2022
* @author Enes_IŞIK enes.isik2@ogr.sakarya.edu.tr
*/
#include "Bagli.hpp"

Bagli::Bagli()
{
    ilk=son=0;
}
Bagli::~Bagli()
{
    Sistem* gezici=ilk;
    while (gezici!=0)
    { 
        Sistem*sil=gezici;
        gezici= gezici->sonraki;
        delete sil;
    }
    
}
void Bagli::ekle(Sistem* ek)
{
    if(ilk==0)
    {
        ilk=son=ek;
    }
    else
    {
        son->sonraki = ek;
        son = ek;
    }
}