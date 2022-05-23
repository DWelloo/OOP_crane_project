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
    /*virtual void zapisz_do_pliku()=0;
    virtual void wczytaj_z_pliku(int)=0;*/
    virtual void dodaj_obiekt()=0;
    virtual void wypisz_obiekt()=0;
    virtual string podaj_klase(){return "Maszyna";};
    void wyswietl_katalog_klasy()
    {
        cout<<"Nie istnieje katalog dla klasy abstrakcyjnej";
    };
    Maszyna(){};
    virtual ~Maszyna(){};
protected:
    char czy_stacjonarny='-';
    string typ_maszyny="-";
};
#endif // KLASA_M_H
