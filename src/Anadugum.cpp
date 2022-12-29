/*
* @file Anadugum.cpp
* @description Yonetici Listesi Dugumu Tanimi
* @course 2/B
* @assignment Odev 1
* @date 9.11.2022
* @author Enes IŞIK  enes.isik2@ogr.sakarya.edu.tr
*/

#include "Anadugum.hpp"

Anadugum::Anadugum(SatirListesi *liste)
{
    this->liste = liste;
    this->ort = liste->ortalama();
    onceki = sonraki = 0;
}
Anadugum::~Anadugum()
{
}
