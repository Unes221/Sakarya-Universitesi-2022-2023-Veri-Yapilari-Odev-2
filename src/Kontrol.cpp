/**
 * @file Kontrol.hpp
 * @description Konturol işlemleri tanımlar
 * @course 2_B
 * @assignment 2
 * @date 14.12.2022
 * @author Enes_IŞIK enes.isik2@ogr.sakarya.edu.tr
 */
#include "Kontrol.hpp"

Kontrol::Kontrol()
{
    varlik = new Organizma();
}
Kontrol::~Kontrol()
{
    delete varlik;
}
void Kontrol::DosyaOku()
{
    ifstream dosya1("Veri.txt");
    if (dosya1.is_open())
    {
        int sayi;
        string satir;

        for (int a = 0; a == 0;)
        {
            Sistem *yeniSistem = new Sistem();
            for (int i = 0; i < 100; i++)
            {
                Organ *yeniOrgan = new Organ();
                for (int j = 0; j < 20; j++)
                {
                    if (getline(dosya1, satir))
                    {
                        Queue *yeniKuyruk = new Queue();
                        stringstream enes(satir);
                        while (enes >> sayi)
                        {
                            yeniKuyruk->ekle(sayi);
                        }
                        Radix *rad = new Radix(yeniKuyruk);
                        rad->sirala(yeniKuyruk);
                        Doku *yeniDoku = new Doku(yeniKuyruk);
                        delete rad;
                        yeniOrgan->ekle(yeniDoku);
                    }
                    else
                    {
                        return;
                    }
                }
                yeniOrgan->agacyap();
                yeniSistem->ekle(yeniOrgan);
            }
            varlik->ekle(yeniSistem);
        }
    }
}