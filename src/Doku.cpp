/**
* @file Doku.hpp
* @description Doku yapısını ve foksuyonları tanımlar
* @course 2_B
* @assignment 2
* @date 14.12.2022
* @author Enes_IŞIK enes.isik2@ogr.sakarya.edu.tr
*/
#include "Doku.hpp"

Doku::Doku(Queue*liste)
{
    this->liste=liste;
    sag=sol=0;
    yukseklik=0;
    ort=liste->ortanca();
}

Doku::~Doku()
{
    delete liste;
}
void Doku::mutasyon(){
    Hucre*gezici=liste->ilk;
   while (gezici!=0)
    {
        gezici->mutasyon();
        gezici=gezici->sonraki;
    }
    Radix*rad=new Radix(liste);
    rad->sirala(liste);
    delete rad;
    ort=liste->ortanca();
    
}