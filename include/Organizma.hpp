#ifndef Organizma_hpp
#define Organizma_hpp

#include <iostream>
#include "Bagli.hpp"
using namespace std;
class Organizma
{
public:
    Organizma();
    ~Organizma();
    Bagli*liste;
    void yazdir();
    void mutasyon();
    void ekle(Sistem*ek);
};

#endif