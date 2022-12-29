#ifndef Sistem_hpp
#define Sistem_hpp

#include <iostream>
#include "Organ.hpp"
using namespace std;
class Sistem
{
public:
    Sistem();
    ~Sistem();
    void yazdir();
    void mutasyon();
    void ekle(Organ*ek); 
    int index;
    Organ* organlar[100];
    Sistem* sonraki;
};

#endif