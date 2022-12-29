/*
* @file Dosya.cpp
* @description Dosya Okuma Isleminin Tanimi
* @course 2/B
* @assignment Odev 1
* @date 15.11.2022
* @author Enes IŞIK  enes.isik2@ogr.sakarya.edu.tr
*/
#include "Dosya.hpp"
#include "SatirListesi.hpp"
#include "YoneticiListesi.hpp"
Dosya::Dosya()
{
}
Dosya::~Dosya()
{
}
YoneticiListesi *Dosya::Dosya_oku()
{
    YoneticiListesi *yeniYontetici = new YoneticiListesi();
    ifstream dosya1("veriler.txt");
    if (dosya1.is_open())
    {
        int sayi;
        string satir;
        while (getline(dosya1, satir))
        {
            stringstream ahmet(satir);
            SatirListesi *yeniSatir = new SatirListesi();
            while (ahmet >> sayi)
            {
                yeniSatir->DugumEkle(sayi);
            }
            yeniYontetici->SatirEkle(yeniSatir);
        }
    }
    return yeniYontetici;
}