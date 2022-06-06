#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
template<class T>
class List
{
public:
    List(){};
    ~List()
    {
        this->del_all();
    };
    class Node
    {
    public:
        ~Node()
        {
            if(this->prev&&this->next)
            {
                this->prev->next=this->next;
                this->next->prev=this->prev;
            }
            else if(!this->next&&this->prev)
            {
                this->prev->next=nullptr;
            }
            else if(!this->prev&&this->next)
            {
                this->next->prev=nullptr;
            }
        };
        friend ostream& operator<<(ostream &ofs,Node &node)
        {
            ofs<<node.object;
            return ofs;
        };
        friend istream& operator>>(istream &ifs,Node &node)
        {
            ifs>>node.object;
            return ifs;
        }
        T object;
        Node* next=nullptr;
        Node* prev=nullptr;
    };
    void add(T o)
    {
        Node* n_node=new Node();
        n_node->object=o;
        n_node->next=nullptr;
        if(!this->first)
        {
            this->first=n_node;
            n_node->prev=nullptr;
        }
        else
        {
            Node* tmp=this->first;
            while(tmp->next)tmp=tmp->next;
            tmp->next=n_node;
            n_node->prev=tmp;
        }
        this->size++;
    };
    void del(int a)
    {
        try{
        if(a<0||a>this->size-1)throw range_error("Błąd:Indeks spoza zakresu");
        Node *tmp=this->first;
        int i=0;
        if(a==i)this->first=this->first->next;
        while(i<a)
        {
            tmp=tmp->next;
            ++i;
        };
        delete tmp;
        this->size--;
        }catch(range_error s){cout<<s.what()<<endl;return;};
    };
    void insert(T object,int indeks)
    {
        try{
        if(this->size==0||indeks==this->size)add(object);
        else if(indeks<0||indeks>this->size)throw invalid_argument("Indeks spoza zakresu");
        else
        {
            Node *tmp=this->first;
            T tmp_mved;
            T tmp_mnext;
            for(int i=0;i<indeks;i++)tmp=tmp->next;
            tmp_mved=tmp->object;
            tmp->object=object;
            tmp=tmp->next;
            while(tmp)
            {
                tmp_mnext=tmp->object;
                tmp->object=tmp_mved;
                tmp_mved=tmp_mnext;
                tmp=tmp->next;
            }
            this->add(tmp_mved);
        }
        }catch(invalid_argument s){cout<<s.what()<<endl;return;}
    }
    void del_all()
    {
        Node* tmp;
        while(this->first)
        {
            tmp=this->first;
            this->first=this->first->next;
            delete tmp;
        }
        this->size=0;
    };
    void w_out()
    {
        Node* tmp=this->first;
        while(tmp)
        {
            cout<<tmp->object<<endl;
            tmp=tmp->next;
        }
    };
    void rplace(int x,int y)
    {
        try{
            if(x==y)throw domain_error("Kontener jest pusty");
            if(x<0||y<0||x>this->size-1||y>this->size-1)throw invalid_argument("Indeks spoza zasięgu");
        Node *tmp_x=this->first;
        Node *tmp_y=this->first;
        Node *tmp_obj=new Node();
        int i=0;
        while(i<x)tmp_x=tmp_x->next;
        i=0;
        while(i<y)tmp_y=tmp_y->next;
        tmp_obj->object=tmp_x->object;
        tmp_x->object=tmp_y->object;
        tmp_y->object=tmp_obj->object;
        }catch(invalid_argument s){cout<<s.what()<<endl;return;}catch(domain_error s){cout<<s.what()<<endl;return;};
    };
    void move_front(int a)
    {
        Node *tmp=this->first;
        int i=0,j=0;
        T y,x=this->first->object;
        do
        {
            tmp=tmp->next;
            ++i;
        }while(i<a);
        this->first->object=tmp->object;
        tmp=this->first->next;
        while(j<a)
        {
            y=tmp->object;
            tmp->object=x;
            x=y;
            tmp=tmp->next;
            j++;
        }
    };
    bool contains(T& t)
    {
        Node *tmp=this->first;
        while(tmp)
        {
            if(tmp->object==t)
            {
                return true;
            }
            tmp=tmp->next;
        }
        return false;
    };
    List& operator=(const List&l)
    {
        if(*this==l)return *this;
        if(l.size==0) //zapytać prowadzącego
        {
            this->del_all();
            return *this;
        }
        Node *tmp=new Node();
        tmp=l.first;
        while(tmp)
        {
        this->add(tmp->object);
        tmp=tmp->next;
        }
        return *this;
    };
    bool operator==(const List&l)
    {
        if(this->size!=l.size)return false;
        if(this->size==0&&l.size==0)return true;
        Node* tmp_t;
        Node* tmp_l;
        tmp_t=this->first;
        tmp_l=l.first;
        while(tmp_t)
        {
            if(tmp_t->object!=tmp_l->object)return false;
            tmp_t=tmp_t->next;
            tmp_l=tmp_l->next;
        };
        return true;
    };
    void zapisz_do_pliku()
    {
        try{
            if(!this->first)throw domain_error("Kontener jest pusty");
        ofstream ofs;
        Node *tmp=this->first;
        ofs.open("Plik.txt"); //if (ofs.bad())throw
        if(ofs.good())
        {
            while(tmp)
            {
                ofs<<tmp->object<<endl;
                if(ofs.fail())break;
                tmp=tmp->next;
            }
        }
        delete tmp;
        ofs.close();
        }catch(domain_error s){cout<<s.what()<<endl;return;};
    };
    void wczytaj_z_pliku()
    {
        if(this->first)this->del_all();
        ifstream ifs;
        Node *tmp=new Node();
        this->first=tmp;
        ifs.open("Plik.txt"); // if(ifs.bad())throw       / while(true)
        while(ifs.good())
        {
            ifs>>tmp->object;
            if(ifs.fail())
            {
                delete tmp;
                break;
            }
            this->add(tmp->object);
            tmp=tmp->next;
        }ifs.close();
    }
    Node* first=nullptr;
    int size=0;
};
#endif //LIST_H
