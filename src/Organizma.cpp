/**
* @file Organizma.hpp
* @description Organizma yapısını ve foksuyonları tanımlar
* @course 2_B
* @assignment 2
* @date 14.12.2022
* @author Enes_IŞIK enes.isik2@ogr.sakarya.edu.tr
*/
#include "Organizma.hpp"

Organizma::Organizma()
{
    liste=new Bagli();
}
Organizma::~Organizma()
{
    delete liste; 
}
void Organizma::ekle(Sistem* ek)
{
    liste->ekle(ek);
}
void Organizma::yazdir()
{
    Sistem* gezici=liste->ilk;
    while (gezici!=0)
    {
        gezici->yazdir();
        gezici=gezici->sonraki; 
          cout<<endl;
    }
   
}
void Organizma::mutasyon()
{
    Sistem* gezici=liste->ilk;
    while (gezici!=0)
    {
        gezici->mutasyon();
        gezici=gezici->sonraki;
    }
   
}