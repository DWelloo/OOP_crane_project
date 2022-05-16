/*#include <string>
#include "List.h"
using namespace std;
template<class T>
project::List<T>::List(){}
template<class T>
project::List<T>::~List()
{
    this->del_all();
}
template<class T>
project::Node<T>::Node(){}
template<class T>
project::Node<T>::~Node()
{
    if(!this->first&&!this->next)
    {
        this->prev->next=this->next;
        this->next->prev=this->prev;
    }
}
template<class T>
void project::List<T>::add(T o)
{
    project::Node<T>* n_node=new project::Node<T>();
    n_node->object=o;
    n_node->next=nullptr;
    if(!this->first)
    {
        this->first=n_node;
        n_node->prev=nullptr;
    }
    else
    {
        project::List<T>* tmp=this->first;
        while(tmp->next!=nullptr)
        {
            tmp=tmp->next;
        }
            //tmp->next->next=nullptr;
            tmp->next=n_node;
            //tmp->next->prev=tmp;
            n_node->prev=tmp;
    }
}
template<class T>
void project::List<T>::del_all()
{
    T* tmp;
    while(!this->first)
    {
        tmp=this->first;
        this->first=this->first->next;
        delete tmp;
    }
}
template<class T>
void project::List<T>::del(int a)
{
    T *tmp;
    for(int i=-1;i<a;++i)
    {
        tmp=this->first;
        this->first=this->first->next;
    }
    delete tmp;
}
template<class T>
void::project::List<T>::w_out()
{
    T* tmp=this->first;
    while(tmp->next)
    {
        cout<<tmp->object;
        tmp=tmp->next;
    }
}
template<class T>
void project::List<T>::insert(T o,int i)
{
    project::Node<T>* n_node=new project::Node<T>();
}*/
