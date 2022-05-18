#include <iostream>
#include "List.h"

using namespace std;
int main()
{
    string r="############################################";
    int a,b,f;
    List<int> list;
    List<int> list2;
    while(true)
    {
        cout<<"Wybierz funkcję:\n[1]dodanie obiektu\n[2]usunięcie wybranego obiektu\n";
        cout<<"[3]usunięcie wszystkich obiektów\n[4]wypisanie wszystkich obiektów\n";
        cout<<"[5]zapis do pliku\n[6]odczyt z pliku\n[7]porównaj\n[8]przesuń obiekt na początek\n";
        cout<<"[9]czy_zawiera\n[10]podstaw\n[11]Wyjście"<<endl;
        cin>>a;
        switch(a)
        {
        case 1:
            cout<<endl;
            cout<<"Wybierz listę do dodania obiektu"<<endl;
            cin>>f;
            cout<<"Podaj obiekt do dodania"<<endl;
            cin>>b;
            if(f==1)
            list.add(b);
            else
                list2.add(b);
            cout<<r<<endl;
            break;
        case 2:
            cout<<endl;
            cout<<"Wybierz indeks obiektu do usunięcia"<<endl;
            cin>>b;
            list.del(b);
            cout<<r<<endl;
            break;
        case 3:
            cout<<endl;
            list.del_all();
            cout<<r<<endl;
            break;
        case 4:
            cout<<endl;
            list.w_out();
            cout<<endl;
            list2.w_out();
            cout<<r<<endl;
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            cout<<list.operator==(list2)<<endl;
            break;
        case 8:
            cout<<endl;
            cout<<"Wybierz indeks obiektu do przesunięcia"<<endl;
            cin>>b;
            list.move_front(b);
            cout<<r<<endl;
            break;
        case 9:
            cout<<endl;
            cout<<"Wybierz obiekt do szukania"<<endl;
            cin>>b;
            cout<<list.contains(b)<<endl;
            cout<<r<<endl;
            break;
        case 10:
            list.operator=(list2);
            break;
        case 11:
            return 0;
        }
    }
    return 0;
}
