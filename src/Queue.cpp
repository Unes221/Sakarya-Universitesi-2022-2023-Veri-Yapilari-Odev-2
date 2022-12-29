/**
* @file Queue.hpp
* @description Queue yapısını ve foksuyonları tanımlar
* @course 2_B
* @assignment 2
* @date 14.12.2022
* @author Enes_IŞIK enes.isik2@ogr.sakarya.edu.tr
*/
#include"Hucre.hpp"
#include "Queue.hpp"
#include<iostream>
Queue::Queue()
{
    ilk=son=0;
    elemanSayisi=0;
}
Queue::~Queue()
{
    while(ilk!=0)
    {
        Hucre*gec= ilk;
        ilk=ilk->sonraki;
        delete gec;
    }
}

void Queue::ekle(int dna)
{
    if(ilk==0)
    {
        son=ilk=new Hucre(dna);
    }
    else
    {
        Hucre*yeni = new Hucre(dna);
        son->sonraki = yeni;
        son = yeni;

    }
    elemanSayisi++;
}
int Queue::ortanca()
{
    Hucre* yer=ilk;
    for(int i =0;i<elemanSayisi/2;i++)
    {
        yer=yer->sonraki;
    }
    int deger=yer->dna;
    return deger;
}
bool Queue::bosmu()
{
    if(ilk==0)
    {
        return true;
        }
    return false;
}
void Queue::cikar()
{
    if(ilk!=0)
    {
        Hucre*gec = ilk->sonraki;
        delete ilk;
        ilk=gec;
        if(ilk==0)
            son=0;
        elemanSayisi--;
    }
}
int Queue::getir()
{
    if(ilk!=0)
    {
        return ilk->dna;}
}