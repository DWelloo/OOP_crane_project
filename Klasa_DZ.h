#ifndef KLASA_DZ_H
#define KLASA_DZ_H
#include <iostream>
#include <string.h>
using namespace std;
class Zuraw
{
public:
    ///deklaracja konstruktora domyślnego klasy Żuraw
    Zuraw();
    ///deklaracja konstruktora z parametrem klasy Żuraw
    Zuraw(double);
    ///deklaracja konstruktora kopiującego klasy Żuraw
    Zuraw(const Zuraw&);
    ///deklaracja operatora przypisania klasy Żuraw
    Zuraw& operator=(const Zuraw&);
    ///deklaracja przeciążenia operatora wypisania na strumień klasy Żuraw
    friend ostream& operator<<(ostream&,Zuraw&);
    ///deklaracja przeciążenia operatora zapisu klasy Żuraw
    friend istream& operator>>(istream&,Zuraw&);
    ///deklaracja metody klasy Żuraw
    void dodaj_Zuraw();
    ///deklaracja destruktora klasy Żuraw
    ~Zuraw();
    ///początek deklaracji pól klasy Żuraw
    double wysokosc=0;
};
#endif // KLASA_DZ_H
