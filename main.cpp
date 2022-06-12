#include <iostream>
#include <string>
#include <algorithm>
#include "List.h"
#include "Klasa_D.h"
#include "Test.h"
#include "Klasa_MB.h"
#include "Klasa_MM.h"
#include "Klasa_M.h"
#include "Test.h"
using namespace std;
/*int check_input(const string &s)
{
    int num,iter=0;
    auto i=s.begin();
    while(i!=s.end())
    {
        if(!isdigit(s[iter]))throw string("Wykryto nieprawidłowy znak");
        iter++;
        i++;
    }
    num=stoi(s);
        return num;
};*/
int main()
{
    string wczyt,r="###################################################";
    int a,b,f,ind_1,ind_2;
    List<M_budowla> list_mb;
    List<M_militar> list_mm;
    List<Dzwig> list_d;
    M_budowla *mb=new M_budowla();
    M_militar *mm=new M_militar();
    Dzwig *d=new Dzwig();
    while(true)
    {
        try
        {
        cout<<"Wybierz funkcję:\n[1]dodanie obiektu\n[2]usunięcie wybranego obiektu\n";
        cout<<"[3]usunięcie wszystkich obiektów\n[4]wypisanie wszystkich obiektów\n";
        cout<<"[5]zapis do pliku\n[6]odczyt z pliku\n[7]porównaj\n[8]przesuń obiekt na początek\n";
        cout<<"[9]czy_zawiera\n[11]zamień_miejscami\n[12]Funkcja testująca\n";
        cout<<"[13]Wyjście\n";
        cout<<r<<endl;
        cin>>a;
        //if(!(cin>>a))throw string("Niepoprawny znak");
        //getline(cin,wczyt);
        //a=check_input(wczyt);
        switch(a)
        {
        case 1:
            cout<<"wybierz klasę\n[1]Maszyna_budowlana\n[2]Maszyna_militarna\n[3]Dźwig"<<endl;
            cin>>b;
            cout<<"Wybierz indeks, w który chcesz wstawić obiekt"<<endl;
            cin>>f;
            switch(b)
            {
            case 1:
                mb->dodaj_obiekt();
                list_mb.insert(*mb,f);
                break;
            case 2:
                mm->dodaj_obiekt();
                list_mm.insert(*mm,f);
                break;
            case 3:
                d->dodaj_obiekt();
                list_d.insert(*d,f);
                break;
            }
            cout<<r<<endl;
            break;
        case 2:
            cout<<"wybierz klasę\n[1]Maszyna_budowlana\n[2]Maszyna_militarna\n[3]Dźwig"<<endl;
            cin>>b;
            cout<<"Wybierz indeks obiektu do usunięcia"<<endl;
            cin>>f;
            switch(b)
            {
            case 1:
            list_mb.del(f);
                break;
            case 2:
            list_mm.del(f);
                break;
            case 3:
            list_d.del(f);
                break;
            }
            break;
        case 3:
            cout<<"wybierz klasę\n[1]Maszyna_budowlana\n[2]Maszyna_militarna\n[3]Dźwig"<<endl;
            cin>>b;
            switch(b)
            {
            case 1:
            list_mb.del_all();
                break;
            case 2:
            list_mm.del_all();
                break;
            case 3:
            list_d.del_all();
                break;
            }
            break;
        case 4:
            cout<<"wybierz klasę\n[1]Maszyna_budowlana\n[2]Maszyna_militarna\n[3]Dźwig"<<endl;
            cin>>b;
            switch(b)
            {
            case 1:
            list_mb.w_out();
                break;
            case 2:
            list_mm.w_out();
                break;
            case 3:
            list_d.w_out();
                break;
            }
            break;
        case 5:
            cout<<"wybierz klasę\n[1]Maszyna_budowlana\n[2]Maszyna_militarna\n[3]Dźwig"<<endl;
            cin>>b;
            switch(b)
            {
            case 1:
            list_mb.zapisz_do_pliku();
                break;
            case 2:
            list_mm.zapisz_do_pliku();
                break;
            case 3:
            list_d.zapisz_do_pliku();
                break;
            }
            break;
        case 6:
            cout<<"wybierz klasę\n[1]Maszyna_budowlana\n[2]Maszyna_militarna\n[3]Dźwig"<<endl;
            cin>>b;
            switch(b)
            {
            case 1:
            list_mb.wczytaj_z_pliku();
                break;
            case 2:
            list_mm.wczytaj_z_pliku();
                break;
            case 3:
            list_d.wczytaj_z_pliku();
                break;
            }
            break;
        case 7:
            cout<<"wybierz klasę\n[1]Maszyna_budowlana\n[2]Maszyna_militarna\n[3]Dźwig"<<endl;
            cin>>b;
            switch(b)
            {
            case 1:
            cout<<list_mb.operator==(list_mb)<<endl;
                break;
            case 2:
            cout<<list_mm.operator==(list_mm)<<endl;
                break;
            case 3:
            cout<<list_d.operator==(list_d)<<endl;
                break;
            }
            break;
        case 8:
            cout<<"wybierz klasę\n[1]Maszyna_budowlana\n[2]Maszyna_militarna\n[3]Dźwig"<<endl;
            cin>>b;
            cout<<"Wybierz indeks obiektu do przesunięcia"<<endl;
            cin>>f;
            switch(b)
            {
            case 1:
            list_mb.move_front(f);
                break;
            case 2:
            list_mm.move_front(f);
                break;
            case 3:
            list_d.move_front(f);
                break;
            }
            break;
        case 9:
            cout<<"wybierz klasę\n[1]Maszyna_budowlana\n[2]Maszyna_militarna\n[3]Dźwig"<<endl;
            cin>>b;
            cout<<"Podaj obiekt, który potencjalnie się znajduje w kontenerze:"<<endl;
            switch(b)
            {
            case 1:
                mb->dodaj_obiekt();
            cout<<list_mb.contains(*mb);
                break;
            case 2:
                mm->dodaj_obiekt();
            cout<<list_mm.contains(*mm);
                break;
            case 3:
                d->dodaj_obiekt();
            cout<<list_d.contains(*d);
                break;
            }
            cout<<endl;
            break;
        case 11:
            cout<<"Podaj indeksy obiektów do zamiany: ";
            cin>>ind_1>>ind_2;
            list_mb.rplace(ind_1,ind_2);
            break;
        case 12:
            apka_test();
            break;
        case 13:
            delete mb;
            delete mm;
            delete d;
            return 0;
        default:
            cout<<"Niepoprawny wybór. Spróbuj ponownie"<<endl;
            break;
        }
    }catch(range_error s){cout<<s.what()<<endl;continue;}catch(int s){cout<<s<<endl;}
        catch(string s){cout<<s<<endl;}catch(...){cout<<"Nieprzewidziany wyjątek"<<endl;};
    }
    return 0;
}
