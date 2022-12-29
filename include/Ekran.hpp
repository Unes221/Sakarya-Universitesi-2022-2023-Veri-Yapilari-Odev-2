#ifndef Ekran_hpp
#define Ekran_hpp

#include <iostream>
#include <iomanip>
#include "SatirListesi.hpp"
#include "YoneticiListesi.hpp"
#include "Dosya.hpp"

using namespace std;

class Ekran
{
public:
    int YoneticiSayac = 0, SartirSayac = 0;
    Ekran(YoneticiListesi *analiste);
    ~Ekran();
    int c, k;
    YoneticiListesi *yonetici;
    Dugum *silinecek;
    Anadugum *yazilacak;
    Anadugum *satiryazilacak;
    void EkranKomut(char emir);
    void EkranYazdir();
};
#endif