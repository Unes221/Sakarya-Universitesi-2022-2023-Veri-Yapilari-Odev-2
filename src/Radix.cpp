/**
* @file Radix.hpp
* @description Radix short yapısını ve foksuyonları tanımlar
* @course 2_B
* @assignment 2
* @date 14.12.2022
* @author Enes_IŞIK enes.isik2@ogr.sakarya.edu.tr
*/
#include "Queue.hpp"
#include "Radix.hpp"
#include "Hucre.hpp"
#include<iomanip>
Radix::Radix(Queue*liste)
{
    this->sayiAdedi = liste->elemanSayisi;
    this->sayilar = new int[sayiAdedi];
    Hucre* yer=liste->ilk;
    for(int i=0;i<sayiAdedi;i++)
    {
        this->sayilar[i] = yer->dna;
        yer= yer->sonraki;
    }
    kuyruklar = new Queue*[10];
    for(int i=0;i<10;i++)
    {
        kuyruklar[i] = new Queue();
    }
    
}

Radix::~Radix()
{
    delete[] sayilar;
    for(int i=0;i<10;i++)
    {
        delete kuyruklar[i];
    }
    delete [] kuyruklar;
}
int Radix::maxBasamakSayisiGetir()
{
    int maxBasamakSayisi = basamakSayisiGetir(sayilar[0]);

    for(int i=1;i<sayiAdedi;i++)
    {
        int siradakiBasamakSayisi = basamakSayisiGetir(sayilar[i]);
        if(maxBasamakSayisi<siradakiBasamakSayisi)
            maxBasamakSayisi = siradakiBasamakSayisi;
    }
    return maxBasamakSayisi;
}
void *Radix::sirala(Queue*liste)
{
    for(int i=0;i<sayiAdedi;i++)
    {
        int sonBasamak = sayilar[i]%10;
        kuyruklar[sonBasamak]->ekle(sayilar[i]);
    }
    int maxBasamakSayisi = maxBasamakSayisiGetir();
    int basamakCarpani = 10;
    for(int i = 1;i<maxBasamakSayisi;i++ )
    {
        int uzunluklar[10];
        kuyrukUzunluklariGetir(uzunluklar);
        for(int j=0;j<10;j++)
        {
            int es = uzunluklar[j];
            while(es)
            {
                int siradakiSayi = kuyruklar[j]->getir();
                kuyruklar[j]->cikar();
                int basamak = (siradakiSayi/basamakCarpani)%10;
                kuyruklar[basamak]->ekle(siradakiSayi);
                es--;
            }
        }
        basamakCarpani*=10;
    }
    int diziIndex = 0;
    for(int i=0;i<10;i++)
    {
        while(!kuyruklar[i]->bosmu())
        {
            sayilar[diziIndex] = kuyruklar[i]->getir();
            kuyruklar[i]->cikar();
            diziIndex++;
        }
    }
    Hucre* yer=liste->ilk;
    for(int i=0;i<sayiAdedi;i++)
    {
        yer->dna =sayilar[i] ;
        yer= yer->sonraki;
    }
}


void Radix::kuyrukUzunluklariGetir(int* uzunluklar)
{
    for(int i=0;i<10;i++)
    {
        uzunluklar[i] = kuyruklar[i]->elemanSayisi;
    } 
}
int Radix::basamakSayisiGetir(int sayi)
{
    int basamakSayisi = 0;
    while(sayi)
    {
        sayi = sayi/10;
        basamakSayisi++;
    }
    return basamakSayisi;

}

