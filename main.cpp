#include <iostream>
#include "List.h"

using namespace std;
int main()
{
    int a,b;
    project::List<int> list;
    while(true)
    {
        cout<<"Wybierz funkcję:\n[1]dodanie obiektu\n[2]usunięcie wybranego obiektu\n";
        cout<<"[3]usunięcie wszystkich obiektów\n[4]wypisanie wszystkich obiektów";
        cout<<"[5]zapis do pliku\n[6]odczyt z pliku\n[7]Wyjście"<<endl;
        cin>>a;
        switch(a)
        {
        case 1:
            break;
        case 2:
            cout<<"Podaj obiekt do dodania"<<endl;
            cin>>b;
            list.add(b);
            break;
        case 3:
            list.w_out();
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            return 0;
        }
    }
    return 0;
}
