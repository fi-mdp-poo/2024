#include <iostream>
#include <map>

using namespace std;

template <class K, class V> void vPrintMp(map<K, V> mp)
{
    typename map<K, V>::iterator ForIter;

    ForIter = mp.begin();                       // puntero al primer elemento
    cout << endl;
    while (ForIter != mp.end() )                // mientras no sea el último elemento
    {
        cout << ForIter->first << "  " << ForIter->second << endl;
        ForIter++;                              // aumento el iterador
    }
    cout << "\n\n";
}

int main()
{
    map<char, int> cm;
    map<char, int>::iterator ptr, ptr2;
    int i;
    char ch;

    for(i=0; i<26; i++)
    {
        cm.insert(pair<char, int>('A'+i, 65+i));
    }
    cout << "MAP DE CARACTERES\n\n:";
    vPrintMp(cm);

    cout << "Elimino la mitad del map:\n";
    ptr = ptr2 = cm.begin();
    advance(ptr2, int(cm.size()/2));
    cm.erase(ptr, ptr2);
    vPrintMp(cm);

    cout << "Ingrese una clave: ";
    cin >> ch;
    ptr = cm.find(ch);
    if(ptr != cm.end())
    {
        cout << "Su codigo ASCII es " << ptr->second << endl;
    }
    else
    {
        cout << "Clave no encontrada\n";
    }
    cout << "Ingrese una clave: ";
    cin >> ch;
    ptr = cm.find(ch);
    if(ptr != cm.end())
    {
        cout << "Su codigo ASCII es " << ptr->second << endl;
    }
    else
    {
        cout << "Clave no encontrada\n";
    }

    i = cm['P'];
    cout << "\n\nAcceso mediante el operador []: el codigo de 'P' es = " << i << endl << endl;
    cout << "Si no existe lo inserta, el codigo de 'b' es = " << cm['b'] << endl << endl;
    vPrintMp(cm);
    cm['b'] = 125;
    cout << "Fijo el valor de 'b' con el operador []: " << endl;
    vPrintMp(cm);

    return 0;
}
