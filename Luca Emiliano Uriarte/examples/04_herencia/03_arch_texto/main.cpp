#include <fstream>
#include <sstream>
#include <iostream>
#include <windows.h>

using namespace std;

bool fexists(const char *fname);                         // true ==> existe; false ==> no existe

int main()
{
    SetConsoleOutputCP(1252);
    SetConsoleCP(1252);

    string texto = "pirulo prueba letras ñ Ñ á é í ó ú";
    char nombre[] = "Archivos\\datos.txt";
    int numero = 10,
        res;

    /* *** se puede invocar la línea de comandos (DOS) *** */
    system("if not exist Archivos md Archivos");

    /* *** determino si el archivo ya exite *** */
    if(fexists(nombre))
        cout << "Ese archivo ya existe se va a sobrescribir\n" << endl;
    else
        cout << "El archivo no existe, se crea\n" << endl;

    /* *** prueba de escritura en disco *** */
    ofstream fileout;
    fileout.open(nombre, ios::out);             // abro el archivo para escritura
    fileout << texto << "; " << numero << endl; // escribo el texto y el número
    fileout << (numero + 20) << endl;           // nuevo valor en nueva línea
    fileout.close();                            // cierro el archivo

    res = fileout.fail();
    if(res)
        cout << "Se produjo un error con el archivo" << endl;
    else
        cout << "No se produjeron errores con el archivo" << endl;

    cout << "\nTerminó la escritura " << endl;
    texto.clear();                              // borra el string
    cout << "\nEl string ahora es: " << texto << endl;

    /* *** prueba de lectura desde disco *** */
    ifstream file;
    file.open(nombre);                        // no hace falta ios::in porque el objeto es ifstream

//    char aux[50];
//    file.getline(aux, 50, ';'); // se lee hasta el carácter (;)
//    texto = aux;
    getline(file, texto, ';');                  // equivalente a las 3 líneas comentadas antes

    file >> numero;                             // se lee el primer número
    cout << "\n\nEl texto leido es: " << "\"" << texto << "\""
         << "\ny el numero leido es: " << numero << endl;

    file >> numero;                             // se lee el segundo número
    cout << "\nEl segundo número es: " << numero << endl;
    file.close();                               // cierro el archivo de lectura

    numero = 128;
    fileout.open(nombre, ios::app);             // abro el archivo append = agrego información
    fileout << "Nueva información = " << numero << endl;
    fileout.close();                            // cierro el archivo

    return 0;
}

bool fexists(const char *fname)
{
    ifstream file;
    file.open(fname);       // no hace falta ios::in porque el objeto es ifstream
                            // si open falla el stream adopta un valor falso
    if (file)               // si el stream es verdadero se pudo hacer la apertura
    {
        file.close();
        return true;
    }

    return false;
}
