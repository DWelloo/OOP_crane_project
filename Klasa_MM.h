#ifndef KLASA_MM_H
#define KLASA_MM_H
#include "Klasa_M.h"
using namespace std;
class M_militar: public Maszyna
{
public:
    M_militar(){};
    M_militar(string kraj,char czy){};
    ~M_militar(){};
    void dodaj_obiekt()
    {
        int a;
        cout<<"Podaj kontrahenta: ";
        cin>>panstwo_kontrahent;
        cout<<"Wybierz typ maszyny:"<<endl;
        this->wyswietl_katalog_klasy();
        cin>>a;
        switch(a)
        {
        case 1:
            this->typ_maszyny="Pojazd_opancerzony";
            break;
        case 2:
            this->typ_maszyny="Czołg";
            this->czy_wystrzeliwuje_pociski='1';
            break;
        case 3:
            this->typ_maszyny="Moździerz";
            this->czy_wystrzeliwuje_pociski='1';
            break;
        default:
            throw string("Niepoprawny wybór");
            break;
        }
        if(czy_wystrzeliwuje_pociski=='1')
        {
            try
            {
            cout<<"Podaj kaliber pocisków: ";
            cin>>kaliber;
            if(kaliber<=0)throw range_error("Błąd:Wartość spoza zasięgu");
            }catch(range_error s){cout<<s.what()<<endl;kaliber=0;}
        }
    }
    void wypisz_obiekt()
    {
        cout<<*this;
    }
    void wyswietl_katalog_klasy()
    {
        cout<<"[1]Pojazd_opancerzony"<<endl;
        cout<<"[2]Czołg"<<endl;
        cout<<"[3]Moździerz"<<endl;
    }
    string podaj_klase()
    {
        return "Maszyna_militarna";
    }
    friend ostream& operator<<(ostream& ofs,M_militar &m)
    {
        ofs<<m.typ_maszyny<<" "<<m.panstwo_kontrahent<<" "<<m.czy_wystrzeliwuje_pociski<<" "<<m.kaliber<<endl;
        return ofs;
    }
    friend istream& operator>>(istream& ifs,M_militar &m)
    {
        ifs>>m.typ_maszyny>>m.panstwo_kontrahent>>m.czy_wystrzeliwuje_pociski>>m.kaliber;
        return ifs;
    }
    bool operator!=(const M_militar &m)
    {
        if(this->panstwo_kontrahent!=m.panstwo_kontrahent||this->typ_maszyny!=m.typ_maszyny||this->kaliber!=m.kaliber)
        {
            return true;
        }
        return false;
    }
    bool operator==(const M_militar &m)
    {
        if(this!=&m)return false;
        return true;
    }
private:
    string panstwo_kontrahent="-";
    char czy_wystrzeliwuje_pociski='0';
    double kaliber=0;
};
#endif // KLASA_MM_H
