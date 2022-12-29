/**
 * @file İkili_Arama_Ağacı.hpp
 * @description İkili Arama Ağacı yapısını ve foksuyonları tanımlar
 * @course 2_B
 * @assignment 2
 * @date 14.12.2022
 * @author Enes_IŞIK enes.isik2@ogr.sakarya.edu.tr
 */
#include "Doku.hpp"
#include "AramaAgaci.hpp"

AramaAgaci::AramaAgaci()
{
    ilk = 0;
    max = 0;
}
AramaAgaci::~AramaAgaci()
{
    yoket(ilk);
}
void AramaAgaci::ekle(Doku *veri, Doku *yer)
{
    if (yer->ort >= veri->ort)
    {
        if (yer->sol)
        {
            ekle(veri, yer->sol);
        }
        else
        {
            yer->sol = veri;
            veri->yukseklik = yer->yukseklik + 1;
        }
    }
    else
    {
        if (yer->sag)
        {
            ekle(veri, yer->sag);
        }
        else
        {
            yer->sag = veri;
            veri->yukseklik = yer->yukseklik + 1;
        }
    }
    if (max < veri->yukseklik)
    {
        max = veri->yukseklik;
    }
}

void AramaAgaci::yoket(Doku *yer)
{
    if (yer!=0)
    {
        yoket(yer->sag);
        yoket(yer->sol);
        delete yer;
    }
}

