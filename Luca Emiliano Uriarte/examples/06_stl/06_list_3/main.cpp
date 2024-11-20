#include <iostream>
#include <list>

using namespace std;

template <class T> void vPrintLst(list<T> lst)
{
    typename list<T>::iterator ForIter;

    ForIter = lst.begin();                      // puntero al primer elemento
    cout << endl;
    while (ForIter != lst.end() )               // mientras no sea el último elemento
    {
        cout << *ForIter++ << "  ";             // aumento el iterador
    }
    cout << "\n\n";
}

int main()
{
    list<int> lst1, lst2;
    int i;

    for(i=0; i<10; i++)
    {
        lst1.push_back(i);
    }
    for(i=0; i<10; i++)
    {
        lst2.push_front(i);
    }
    cout << "LISTA DE ENTEROS\n\nLista 1 usando push_back:";
    vPrintLst(lst1);
    cout << "Lista 2 usando push_front:";
    vPrintLst(lst2);

    lst1.merge(lst2);
    cout << "\nResultado de merge:";
    vPrintLst(lst1);
    if(lst2.empty())
    {
        cout << "lst2 quedo vacia\n\n";
    }

    return 0;
}
