#ifndef TEST_H
#define TEST_H
#include <List.h>
#include <limits>
void apka_test()
{
    int b,m,n;
    List<int> list;
    List<int> list2;
    string input;
    cout<<"Dodawanie liczb do listy 1"<<endl;
    while(true)
    {
        cout<<"Podaj liczbę: ";
        cin>>m;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            break;
        }
        list.add(m);
    };
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
