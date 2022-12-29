#ifndef Organ_hpp
#define Organ_hpp

#include <iostream>
#include "AramaAgaci.hpp"
using namespace std;
class Organ
{
public:
    Organ();
    ~Organ();
    int index;
    int sira;
    AramaAgaci*agac;
    void mutasyon();
    Doku* dokular[20];
    void agacyap();
    void ekle(Doku*ek);
    void PostOrder(Doku*yer);
};

#endif