/*
* @file Ekran.cpp
* @description Liste Yazdirma ve Duzenleme Fonksiyonlarin Tanimi
* @course 2/B
* @assignment Odev 1
* @date 16.11.2022
* @author Enes IŞIK  enes.isik2@ogr.sakarya.edu.tr
*/
#include "Ekran.hpp"
#include "YoneticiListesi.hpp"
#include "Dosya.hpp"

Ekran::Ekran(YoneticiListesi *analiste)
{
    yonetici = analiste;
    c = 0, k = 0;
    satiryazilacak = analiste->ilk;
    yazilacak = analiste->ilk;
    silinecek = 0;
}
Ekran::~Ekran()
{
}
void Ekran::EkranKomut(char emir)
{
    if (emir == 'c')
    {
        if (satiryazilacak->sonraki != 0 && c < 8)
        {
            satiryazilacak = satiryazilacak->sonraki;
            c++;
        }
        if (c == 8)
        {
            c = 0;
            Anadugum *denetle = yazilacak;
            bool gec = true;
            for (int i = 0; i < 8; i++)
            {
                if (denetle->sonraki == 0)
                {
                    gec = false;
                    break;
                }
                denetle = denetle->sonraki;
            }
            if (gec)
            {
                for (int i = 0; i < 8; i++)
                {
                    yazilacak = yazilacak->sonraki;
                }
            }
        }
    }
    else if (emir == 'z')
    {
        if (satiryazilacak->onceki != 0 && c >= 0)
        {
            satiryazilacak = satiryazilacak->onceki;
            c--;
        }
        if (c == -1)
        {
            c = 7;
            Anadugum *denetle = yazilacak;
            bool gec = true;
            for (int i = 0; i < 8; i++)
            {
                if (denetle == 0)
                {
                    gec = false;
                    break;
                }
                denetle = denetle->onceki;
            }
            if (gec)
            {
                for (int i = 0; i < 8; i++)
                {
                    yazilacak = yazilacak->onceki;
                }
            }
        }
    }
    else if (emir == 'd')
    {
        Anadugum *denetle = yazilacak;
        bool gec = true;
        for (int i = 0; i < 8; i++)
        {
            if (denetle->sonraki == 0)
            {
                gec = false;
                break;
            }
            denetle = denetle->sonraki;
        }
        if (gec)
        {
            for (int i = 0; i < 8; i++)
            {
                yazilacak = yazilacak->sonraki;
            }
            satiryazilacak = yazilacak;
            c = 0;
        }
    }
    else if (emir == 'a')
    {
        Anadugum *denetle = yazilacak;
        bool gec = true;
        for (int i = 0; i < 8; i++)
        {
            if (denetle->onceki == 0)
            {
                gec = false;
                break;
            }
            denetle = denetle->onceki;
        }
        if (gec)
        {
            for (int i = 0; i < 8; i++)
            {
                yazilacak = yazilacak->onceki;
            }
            satiryazilacak = yazilacak;
            c = 0;
        }
    }
    else if (emir == 'p')
    {
        if (yonetici->ilk != 0)
        {
            if (satiryazilacak->onceki == 0)
            {
                Anadugum *yedek = satiryazilacak->sonraki;
                yonetici->Sil(satiryazilacak);
                satiryazilacak = yedek;
                yazilacak = yedek;
            }
            else if (satiryazilacak->sonraki == 0)
            {
                Anadugum *yedek = satiryazilacak->onceki;
                yonetici->Sil(satiryazilacak);
                satiryazilacak = yedek;
                if (c > 0)
                {
                    c--;
                }
                else
                {
                    Anadugum *denetle = yazilacak;
                    bool gec = true;
                    for (int i = 0; i < 8; i++)
                    {
                        if (denetle->onceki == 0)
                        {
                            gec = false;
                            break;
                        }
                        denetle = denetle->onceki;
                    }
                    if (gec)
                    {
                        for (int i = 0; i < 8; i++)
                        {
                            yazilacak = yazilacak->onceki;
                        }
                        satiryazilacak = yazilacak;
                        c = 0;
                    }
                }
            }
            else
            {
                Anadugum *yedek = satiryazilacak->sonraki;
                yonetici->Sil(satiryazilacak);
                satiryazilacak = yedek;
            }
        }
        else if (yonetici->son == 0)
        {
            yonetici->Sil(yonetici->ilk);
        }
    }
    if (emir == 'k' && k == 0)
    {
        silinecek = satiryazilacak->liste->getir();
        k = 1;
    }
    else if (emir == 'k' && k == 1 && silinecek != 0)
    {
        if (silinecek->onceki != 0 || silinecek->sonraki != 0)
        {
            if (c == 0 && satiryazilacak->onceki != 0)
            {
                Anadugum *yedek;
                satiryazilacak->liste->DugumSil(silinecek);
                yonetici->SatirEkle(satiryazilacak->liste);
                if (satiryazilacak->liste->ortalama() > satiryazilacak->ort)
                {
                    yedek = satiryazilacak->sonraki;
                    yazilacak = yazilacak->sonraki;
                }
                else
                {
                    yedek = satiryazilacak->onceki;
                    yazilacak = yazilacak->onceki;
                }
                yonetici->SilDugum(satiryazilacak);
                satiryazilacak = yedek;
            }
            else if (satiryazilacak->sonraki == 0)
            {
                satiryazilacak->liste->DugumSil(silinecek);
                yonetici->SatirEkle(satiryazilacak->liste);
                yonetici->SilDugum(satiryazilacak);
                satiryazilacak = yonetici->son;
            }
            else if (satiryazilacak->onceki == 0)
            {
                satiryazilacak->liste->DugumSil(silinecek);
                yonetici->SatirEkle(satiryazilacak->liste);
                yonetici->SilDugum(satiryazilacak);
                satiryazilacak = yonetici->ilk;
                yazilacak = yonetici->ilk;
            }
            else
            {
                Anadugum *yedek;
                satiryazilacak->liste->DugumSil(silinecek);
                yonetici->SatirEkle(satiryazilacak->liste);
                if (satiryazilacak->liste->ortalama() > satiryazilacak->ort)
                {
                    yedek = satiryazilacak->sonraki;
                }
                else
                {
                    yedek = satiryazilacak->onceki;
                }
                yonetici->SilDugum(satiryazilacak);
                satiryazilacak = yedek;
            }
        }
        else
        {
            if (c == 0 && satiryazilacak->onceki != 0 && satiryazilacak->sonraki != 0)
            {
                Anadugum *yedek = satiryazilacak->sonraki;
                yonetici->Sil(satiryazilacak);
                satiryazilacak = yedek;
                yazilacak = yedek;
            }
            else if (c == 0 && satiryazilacak->onceki != 0 && satiryazilacak->sonraki == 0)
            {
                Anadugum *denetle = yazilacak;
                bool gec = true;
                for (int i = 0; i < 8; i++)
                {
                    if (denetle->onceki == 0)
                    {
                        gec = false;
                        break;
                    }
                    denetle = denetle->onceki;
                }
                if (gec)
                {
                    for (int i = 0; i < 8; i++)
                    {
                        yazilacak = yazilacak->onceki;
                    }
                }
                c = 7;
                yonetici->Sil(satiryazilacak);
                satiryazilacak = yonetici->son;
            }
            else if (satiryazilacak->sonraki == 0)
            {
                yonetici->Sil(satiryazilacak);
                satiryazilacak = yonetici->son;
                if (c > 0)
                {
                    c--;
                }
                else
                {
                    Anadugum *denetle = yazilacak;
                    bool gec = true;
                    for (int i = 0; i < 8; i++)
                    {
                        if (denetle->onceki == 0)
                        {
                            gec = false;
                            break;
                        }
                        denetle = denetle->onceki;
                    }
                    if (gec)
                    {
                        for (int i = 0; i < 8; i++)
                        {
                            yazilacak = yazilacak->onceki;
                        }
                        satiryazilacak = yazilacak;
                        c = 0;
                    }
                }
            }
            else if (satiryazilacak->onceki == 0)
            {
                yonetici->Sil(satiryazilacak);
                satiryazilacak = yonetici->ilk;
                yazilacak = yonetici->ilk;
            }
            else
            {
                Anadugum *yedek = satiryazilacak->sonraki;
                yonetici->Sil(satiryazilacak);
                satiryazilacak = yedek;
            }
        }
        k = 0;
    }
    else
    {
        k = 0;
    }
}
void Ekran::EkranYazdir()
{
    Anadugum *gezici = yazilacak;
    if (yonetici->ilk == 0)
    {
        cout << "Yonetici listesi bos !!!" << endl;
    }
    else
    {
        int i = 0;
        system("cls");
        for (i = 0; i < 8; i++)
        {
            if (gezici->onceki == 0)
            {
                cout << setiosflags(ios::left) << " ilk" << setw(14);
            }
            else if (i == 0)
            {
                cout << setiosflags(ios::left) << " <---" << setw(14);
            }
            if (gezici->sonraki == 0)
            {
                cout << resetiosflags(ios::left) << "son" << setw(14) << endl;
                break;
            }
            else if (i == 7)
            {
                cout << resetiosflags(ios::left) << "--->" << setw(14) << endl;
            }
            else if (i != 0)
            {
                cout << "" << setw(15);
            }
            if (gezici->sonraki != 0)
            {
                gezici = gezici->sonraki;
            }
        }
        gezici = yazilacak;
        for (i = 0; i < 8; i++)
        {
            if (gezici == 0)
            {
                cout << endl;
                break;
            }
            if (i == 7)
            {
                cout << setiosflags(ios::left) << setw(1) << "" << setw(10) << gezici << setw(3) << "" << endl;
            }
            else
            {
                cout << setiosflags(ios::left) << setw(1) << "" << setw(10) << gezici << setw(3) << "";
            }
            gezici = gezici->sonraki;
        }
        gezici = yazilacak;
        for (i = 0; i < 8; i++)
        {
            if (gezici == 0)
            {
                cout << endl;
                break;
            }
            if (i == 7)
            {
                cout << setiosflags(ios::left) << setw(14) << "------------" << endl;
            }
            else
            {
                cout << setiosflags(ios::left) << setw(14) << "------------";
            }
            gezici = gezici->sonraki;
        }
        gezici = yazilacak;
        for (i = 0; i < 8; i++)
        {
            if (gezici == 0)
            {
                cout << endl;
                break;
            }
            if (i == 7)
            {
                cout << setiosflags(ios::left) << setw(1) << "|" << setw(10) << gezici->onceki << setw(3) << "|" << endl;
            }
            else
            {
                if (gezici->onceki == 0)
                {
                    cout << setiosflags(ios::left) << setw(1) << "|" << setw(10) << "00000000" << setw(3) << "|";
                }
                else
                {
                    cout << setiosflags(ios::left) << setw(1) << "|" << setw(10) << gezici->onceki << setw(3) << "|";
                }
            }
            gezici = gezici->sonraki;
        }
        gezici = yazilacak;
        for (i = 0; i < 8; i++)
        {
            if (gezici == 0)
            {
                cout << endl;
                break;
            }
            if (i == 7)
            {
                cout << setiosflags(ios::left) << setw(14) << "------------" << endl;
            }
            else
            {
                cout << setiosflags(ios::left) << setw(14) << "------------";
            }
            gezici = gezici->sonraki;
        }
        gezici = yazilacak;
        for (i = 0; i < 8; i++)
        {
            if (gezici == 0)
            {
                cout << endl;
                break;
            }
            if (i == 7)
            {
                cout << setiosflags(ios::left) << setw(1) << "|" << setw(10) << gezici->ort << setw(3) << "|" << endl;
            }
            else
            {
                cout << setiosflags(ios::left) << setw(1) << "|" << setw(10) << gezici->ort << setw(3) << "|";
            }
            gezici = gezici->sonraki;
        }
        gezici = yazilacak;
        for (i = 0; i < 8; i++)
        {
            if (gezici == 0)
            {
                cout << endl;
                break;
            }
            if (i == 7)
            {
                cout << setiosflags(ios::left) << setw(14) << "------------" << endl;
            }
            else
            {
                cout << setiosflags(ios::left) << setw(14) << "------------";
            }
            gezici = gezici->sonraki;
        }
        gezici = yazilacak;
        for (i = 0; i < 8; i++)
        {
            if (gezici == 0)
            {
                cout << endl;
                break;
            }
            if (i == 7)
            {
                cout << setiosflags(ios::left) << setw(1) << "|" << setw(10) << gezici->sonraki << setw(3) << "|" << endl;
            }
            else
            {
                if (gezici->sonraki == 0)
                {
                    cout << setiosflags(ios::left) << setw(1) << "|" << setw(10) << "00000000" << setw(3) << "|";
                }
                else
                {
                    cout << setiosflags(ios::left) << setw(1) << "|" << setw(10) << gezici->sonraki << setw(3) << "|";
                }
            }
            gezici = gezici->sonraki;
        }
        gezici = yazilacak;
        int aralik = (14 * c);
        if (silinecek == 0)
        {
            satiryazilacak->liste->Yazdir(aralik);
        }
        else
        {
            satiryazilacak->liste->Yazdir(aralik, silinecek);
        }
    }
}
