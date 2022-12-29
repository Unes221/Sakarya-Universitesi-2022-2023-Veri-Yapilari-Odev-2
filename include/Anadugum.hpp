#ifndef Anadugum_hpp
#define Anadugum_hpp

#include <iostream>
#include "SatirListesi.hpp"

using namespace std;

class Anadugum
{
public:
    Anadugum(SatirListesi*liste);
    ~Anadugum();
    double ort;
    Anadugum* onceki;
    Anadugum* sonraki;
    SatirListesi* liste;
};

#endif