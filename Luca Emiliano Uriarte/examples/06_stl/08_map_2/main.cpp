#include "persona.h"
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
    map<unsigned, persona> persm;
    persona ped("Pedro", 1234, fecha(21, 10, 2000)),
            pab("Pablo", 1122, fecha(15, 1, 2005)),
            vil("Vilma", 2341, fecha(31, 01, 1999));

    persm.insert(pair<unsigned, persona>(ped.GetDocument(), ped));
    persm.insert(pair<unsigned, persona>(pab.GetDocument(), pab));
    persm.insert(pair<unsigned, persona>(vil.GetDocument(), vil));

    cout << "MAP DE PERSONAS:\n\n";
    vPrintMp(persm);

    cout << "La persona con documento 1122 es: \n" << persm.find(1122)->second << endl;
    cout << "Acceso mediante el operador []: \n" << persm[2341] << endl << endl;
    persm[1234] = pab;              // modifico los datos de la persona
    vPrintMp(persm);

    return 0;
}
