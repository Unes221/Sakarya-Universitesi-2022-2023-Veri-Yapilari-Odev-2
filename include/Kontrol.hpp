#ifndef Kontrol_hpp
#define Kontrol_hpp

#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include "Organizma.hpp"
using namespace std;
class Kontrol
{
public:
    Kontrol();
    ~Kontrol();
    Organizma* varlik;
    void DosyaOku();
};

#endif