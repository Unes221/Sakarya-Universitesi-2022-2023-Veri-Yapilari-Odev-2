/*
* @file YoneticiListesi.cpp
* @description Yonetici Listesi Fonksiyonların Tanimi
* @course 2/B
* @assignment Odev 1
* @date 9.11.2022
* @author Enes IŞIK  enes.isik2@ogr.sakarya.edu.tr
*/
#include "YoneticiListesi.hpp"

YoneticiListesi::YoneticiListesi()
{
    ilk = 0;
    son = 0;
}
YoneticiListesi::~YoneticiListesi()
{
    Anadugum *gezici = ilk;
    while (gezici != 0)
    {
        Anadugum *yoket = gezici;
        gezici = gezici->sonraki;
        delete yoket->liste;
        delete yoket;
    }
}
void YoneticiListesi::SatirEkle(SatirListesi *satir)
{

    if (satir->ortalama() != 0)
    {
        Anadugum *yeni = new Anadugum(satir);
        if (ilk == 0)
        {

            ilk = yeni;
            yeni->onceki = 0;
            yeni->sonraki = 0;
            son = yeni;
        }
        else
        {

            if (ilk->ort > yeni->ort)
            {

                ilk->onceki = yeni;
                yeni->sonraki = ilk;
                yeni->onceki = 0;
                ilk = yeni;
            }
            else
            {
                Anadugum *gezici = ilk;
                while (gezici != 0)
                {
                    if (gezici->ort > yeni->ort)
                    {
                        gezici->onceki->sonraki = yeni;
                        yeni->onceki = gezici->onceki;
                        yeni->sonraki = gezici;
                        gezici->onceki = yeni;
                        return;
                    }
                    gezici = gezici->sonraki;
                }

                yeni->sonraki = 0;
                yeni->onceki = son;
                son->sonraki = yeni;
                son = yeni;
                return;
            }
        }
    }
}
void YoneticiListesi::Sil(Anadugum *yer)
{
    Anadugum *sil = yer->onceki;
    if (yer->onceki == 0 && yer->sonraki == 0)
    {
        ilk = 0;
        son = 0;
        delete yer->liste;
        delete yer;
    }
    else if (yer->onceki == 0)
    {
        ilk = yer->sonraki;
        yer->sonraki->onceki = 0;
    }
    else if (yer->sonraki == 0)
    {
        son = yer->onceki;
        yer->onceki->sonraki = 0;
        delete yer->liste;
        delete yer;
    }
    else
    {
        yer->onceki->sonraki = yer->sonraki;
        yer->sonraki->onceki = sil;
        delete yer->liste;
        delete yer;
    }
}
void YoneticiListesi::SilDugum(Anadugum *yer)
{
    Anadugum *sil = yer->onceki;
    if (yer->onceki == 0)
    {
        ilk = yer->sonraki;
        yer->sonraki->onceki = 0;
        delete yer;
    }
    else if (yer->sonraki == 0)
    {
        son = yer->onceki;
        yer->onceki->sonraki = 0;
        delete yer;
    }
    else
    {
        yer->onceki->sonraki = yer->sonraki;
        yer->sonraki->onceki = sil;
        delete yer;
    }
}
