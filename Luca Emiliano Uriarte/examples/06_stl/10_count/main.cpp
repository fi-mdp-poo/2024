#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T> void vPrintVec(vector<T> v)
{
    typename vector<T>::iterator ForIter;

    ForIter = v.begin();                        // puntero al primer elemento
    cout << endl;
    while (ForIter != v.end() )                 // mientras no sea el último elemento
    {
        cout << *ForIter++ << " ";              // aumento el iterador
    }
    cout << "\n\n";
}

bool dividesBy3(int i)                      // unary predicate: determina si es divisible por 3
{
    bool result;
    (i%3) ? result=false : result=true;

    return result;
}

int main()
{
    vector<int> iVec;                       // vector de enteros
    vector<char> cVec,                      // vector de enteros
                 cResult(30);               // vector de 30 elementos
    unsigned loop,
             cnt;

    for(loop=0; loop<30; loop++)
    {
        iVec.push_back(loop);
        cnt = loop;
        if(loop>9)
            cnt/= 10;
        cVec.push_back(cnt + 0x30);
    }
    cout << "Secuencias originales:\n";
    vPrintVec(iVec);
    vPrintVec(cVec);

    cnt = count(iVec.begin(), iVec.end(), 7);
    cout << "\nHay " << cnt << " numeros 7 en la secuencia completa\n\n";
    cnt = count(iVec.begin()+10, iVec.begin()+15, 12);
    cout << "Hay " << cnt << " numeros 12 en la secuencia reducida\n\n";

    cnt = count_if(iVec.begin(), iVec.end(), dividesBy3);
    cout << cnt << " numeros son divisibles por 3.\n\n";

    remove_copy(cVec.begin(), cVec.end(), cResult.begin(), '1');
    cout << "\nSe eliminan los '1' de la secuencia de caracteres\n";
    vPrintVec(cResult);

    replace_copy(cVec.begin(), cVec.end(), cResult.begin(), '2', '3');
    cout << "\nSe reemplazan los '2' por '3' en la secuencia de caracteres\n";
    vPrintVec(cResult);

    reverse(iVec.begin(), iVec.end());
    cout << "\nSecuencia de numeros invertida:\n";
    vPrintVec(iVec);

    string ptr("Prueba de escritura en un string para invertir");
    cout << "\nString original: " << ptr;
    reverse(ptr.begin(), ptr.end());
    cout << "\n\nString invertido: " << ptr << endl << endl;


    return 0;
}
