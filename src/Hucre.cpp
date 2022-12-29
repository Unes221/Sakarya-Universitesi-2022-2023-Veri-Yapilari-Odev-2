/**
* @file Hucre.hpp
* @description Hucre yapısını ve foksuyonları tanımlar
* @course 2_B
* @assignment 2
* @date 14.12.2022
* @author Enes_IŞIK enes.isik2@ogr.sakarya.edu.tr
*/
#include "Hucre.hpp"

Hucre::Hucre(int dna)
{
    this->dna =dna;
    sonraki=0;
}
Hucre::~Hucre()
{
}
void Hucre::mutasyon()
{
    if(dna%2==0)
    {
       dna=dna/2;
    }
}