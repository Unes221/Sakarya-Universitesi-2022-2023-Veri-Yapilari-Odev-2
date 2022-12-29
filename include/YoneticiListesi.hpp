#ifndef YoneticiListesi_hpp
#define YoneticiListesi_hpp

#include <iostream>
#include <iomanip>
#include "Anadugum.hpp"

using namespace std;

class YoneticiListesi
{
public:
    Anadugum *ilk;
    Anadugum *son;
    YoneticiListesi();
    ~YoneticiListesi();
    void SatirEkle(SatirListesi *satir);
    void Sil(Anadugum *yer);
    void SilDugum(Anadugum *yer);
};

#endif