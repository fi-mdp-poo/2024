#include <iostream>
#include <vector>
#include <windows.h>

#define       VERT       1
#define       HORI       0

using namespace std;

template <class T> void vPrintVec(vector<T> v, bool vert)
{
    typename vector<T>::iterator ForIter;

    ForIter = v.begin();                        // puntero al primer elemento
    cout << endl;
    while (ForIter != v.end() )                 // mientras no sea el �ltimo elemento
    {
        cout << *ForIter++ << "  ";              // aumento el iterador
        if (vert)
            cout << endl;
    }
    cout << "\n\n";
}

int main()
{
    SetConsoleOutputCP(1252);
    SetConsoleCP(1252);

    vector<char> cVec(10);                      // crea un vector de 10 caracteres
    unsigned int i,
                 lim = cVec.size();             // tama�o actual del vector

    cout << "VECTOR DE CARACTERES\n\nTama�o original = " << lim << endl;
    for(i=0; i<10; i++)
    {
        cVec[i] = i + 'a';                      // asigna valores consecutivos
    }
    vPrintVec(cVec, HORI);

    for(i=0; i<10; i++)
    {
        cVec.push_back(i  + 'A');               // agrego valores al final, crece solo
    }
    cout << "Nuevo tama�o = " << cVec.size() << endl;
    vPrintVec(cVec, HORI);

    cVec.pop_back();                            // extrae el �ltimo elemento
    vector<char>::iterator ForIter = cVec.begin();
    ForIter += 2;                               // apunta al 3er. elemento
    cVec.insert(ForIter, 3, 'X');               // inserta 3 X en las posiciones 2, 3 y 4
    cout << "Despu�s de la insertar 3 'X' (en la tercera posici�n): ";
    vPrintVec(cVec, HORI);
    cout << "Tama�o despu�s de la inserci�n = " << cVec.size() << endl;

    char car=cVec.front();                      // otra forma de obtener el primer elemento
    cout << "\nPrimer elemento: " << car;
    car=cVec.back();                            // otra forma de obtener el �ltimo elemento
    cout << ", �ltimo elemento: " << car << endl;

    cout << "\n\n\nVECTOR DE FLOTANTES\n";
    float f;
    vector<float> fVec;                         // crea un vector de flotantes
    for(i=0; i<7; i++)                          // no utilizar [i] porque est� vac�o
    {
        fVec.push_back(float(i * 3.1415927));   // agrego valores al final, crece solo
    }
    vPrintVec(fVec, VERT);

    f = *(fVec.end()-1);                        // accedo al �ltimo elemento
    cout << "�ltimo elemento  = " << f << endl;
    size_t tam = fVec.size();
    f = fVec[tam-2];                            // accedo al pen�ltimo elemento con []
    cout << "Pen�ltimo elemento  = " << f << endl;
    f = fVec.at(tam-3);                         // accedo al antepen�ltimo elemento con .at()
    cout << "Antepen�ltimo elemento  = " << f << endl;

    vector<float>::iterator fForIter;
    fForIter = fVec.begin();                    // iterador para flotantes

    fVec.insert(fForIter+2, fForIter, fForIter+4);
    cout << "\nSe inserta en la tercera posici�n las componentes 1�, 2�, 3� y 4�";
    vPrintVec(fVec, HORI);

    fForIter = fVec.begin() + 2;                               // tercer elemento
    fVec.erase(fForIter, fForIter+3);           // elimino componentes 3�, 4� y 5�
    cout << "\nSe eliminaron las componentes 3�, 4� y 5�";
    vPrintVec(fVec, HORI);

    return 0;
}



