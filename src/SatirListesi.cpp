/*
* @file SatirListesi.cpp
* @description Satir Listesi  Fonksiyonların Tanimi
* @course 2/B
* @assignment Odev 1
* @date 9.11.2022
* @author Enes IŞIK  enes.isik2@ogr.sakarya.edu.tr
*/
#include "SatirListesi.hpp"

SatirListesi::SatirListesi()
{
    ilk = son = 0;
}
SatirListesi::~SatirListesi()
{
    Dugum *gezici = ilk;
    while (gezici != 0)
    {
        Dugum *yoket = gezici;
        gezici = gezici->sonraki;
        delete yoket;
    }
}
void SatirListesi::DugumEkle(int veri)
{
    Dugum *yeni = new Dugum(veri);
    if (ilk == 0)
    {
        ilk = yeni;
        son = yeni;
        yeni->onceki = 0;
        yeni->sonraki = 0;
    }
    else
    {
        son->sonraki = yeni;
        yeni->onceki = son;
        yeni->sonraki = 0;
        son = yeni;
    }
}
double SatirListesi::ortalama()
{
    if (ilk == 0)
    {
        return 0;
    }
    else
    {
        Dugum *gezici = ilk;
        int sayac = 0;
        double toplam = 0;
        double don;
        while (gezici != 0)
        {
            sayac++;
            toplam = toplam + gezici->veri;
            gezici = gezici->sonraki;
        }
        don = toplam / sayac;
        return don;
    }
}
Dugum *SatirListesi::getir()
{
    if (ilk == 0)
    {
        return 0;
    }
    else
    {
        Dugum *gezici = ilk;
        int sayac = 0;
        while (gezici != 0)
        {
            sayac++;
            gezici = gezici->sonraki;
        }
        gezici = ilk;
        srand(time(NULL));
        for (int i = 0; i < rand() % sayac; i++)
        {
            gezici = gezici->sonraki;
        }
        return gezici;
    }
}
void SatirListesi::DugumSil(Dugum *yer)
{
    if (yer->onceki == 0 && yer->sonraki == 0)
    {
        ilk = 0;
        son = 0;
        delete yer;
    }
    else
    {
        if (yer->onceki == 0)
        {
            yer->sonraki->onceki = 0;
            ilk = yer->sonraki;
            delete yer;
        }
        else if (yer->sonraki == 0)
        {
            yer->onceki->sonraki = 0;
            son = yer->onceki;
            delete yer;
        }
        else
        {
            yer->onceki->sonraki = yer->sonraki;
            yer->sonraki->onceki = yer->onceki;
            delete yer;
        }
    }
}
void SatirListesi::Yazdir(int aralik)
{
    Dugum *gezici = ilk;
    cout << endl
         << setiosflags(ios::left) << setw(aralik) << ""
         << "^^^^^^^^^^" << endl
         << endl;
    while (gezici != 0)
    {
        cout << setiosflags(ios::left) << setw(aralik) << "" << setw(1) << "" << setw(10) << gezici << endl
             << setiosflags(ios::left) << setw(aralik) << ""
             << "----------" << endl
             << setiosflags(ios::left) << setw(aralik) << ""
             << "|" << setw(8) << gezici->veri << setw(4) << "|" << endl
             << setiosflags(ios::left) << setw(aralik) << ""
             << "----------" << endl;
        if (gezici->sonraki == 0)
        {
            cout << setiosflags(ios::left) << setw(aralik) << ""
                 << "|00000000|" << endl
                 << setiosflags(ios::left) << setw(aralik) << ""
                 << "----------" << endl
                 << endl;
        }
        else
        {
            cout << setiosflags(ios::left) << setw(aralik) << ""
                 << "|" << gezici->sonraki << "|" << endl
                 << setiosflags(ios::left) << setw(aralik) << ""
                 << "----------" << endl
                 << endl;
        }

        gezici = gezici->sonraki;
    }
}
void SatirListesi::Yazdir(int aralik, Dugum *isaret)
{
    Dugum *gezici = ilk;
    cout << endl
         << setiosflags(ios::left) << setw(aralik) << ""
         << "^^^^^^^^^^" << endl
         << endl;
    while (gezici != 0)
    {
        if (gezici == isaret)
        {
            cout << setiosflags(ios::left) << setw(aralik) << "" << setw(1) << "" << setw(10) << gezici << endl
                 << setiosflags(ios::left) << setw(aralik) << ""
                 << "----------" << endl
                 << setiosflags(ios::left) << setw(aralik) << ""
                 << "|" << setw(8) << gezici->veri << setw(4) << "|" << endl
                 << setiosflags(ios::left) << setw(aralik) << ""
                 << "----------  <---- silinecek secili" << endl;
            if (gezici->sonraki == 0)
            {
                cout << setiosflags(ios::left) << setw(aralik) << ""
                     << "|00000000|" << endl
                     << setiosflags(ios::left) << setw(aralik) << ""
                     << "----------" << endl
                     << endl;
            }
            else
            {
                cout << setiosflags(ios::left) << setw(aralik) << ""
                     << "|" << gezici->sonraki << "|" << endl
                     << setiosflags(ios::left) << setw(aralik) << ""
                     << "----------" << endl
                     << endl;
            }
        }
        else
        {

            cout << setiosflags(ios::left) << setw(aralik) << "" << setw(1) << "" << setw(10) << gezici << endl
                 << setiosflags(ios::left) << setw(aralik) << ""
                 << "----------" << endl
                 << setiosflags(ios::left) << setw(aralik) << ""
                 << "|" << setw(8) << gezici->veri << setw(4) << "|" << endl
                 << setiosflags(ios::left) << setw(aralik) << ""
                 << "----------" << endl;
            if (gezici->sonraki == 0)
            {
                cout << setiosflags(ios::left) << setw(aralik) << ""
                     << "|00000000|" << endl
                     << setiosflags(ios::left) << setw(aralik) << ""
                     << "----------" << endl
                     << endl;
            }
            else
            {
                cout << setiosflags(ios::left) << setw(aralik) << ""
                     << "|" << gezici->sonraki << "|" << endl
                     << setiosflags(ios::left) << setw(aralik) << ""
                     << "----------" << endl
                     << endl;
            }
        }
        gezici = gezici->sonraki;
    }
}