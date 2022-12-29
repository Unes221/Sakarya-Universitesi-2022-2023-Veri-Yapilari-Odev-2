/**
 * @file Organ.hpp
 * @description Organ yapısını ve foksuyonları tanımlar
 * @course 2_B
 * @assignment 2
 * @date 14.12.2022
 * @author Enes_IŞIK enes.isik2@ogr.sakarya.edu.tr
 */
#include "Organ.hpp"

Organ::Organ()
{
    index = 0;
    sira = 0;
    agac = new AramaAgaci();
}
Organ::~Organ()
{
    delete agac;
}
void Organ::mutasyon()
{
    PostOrder(agac->ilk);
    agac->max = 0;
    for (int i = 0; i < 20; i++)
    {
        dokular[i]->sag = dokular[i]->sol = 0;
        dokular[i]->yukseklik = 0;
        dokular[i]->mutasyon();
    }
    agacyap();
}
void Organ::agacyap()
{
    agac->ilk = dokular[0];

    for (int i = 1; i < 20; i++)
    {
        agac->ekle(dokular[i], agac->ilk);
    }
}
void Organ::ekle(Doku *ek)
{
    dokular[index] = ek;
    index++;
}

void Organ::PostOrder(Doku *yer)
{
    if(yer)
    {
        PostOrder(yer->sol);
        PostOrder(yer->sag);
        dokular[sira] = yer;
        sira++;
    }
}