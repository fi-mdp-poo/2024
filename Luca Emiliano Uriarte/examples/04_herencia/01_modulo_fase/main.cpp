#include <iostream>
#include <fstream>
#include "polar.h"

using namespace std;

int main()
{
    complejo comp1(3.1, 4.2),
             comp2;
    polar pol1(5.0, 6.0),
          pol2(3.0, 45.0, true),
          pol3(comp1),
          pol4,
          suma, prod;
    double producto;

    pol4.SetReal(6.0);
    pol4.SetImag(-6.0);
    pol4.ToPolar();

    cout << "pol1 = " << complejo(pol1) << ", "
         << "\tpol2 = " << pol2 << ", "
         << "\tpol3 = " << complejo(pol2) << "\n\n";

    ofstream fout;
    fout.open("polares.txt"); //, ios::out);        // abro el archivo para escritura es ofstream
    fout << "pol1 = " << complejo(pol1) << ", "
         << "\tpol2 = " << pol2 << ", "
         << "\tpol3 = " << complejo(pol2) << "\n\n";


    cout << "Nueva prueba de salida: " << comp1 << "\n\n";
    fout << "Nueva prueba de salida: " << comp1 << "\n\n";

    suma = pol1 + pol2;
    pol1+= pol2;
    pol1.ToPolar();      // porque no sobrecargo el operador += (usa el de complejos y no actualiza mod y fase
                         // verificar que la suma da bien pero es distino el modulo y fase pol1!=suma
    prod = 3.1 * pol4;
    pol3*= 5.2;
    producto = pol4 * pol3;

    cout << "3.1*pol4 = " << prod << "\n"
         << "pol3*5.2 = " << pol3 << "\n"
         << "pol4*pol3 (escalar) = " << producto << "\n\n";

    fout << "3.1*pol4 = " << prod << "\n"
         << "pol3*5.2 = " << pol3 << "\n"
         << "pol4*pol3 (escalar) = " << producto << "\n\n";

    if(pol1!=pol2)           // operador != definido en complejos
        cout << pol1 << " es distinto de " << pol2 << "\n\n";

    if(pol3==pol3)           // operador == definido en complejos
        cout << pol3 << " es igual a " << pol3 << "\n\n";

    fout.close();
    return 0;
}
