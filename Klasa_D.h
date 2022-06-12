#ifndef KLASA_D_H
#define KLASA_D_H
#include "Klasa_DZ.h"
#include "Klasa_DK.h"
#include "Klasa_MB.h"
#include <vector>
using namespace std;
class Dzwig: public M_budowla
{
public:
    Dzwig(){};
    Dzwig(string m,int l)
    {
        nazwa_firmy=m;
        rok_produkcji=l;
        if(l<0)
        {
            rok_produkcji=0;
        }
    };
    Dzwig(const Dzwig &d)
    {
        this->typ_maszyny=d.typ_maszyny;
        this->nazwa_firmy=d.nazwa_firmy;
        this->rok_produkcji=d.rok_produkcji;
        this->m_zuraw=d.m_zuraw;
        this->ile_kier_dzwigu=d.ile_kier_dzwigu;
        if(d.kierowcy.size()!=0)
        {
            this->kierowcy.operator=(d.kierowcy);
        }
    };
    bool operator==(const Dzwig &d)
    {
        if(this->nazwa_firmy!=d.nazwa_firmy||this->rok_produkcji!=d.rok_produkcji||this->typ_maszyny!=d.typ_maszyny||this->czy_stacjonarny!=d.czy_stacjonarny)return false;
        if(this->ile_kier_dzwigu!=d.ile_kier_dzwigu)return false;
        if(this->m_zuraw!=d.m_zuraw)return false;
        for(int i=0;i<this->ile_kier_dzwigu;i++)
        {if(!(this->kierowcy[i]==d.kierowcy[i]))return false;}
        return true;
    }
    Kierowca operator[](int i)
    {
        if(i<0||i>=kierowcy.size())
        {
            cout<<"Błędny indeks wywoływanego operatora dźwigu"<<endl;
            return Kierowca("-","-",0);
        }
        return kierowcy.operator[](i);
    }
    Dzwig& operator=(const Dzwig &d)
    {
        if(this==&d)
        {
            return *this;
        }
        this->typ_maszyny=d.typ_maszyny;
        this->nazwa_firmy=d.nazwa_firmy;
        this->rok_produkcji=d.rok_produkcji;
        this->m_zuraw=d.m_zuraw;
        this->ile_kier_dzwigu=d.ile_kier_dzwigu;
        if(this->kierowcy.size()!=0)
        {
            this->kierowcy.clear();
        }
        if(d.kierowcy.size()!=0)
        {
            for(int i=0;i<d.kierowcy.size();i++)
            {
                this->kierowcy.push_back(d.kierowcy[i]);
            }
        }
        return *this;

    };
    friend ostream& operator<<(ostream &ofs,Dzwig &d)
    {
        ofs<<d.typ_maszyny<<" "<<d.nazwa_firmy<<" "<<d.rok_produkcji<<" "<<d.m_zuraw.wysokosc<<" "<<d.ile_kier_dzwigu<<endl;
        if(d.kierowcy.size()>0)
        {
            for(int i=0;i<d.kierowcy.size();i++)
            {
                ofs<<d.kierowcy[i];
            }
        }
        return ofs;
    };
    friend istream& operator>>(istream &ifs,Dzwig &d)
    {
        string imie,nazwisko;
        double lat;
        ifs>>d.typ_maszyny>>d.nazwa_firmy>>d.rok_produkcji>>d.m_zuraw.wysokosc>>d.ile_kier_dzwigu;
        for(int i=0;i<d.ile_kier_dzwigu;i++)
        {
            Kierowca a;
            ifs>>a.imie>>a.nazwisko>>a.lat_doswiadczenia;
            d.kierowcy.push_back(a);
        }
        return ifs;
    };
    void dodaj_obiekt()
    {
        int typ;
        cout<<"Wybierz typ dźwigu z dostępnych:"<<endl;
        this->wyswietl_katalog_klasy();
        cin>>typ;
        switch(typ)
        {
        case 1:
            this->typ_maszyny="Dźwig_portowy";
            break;
        case 2:
            this->typ_maszyny="Dźwig_okrężny";
            break;
        case 3:
            this->typ_maszyny="Dźwig_szybowy";
            break;
        }
        cout<<"Podaj nazwę firmy: ";
        cin>>nazwa_firmy;
        cout<<"Podaj rok produkcji: ";
        cin>>rok_produkcji;
        m_zuraw.dodaj_Zuraw();
        cout<<"Podaj ilość kierowców: ";
        cin>>ile_kier_dzwigu;
        for(int i=0;i<ile_kier_dzwigu;i++)
        {
            Kierowca k;
            k.dodaj_kierowce();
            kierowcy.push_back(k);
        }
    };
    void wypisz_obiekt(){cout<<*this;};
    virtual void wyswietl_katalog_klasy()
    {
        cout<<"[1]Dźwig_portowy"<<endl;
        cout<<"[2]Dźwig_okrężny"<<endl;
        cout<<"[3]Dźwig_szybowy"<<endl;
    };
    string podaj_klase(){return "Dźwig";};
    ~Dzwig(){if(kierowcy.size()!=0) kierowcy.clear();};
    Zuraw m_zuraw;
private:
    int ile_kier_dzwigu=0;
    string nazwa_firmy="-";
    int rok_produkcji=0;
};
#endif // KLASA_D_H
