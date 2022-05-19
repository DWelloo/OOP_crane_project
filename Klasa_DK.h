#ifndef KLASA_DK_H
#define KLASA_DK_H
#include <iostream>
#include <string.h>
using namespace std;
class Kierowca
{
public:
    ///deklaracja konstruktora domyślnego klasy Kierowca
    Kierowca();
    ///deklaracja konstruktora z parametrami klasy Kierowca
    Kierowca(string,string,float);
    ///deklaracja konstruktora kopiującego klasy Kierowca
    Kierowca(const Kierowca&);
    ///deklaracja przeciążenia operatora porównania klasy Kierowca
    bool operator==(const Kierowca &a);
    ///deklaracja przeciążenia operatora wypisania na strumień klasy Kierowca
    friend ostream& operator<<(ostream&,Kierowca&);
    ///deklaracja przeciążenia operatora zapisu klasy Kierowca
    friend istream& operator>>(istream&,Kierowca&);
    ///deklaracja metody klasy Kierowca
    void wyswietl_kierowce();
    ///deklaracja metody klasy Kierowca
    void dodaj_kierowce();
    ///deklaracja destruktora klasy Kierowca
    ~Kierowca();
    ///początek deklaracji pól klasy Kierowca
    string imie="-";
    string nazwisko="-";
    float lat_doswiadczenia=0;
};
#endif // KLASA_DK_H
