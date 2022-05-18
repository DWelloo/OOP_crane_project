#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string>
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
            while(tmp->next!=nullptr)
            {
                tmp=tmp->next;
            }
                tmp->next=n_node;
                n_node->prev=tmp;
        }
        this->size++;
    };
    void del(int a)
    {
        Node *tmp=this->first;
        int i=0;
        if(a==i)
        {
            this->first=this->first->next;
        }
        while(i<a)
        {
            tmp=tmp->next;
            ++i;
        };
        delete tmp;
        this->size--;
    };
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
    void rplace(T x,T y);
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
        if(*this==l)
        {
            return *this;
        }
        if(l.size==0)
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
        /*Node *tmp=new Node();
        if(this->first==nullptr)
        {
            this->first=tmp;
        }
        Node *tmp_l=l.first;
        while(tmp_l)
        {
            tmp->object=tmp_l->object;
            tmp->next=new Node();
            tmp=tmp->next;
            tmp_l=tmp_l->next;
        }*/
    };
    bool operator==(const List&l)
    {
        if(this->size!=l.size)
        {
            return false;
        }
        if(this->size==0||l.size==0)
        {
            return true;
        }
        Node* tmp_t;
        Node* tmp_l;
        tmp_t=this->first;
        tmp_l=l.first;
        while(tmp_t)
        {
            if(tmp_t->object!=tmp_l->object)
            {
                return false;
            }
            tmp_t=tmp_t->next;
            tmp_l=tmp_l->next;
        };
        return true;
    };
    //void find(int a);
    Node* first=nullptr;
    int size=0;
};
#endif //LIST_H
