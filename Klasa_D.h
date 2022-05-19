#ifndef KLASA_D_H
#define KLASA_D_H
#include "Klasa_DZ.h"
#include "Klasa_DK.h"
#include "Klasa_MB.h"
using namespace std;
class Dzwig: public M_budowla
{
public:
    Dzwig();
    Dzwig(string,int);
    Dzwig(const Dzwig&);
    Dzwig& operator=(const Dzwig&);
    friend ostream& operator<<(ostream&,Dzwig&);
    friend istream& operator>>(istream&,Dzwig&);
    Kierowca operator[](int);
    void operator--();
    operator string();
    void zapisz_do_pliku();
    void wczytaj_z_pliku(int);
    void dodaj_obiekt();
    void wypisz_obiekt();
    virtual void wyswietl_katalog_klasy();
    string podaj_klase();
    ~Dzwig();
    Zuraw m_zuraw;
private:
    int ile_kier_dzwigu=0;
    string nazwa_firmy="-";
    int rok_produkcji=0;
    Kierowca* kierowcy=nullptr;
};
#endif // KLASA_D_H
