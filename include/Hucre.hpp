#ifndef Hucre_hpp
#define Hucre_hpp

#include <iostream>

using namespace std;
class Hucre
{
public:
    int dna;
    Hucre(int dna);
    ~Hucre();
    Hucre* sonraki;
    void mutasyon();
};

#endif