#ifndef Radix_hpp
#define Radix_hpp
#include "Queue.hpp"

class Radix
{
public:
    Radix(Queue*liste);
    ~Radix();
    void* sirala(Queue*liste);
    int     maxBasamakSayisiGetir();
    int     basamakSayisiGetir(int sayi);
    void    kuyrukUzunluklariGetir(int* uzunluklar);
    Queue** kuyruklar;
    int*    sayilar;
    int     sayiAdedi;
};

#endif