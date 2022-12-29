/*
* @file main.cpp
* @description Program Islemleri 
* @course 2/B
* @assignment Odev 1
* @date 20.11.2022
* @author Enes IŞIK  enes.isik2@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <iomanip>
#include <time.h>
#include <fstream>
#include <string>
#include <sstream>
#include "Dosya.hpp"
#include "Ekran.hpp"
#include "YoneticiListesi.hpp"
#include "SatirListesi.hpp"
#include "Dugum.hpp"
#include "Anadugum.hpp"
using namespace std;
int main()
{
    Dosya *a = new Dosya();
    YoneticiListesi *Yonetici = a->Dosya_oku();
    Ekran *ekran = new Ekran(Yonetici);
    char harf;
    do
    {
        ekran->EkranYazdir();
        cin >> harf;
        ekran->EkranKomut(harf);
    } while (harf != 'b');
    delete a;
    delete ekran;
    delete Yonetici;
}