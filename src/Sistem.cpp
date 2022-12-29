/**
 * @file Sistem.hpp
 * @description Sistem yapısını ve foksuyonları tanımlar
 * @course 2_B
 * @assignment 2
 * @date 14.12.2022
 * @author Enes_IŞIK enes.isik2@ogr.sakarya.edu.tr
 */

#include "Sistem.hpp"

Sistem::Sistem()
{
    index = 0;
    sonraki = 0;
}
Sistem::~Sistem()
{
    for (int i = 0; i < 100; i++)
    {
        delete organlar[i];
    }
}
void Sistem::yazdir()
{
    for (int i = 0; i < 100; i++)
    {
        if (organlar[i]->agac->max > 4)
        {
            cout << "#";
        }
        else
        {
            cout << " ";
        }
    }
}
void Sistem::ekle(Organ *ek)
{
    organlar[index] = ek;
    index++;
}
void Sistem::mutasyon()
{
    for (int i = 0; i < 100; i++)
    {
        if (organlar[i]->agac->ilk->ort % 50 == 0)
        {
            organlar[i]->mutasyon();
        }
    }
}