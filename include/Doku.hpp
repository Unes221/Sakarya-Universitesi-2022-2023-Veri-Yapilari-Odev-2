#ifndef Doku_hpp
#define Doku_hpp

#include <iostream>
#include "Queue.hpp"
#include "Radix.hpp"
using namespace std;
class Doku
{
public:
    Doku(Queue*liste);
    ~Doku();
    Queue*liste;
    Doku*sag;
    Doku*sol;
    int yukseklik;
    int ort;
    void mutasyon();
};



#endif