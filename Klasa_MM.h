#ifndef KLASA_MM_H
#define KLASA_MM_H
#include "Klasa_M.h"
using namespace std;
class M_militar: public Maszyna
{
public:
    friend ostream& operator<<(ostream&, M_militar&); ///deklaracja przeciążenia operatora wypisania na strumień klasy Maszyna militarna
    friend istream& operator>>(istream&, M_militar&); ///deklaracja przeciążenia operatora zapisu klasy Maszyna militarna
    void zapisz_do_pliku(); ///deklaracja metody abstrakcyjnej klasy Maszyna militarna
    void wczytaj_z_pliku(int); ///deklaracja metody abstrakcyjnej klasy Maszyna militarna
    void dodaj_obiekt(); ///deklaracja metody abstrakcyjnej klasy Maszyna militarna
    void wypisz_obiekt(); ///deklaracja metody abstrakcyjnej klasy Maszyna militarna
    M_militar(); ///deklaracja konstruktora domyślnego klasy Maszyna militarna
    ~M_militar(); ///deklaracja destruktora klasy Maszyna militarna
private:
    string panstwo_kontrahent="-"; ///początek deklaracji pól klasy Maszyna militarna
    char czy_wystrzeliwuje_pociski='0';
    double kaliber=0;
};
#endif // KLASA_MM_H
