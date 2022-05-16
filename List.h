#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string>
using namespace std;
namespace project
{
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
        Node();
        ~Node();
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
                //tmp->next->next=nullptr;
                tmp->next=n_node;
                //tmp->next->prev=tmp;
                n_node->prev=tmp;
        }
    };
    void del(int a)
    {
        T *tmp;
        for(int i=-1;i<a;++i)
        {
            tmp=this->first;
            this->first=this->first->next;
        }
        delete tmp;
    };
    void del_all()
    {
        Node* tmp;
        while(!this->first)
        {
            tmp=this->first;
            this->first=this->first->next;
            delete tmp;
        }
    };
    void w_out()
    {
        Node* tmp=this->first;
        while(tmp->next)
        {
            cout<<tmp->object;
            tmp=tmp->next;
        }
    };
    void rplace(T,T);
    void move_front();
    void move_back();
    Node* first=nullptr;
    int size=0;
};
}
#endif //LIST_H
