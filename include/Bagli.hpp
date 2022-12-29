#ifndef Bagli_hpp
#define Bagli_hpp

#include <iostream>
#include "Sistem.hpp"
using namespace std;
class Bagli
{
public:
    Bagli();
    ~Bagli();
    Sistem* ilk;
    Sistem* son;
    void ekle(Sistem*ek);
};

#endif