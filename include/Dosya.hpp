#ifndef Dosya_hpp
#define Dosya_hpp

#include <sstream>
#include <iostream>
#include <fstream>
#include <string>

#include "SatirListesi.hpp"
#include "YoneticiListesi.hpp"
#include "Dosya.hpp"

using namespace std;

class Dosya
{
public:
    Dosya();
    ~Dosya();
    YoneticiListesi *Dosya_oku();
};

#endif