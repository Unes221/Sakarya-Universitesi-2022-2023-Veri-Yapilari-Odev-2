#ifndef AramaAgaci_hpp
#define AramaAgaci_hpp

#include <iostream>
#include "Doku.hpp"
using namespace std;
class AramaAgaci
{
public:
    AramaAgaci();
    ~AramaAgaci();
    Doku*ilk;
    int max;
    void ekle(Doku*veri,Doku*yer);
    void yoket(Doku*yer);
};



#endif