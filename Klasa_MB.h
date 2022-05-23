#ifndef KLASA_MB_H
#define KLASA_MB_H
#include "Klasa_M.h"
using namespace std;
class M_budowla: public Maszyna
{
public:
    M_budowla(){};
    M_budowla(string n_firma,int rok_z,char czy_stacjo,string typ)
    {
        this->nazwa_firmy=n_firma;
        this->rok_produkcji=rok_z;
        this->czy_stacjonarny=czy_stacjo;
        this->typ_maszyny=typ;
    };
    ~M_budowla(){};
    string podaj_klase(){return "Maszyna budowlana";};
    void wyswietl_katalog_klasy()
    {
        cout<<"[1]Koparka"<<endl;
        cout<<"[2]Walec"<<endl;
        cout<<"[3]Spycharka"<<endl;
    };
    void dodaj_obiekt()
    {
        int a;
        cout<<"Podaj nazwę firmy: ";
        cin>>nazwa_firmy;
        cout<<"Podaj rok produkcji: ";
        cin>>rok_produkcji;
        cout<<"Czy ta maszyna jest stacjonarna? [T]/[N]: ";
        cin>>czy_stacjonarny;
        if(czy_stacjonarny=='t')czy_stacjonarny='T';
        if(czy_stacjonarny=='n')czy_stacjonarny='N';
        cout<<"Wybierz typ maszyny:"<<endl;
        this->wyswietl_katalog_klasy();
        cin>>a;
        switch(a)
        {
        case 1:
            this->typ_maszyny="Koparka";
            break;
        case 2:
            this->typ_maszyny="Walec";
            break;
        case 3:
            this->typ_maszyny="Spycharka";
            break;
        }
    };
    void wypisz_obiekt(){cout<<*this;};
    friend ostream& operator<<(ostream &ofs,M_budowla &m)
    {
        ofs<<m.typ_maszyny<<" "<<m.nazwa_firmy<<" "<<m.rok_produkcji<<" "<<m.czy_stacjonarny<<endl;
        return ofs;
    };
    friend istream& operator>>(istream &ifs,M_budowla &m)
    {
        ifs>>m.typ_maszyny>>m.nazwa_firmy>>m.rok_produkcji>>m.czy_stacjonarny;
        return ifs;
    };
    bool operator!=(const M_budowla &m)
    {
        if(this->nazwa_firmy!=m.nazwa_firmy||this->rok_produkcji!=m.rok_produkcji||this->czy_stacjonarny!=m.czy_stacjonarny||this->typ_maszyny!=m.typ_maszyny)
        {
            return true;
        }
        return false;
    };
protected:
    string nazwa_firmy="-";
    int rok_produkcji=0;
};
#endif // KLASA_MB_H
