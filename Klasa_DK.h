#ifndef KLASA_DK_H
#define KLASA_DK_H
#include <iostream>
#include <string.h>
using namespace std;
class Kierowca
{
public:
    Kierowca(){};
    Kierowca(string imie,string nazwisko,float exp)
    {
        this->imie=imie;
        this->nazwisko=nazwisko;
        this->lat_doswiadczenia=exp;
    };
    Kierowca(const Kierowca &o)
    {
        this->imie=o.imie;
        this->nazwisko=o.nazwisko;
        this->lat_doswiadczenia=o.lat_doswiadczenia;
    };
    Kierowca operator=(const Kierowca &o)
    {
        Kierowca (*tmp);
        this->imie=o.imie;
        this->nazwisko=o.nazwisko;
        this->lat_doswiadczenia=o.lat_doswiadczenia;
        return *tmp;
    }
    bool operator==(const Kierowca &a)
    {
        if(this==&a)
        {
            return true;
        }
        if(this->imie!=a.imie&&this->nazwisko!=a.nazwisko&&this->lat_doswiadczenia!=a.lat_doswiadczenia)
        {
            return false;
        }
        return true;
    };
    friend ostream& operator<<(ostream &ofs,Kierowca &o)
    {
        ofs<<o.imie<<" "<<o.nazwisko<<" "<<o.lat_doswiadczenia<<endl;
        return ofs;
    };
    friend istream& operator>>(istream &ifs,Kierowca &o)
    {
        ifs>>o.imie>>o.nazwisko>>o.lat_doswiadczenia;
        return ifs;
    };
    void wyswietl_kierowce()
    {
        cout<<imie<<" "<<nazwisko<<endl;
        cout<<lat_doswiadczenia<<endl;
    };
    void dodaj_kierowce()
    {
        cout<<"Podaj imie i nazwisko: ";
        cin>>imie>>nazwisko;
        cout<<"Podaj doświadczenie: ";
        cin>>lat_doswiadczenia;
    };
    ~Kierowca(){};
    string imie="-";
    string nazwisko="-";
    float lat_doswiadczenia=0;
};
#endif // KLASA_DK_H
