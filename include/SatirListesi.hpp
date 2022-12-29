#ifndef SatirListesi_hpp
#define SatirListesi_hpp

#include <iostream>
#include <iomanip>
#include <time.h>
#include "Dugum.hpp"

using namespace std;

class SatirListesi
{
public:
    SatirListesi();
    ~SatirListesi();
    Dugum *ilk;
    Dugum *son;
    double ortalama();
    Dugum *getir();
    void Yazdir(int aralik);
    void Yazdir(int aralik, Dugum *isaret);
    void DugumSil(Dugum *yer);
    void DugumEkle(int veri);
};

#endif