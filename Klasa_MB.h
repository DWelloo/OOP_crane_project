#ifndef KLASA_MB_H
#define KLASA_MB_H
#include "Klasa_M.h"
using namespace std;
class M_budowla: public Maszyna
{
public:
    friend ostream& operator<<(ostream&, M_budowla&);
    friend istream& operator>>(istream&, M_budowla&);
    void zapisz_do_pliku();
    void wczytaj_z_pliku(int);
    void dodaj_obiekt();
    void wypisz_obiekt();
    M_budowla();
    ~M_budowla();
protected:
    string nazwa_firmy="-";
    int rok_produkcji=0;
};
#endif // KLASA_MB_H
