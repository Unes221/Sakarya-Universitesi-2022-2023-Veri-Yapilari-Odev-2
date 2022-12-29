/*
* @file Dugum.cpp
* @description Satir Listesi Dugumu Tanimi
* @course 2/B
* @assignment Odev 1
* @date 9.11.2022
* @author Enes IŞIK  enes.isik2@ogr.sakarya.edu.tr
*/
#include "Dugum.hpp"

Dugum::Dugum(int veri)
{
    this->veri = veri;
    onceki = sonraki = 0;
}
Dugum::~Dugum()
{
}