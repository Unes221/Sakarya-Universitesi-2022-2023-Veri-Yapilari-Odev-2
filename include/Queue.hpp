#ifndef Queue_hpp
#define Queue_hpp
#include<iostream>
#include"Hucre.hpp"
using namespace std;

class Queue
{
public:
	Queue();
	~Queue();
	void ekle(int dna);
    int ortanca();
    void cikar();
    bool bosmu();
	int getir();
	int elemanSayisiGetir();
    Hucre* 	ilk;
	Hucre*	son;   
	int elemanSayisi;
};

#endif