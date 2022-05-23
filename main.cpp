#include <iostream>
#include "List.h"
#include "Klasa_M.h"
#include "Klasa_MB.h"
#include "Klasa_MM.h"
#include "Test.h"
using namespace std;
int main()
{
    string r="###################################################";
    int a,b,f,ind_1,ind_2;
    List<M_budowla> list_mb;
    List<M_militar> list_mm;
    M_budowla *mb=new M_budowla();
    M_militar *mm=new M_militar();
    //M_budowla mb2;
    while(true)
    {
        try
        {
        cout<<"Wybierz funkcję:\n[1]dodanie obiektu\n[2]usunięcie wybranego obiektu\n";
        cout<<"[3]usunięcie wszystkich obiektów\n[4]wypisanie wszystkich obiektów\n";
        cout<<"[5]zapis do pliku\n[6]odczyt z pliku\n[7]porównaj\n[8]przesuń obiekt na początek\n";
        cout<<"[9]czy_zawiera\n[10]podstaw\n[11]zamień_miejscami\n[12]Funkcja testująca\n";
        cout<<"[13]Wyjście\n";
        cout<<r<<endl;
        cin>>a;
        switch(a)
        {
        case 1:
            cout<<"wybierz klasę\n[1]Maszyna_budowlana\n[2]Maszyna_militarna\n[3]Dźwig"<<endl;
            cin>>b;
            switch(b)
            {
            case 1:
                mb->dodaj_obiekt();
                list_mb.add(*mb);
                break;
            case 2:
                break;
            case 3:
                break;
            }
            cout<<r<<endl;
            break;
        case 2:
            cout<<"Wybierz indeks obiektu do usunięcia"<<endl;
            cin>>b;
            list_mb.del(b);
            break;
        case 3:
            list_mb.del_all();
            break;
        case 4:
            list_mb.w_out();
            break;
        case 5:
            list_mb.zapisz_do_pliku();
            break;
        case 6:
            list_mb.wczytaj_z_pliku();
            break;
        case 7:
            cout<<list_mb.operator==(list_mb)<<endl;
            break;
        case 8:
            cout<<"Wybierz indeks obiektu do przesunięcia"<<endl;
            cin>>b;
            list_mb.move_front(b);
            break;
        case 9:
            cout<<endl;
            break;
        case 10:
            cout<<endl;
            break;
        case 11:
            cout<<"Podaj indeksy obiektów do zamiany: ";
            cin>>ind_1>>ind_2;
            list_mb.rplace(ind_1,ind_2);
        case 12:
            apka_test();
            break;
        case 13:
            delete mb;
            delete mm;
            return 0;
        default:
            cout<<"Niepoprawny wybór. Spróbuj ponownie"<<endl;
            break;
        }
    }catch(range_error s){cout<<s.what()<<endl;continue;}catch(int s){cout<<s<<endl;};
    }
    return 0;
}
