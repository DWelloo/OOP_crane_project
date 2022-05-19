#ifndef KLASA_M_H
#define KLASA_M_H
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <ios>
using namespace std;
class Maszyna
{
public:
    virtual void zapisz_do_pliku()=0;
    ///deklaracja metody abstrakcyjnej klasy Maszyna
    virtual void wczytaj_z_pliku(int)=0;
    ///deklaracja metody abstrakcyjnej klasy Maszyna
    virtual void dodaj_obiekt()=0;
    ///deklaracja metody abstrakcyjnej klasy Maszyna
    virtual void wypisz_obiekt()=0;
    ///deklaracja konstruktora domyślnego klasy Maszyna
    Maszyna();
    ///Destruktor domyślny klasy Maszyna
    virtual ~Maszyna();
protected:
    char czy_stacjonarny='-';
    string typ_maszyny="-";
};
#endif // KLASA_M_H
