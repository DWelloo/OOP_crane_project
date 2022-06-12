#ifndef KLASA_DZ_H
#define KLASA_DZ_H
#include <iostream>
#include <string.h>
using namespace std;
class Zuraw
{
public:
    Zuraw(){};
    Zuraw(double wys){this->wysokosc=wys;};
    Zuraw(const Zuraw &m){this->wysokosc=m.wysokosc;};
    Zuraw& operator=(const Zuraw &m)
    {
        if(this==&m)
        {
            return *this;
        }
        this->wysokosc=m.wysokosc;
        return *this;
    };
    bool operator!=(const Zuraw &m)
    {
        if(this->wysokosc==m.wysokosc)return false;
        else return true;
    }
    friend ostream& operator<<(ostream &ofs,Zuraw &o)
    {
        ofs<<o.wysokosc;
        return ofs;
    };
    friend istream& operator>>(istream &ifs,Zuraw &o)
    {
        ifs>>o.wysokosc;
        return ifs;
    };
    void dodaj_Zuraw()
    {
        cout<<"Podaj wysokość zurawia: ";
        cin>>wysokosc;
    };
    ~Zuraw(){};
    double wysokosc=0;
};
#endif // KLASA_DZ_H
