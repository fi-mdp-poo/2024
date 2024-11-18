#include <iostream>
#include <vector>
#include "persona.h" // Asegúrate de que esta clase esté correctamente definida


#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

void imprimirVector(const vector<persona>& vec); // Declaración anticipada

int main()
{
    int res = 0;
    vector<persona> unvector;
    persona una_persona = persona();
    persona una_persona2 = persona("minombre2");


    // Supongamos que Getnombre() devuelve el nombre como string.
    //cout << una_persona.Getnombre() << endl;  // Imprime el nombre de la persona

    unvector.push_back(una_persona);
    unvector.push_back(una_persona2);
    unvector.push_back(persona("otrapersona22",225));
    unvector.emplace_back("down");


    imprimirVector(unvector);  // Imprime todos los nombres del vector



    fstream fileout;
    fileout.open("exit.txt", ios::out);             // abro el archivo para escritura
    fileout << una_persona.Getnombre() << " ; " << 22222 << endl; // escribo el texto y el número
    fileout.close();                            // cierro el archivo

    res = fileout.fail();
    if(res)
        cout << "Se produjo un error con el archivo" << endl;
    else
        cout << "No se produjeron errores con el archivo" << endl;

    cout << "\nTerminó la escritura " << endl;


    //fileout.open("exit.txt", ios::in);             // abro el archivo para escritura
    //fileout.close();

    ifstream fin("exit.txt");
    char ss[40],
         ch;
    int i = 0;

    while(fin.get(ch))
    {
        ss[i++] = ch;
    }
    cout << "\n\n\nNueva salida: " << ss << endl;

    fin.clear();
    fin.seekg(0);

    while(fin >> ch)
    {
        ss[i++] = ch;
    }
    cout << "\n\n\nOtra nueva salida: " << ss << endl;

    fin.close();



    return 0;
}

void imprimirVector(const vector<persona>& vec) {
    vector<persona>::const_iterator it;
    for (it = vec.begin(); it != vec.end(); ++it) {
        cout << it->Getnombre() << " ";  // Desreferenciar el iterador para acceder a persona
    }
    cout << endl;
}
