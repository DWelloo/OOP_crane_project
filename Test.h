#ifndef TEST_H
#define TEST_H
#include <List.h>
#include <limits>
void apka_test()
{
    int a,b,m,n,f;
    string r="########################################";
    List<int> list;
    List<int> list2;
    string input;
    while(true)
        {
            cout<<"Wybierz funkcję:\n[1]dodanie obiektu\n[2]usunięcie wybranego obiektu\n";
            cout<<"[3]usunięcie wszystkich obiektów\n[4]wypisanie wszystkich obiektów\n";
            cout<<"[5]zapis do pliku\n[6]odczyt z pliku\n[7]porównaj\n[8]przesuń obiekt na początek\n";
            cout<<"[9]czy_zawiera\n[10]\n[11]Wyjście"<<endl;
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
                break;
            case 3:
                list.del_all();
                break;
            case 4:
                cout<<endl;
                list.w_out();
                cout<<endl;
                list2.w_out();
                cout<<r<<endl;
                break;
            case 5:
            case 6:
                break;
            case 7:
                cout<<list.operator==(list2)<<endl;
                break;
            case 8:
                cout<<endl;
                cout<<r<<endl;
                break;
            case 10:
                list.operator=(list2);
                break;
            case 11:
                return;
            case 20:
                cout<<"Podaj obiekt i indeks: ";
                cin>>f>>b;
                list.insert(f,b);
                list.w_out();
                break;
            }
    }
    list2.add(5);
    list2.add(8);
    list2.add(13);
    cout<<"Wybierz indeks obiektu do usunięcia z listy 1"<<endl;
    cin>>b;
    list.del(b);
    list.w_out();
    cout<<endl;
    list2.w_out();
    cout<<endl;
    cout<<"Wybierz obiekt do szukania w liście 1"<<endl;
    cin>>b;
    cout<<list.contains(b)<<endl;
    cout<<"Pierwsze sprawdzenie operatora==: ";
    cout<<list.operator==(list2)<<endl;
    cout<<"Sprawdzenie operatora=;lista 1 stanie się identyczna do listy 2"<<endl;
    list.operator=(list2);
    list.w_out();
    list2.w_out();
    cout<<"Ponowne sprawdzenie operatora==: ";
    cout<<list.operator==(list2);
}
#endif // TEST_H
