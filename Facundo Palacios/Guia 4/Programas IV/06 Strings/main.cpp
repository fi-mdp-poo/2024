#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{
    ofstream fout("Strings.txt");                                   // abro el archivo para escritura
    if(!fout)
    {
        perror("No puedo abrir el archivo ");
        exit(1);                                                    // termina el programa con un código de error
    }

    string str = "objeto de la clase string";
    const char *ptr1, *ptr2;

    cout << "Objeto str original: " << str << endl << endl;
    fout << "Objeto str original: " << str << endl << endl;         // MISMO FORMATO CONSOLA QUE ARCHIVO!!
    str+=  " concatenado";
    cout << "Objeto str modificado: " << str << endl << endl << endl;
    fout << "Objeto str modificado: " << str << endl << endl << endl;

    /* *** obtener la cadena de caracteres del objeto string *** */
    ptr2 = str.data();
    ptr1 = str.c_str();
    cout << "Se obtienen los datos del objeto string:\nMediante el metodo c_str() = " <<
            ptr1 << "\nMediante el metodo data()  = " << ptr2 << endl << endl<< endl;
    fout << "Se obtienen los datos del objeto string:\nMediante el metodo c_str() = " <<
            ptr1 << "\nMediante el metodo data()  = " << ptr2 << endl << endl<< endl;

    /* *** conversiones de numeros a string mediante objetos stringstream *** */
    int numi = 59;
    float numf = 378.123456789;
    stringstream ss1, ss2;

    ss1 << "Numero entero a texto = " << numi << endl;
    ss2 << "Numero flotante a texto = " << numf << endl;
    cout << ss1.str() << ss2.str() << endl;
    fout << ss1.str() << ss2.str() << endl;
    ss2.precision(5);
    ss2.str("");
    ss2 << "Numero flotante con 5 digitos en total = " << numf << " (.precision)\n";
    cout << ss2.str();
    fout << ss2.str();
    ss2.setf(ios::fixed);
    ss2.str("");
    ss2 << "Numero flotante con 5 digitos decimales = " << numf << " (.setf(ios::fixed))\n\n\n";
    cout << ss2.str();
    fout << ss2.str();

    /* *** formas equivalentes a las utilizadas por printf/fprintf *** */
    cout << "Ajusta el ancho de salida a 10 caracteres y completa con '_'\n1234567890\n";
    fout << "Ajusta el ancho de salida a 10 caracteres y completa con '_'\n1234567890\n";
    ss1.str("");
    ss1.width(10);
    ss1.fill('_');
    ss1 << numi << " alineado a la derecha" << endl;
    cout << ss1.str();
    fout << ss1.str();
    ss1.setf(ios::left);
    ss1.width(10);
    ss1.str("");
    ss1 << numi << " alineado a la izquierda" << endl;
    cout << ss1.str();
    fout << ss1.str();
    ss2.str("");
    ss2.width(10);
    ss2 << ptr2 << " (ancho = 10 pero no se trunca)" << endl << endl << endl;
    cout << ss2.str();
    fout << ss2.str();

    /* *** conversion de texto a numero *** */
    ss1.str("1976");
    ss1 >> numi;
    ss2.str("-2.18e-07");
    ss2 >> numf;
    // Salida directa a pantalla y disco de un entero
    cout << "Sumo 2 a numi = " << (numi + 2) << endl;
    fout << "Sumo 2 a numi = " << (numi + 2) << endl;
    // Salida en formato hexadecimal a pantalla y disco
    cout << numi << " en hexadecimal es: ";
    cout.flags(ios::hex | ios::showbase | ios::uppercase);
    cout << numi << endl;
    fout << numi << " en hexadecimal es: ";
    fout.flags(ios::hex | ios::showbase | ios::uppercase);
    fout << numi << endl;
    // Salida directa a pantalla y disco de un flotante
    cout << "Multiplico por 3 a numf = " << (numf * 3) << endl << endl << endl ;
    fout << "Multiplico por 3 a numf = " << (numf * 3) << endl;


    fout.close();                                   // cierro el archivo

    return 0;
}
