#include <iostream>
#include <fstream>

using namespace std;
#include <vector>

struct Persona
{
    int id;
    char* nombre;
};



//namespace MiEspacioDeNombres
//{
class MiClase
{
public:
    union
    {
        unsigned valor;     //ej valor = 0x11223344
        unsigned char byte[4];  //byte[1]= 33, AL REVES EN MEMORIA
    }seleccion;
};
//}


// Función para crear un archivo binario
void crear_archivo_binario(const string& nombre_archivo)
{
    ofstream archivo(nombre_archivo, ios::binary);
    if (archivo.is_open())
    {
        // Escribir datos binarios en el archivo
        int datos_binarios[] = {1, 2, 3, 4, 5};
        archivo.write(reinterpret_cast<const char*>(datos_binarios), sizeof(datos_binarios));
        archivo.close();
        cout << "Archivo binario creado correctamente." << endl;
    }
    else
    {
        cerr << "No se pudo crear el archivo binario." << endl;
    }
}

// Función para crear un archivo de texto
void crear_archivo_texto(const string& nombre_archivo)
{
    ofstream* archivo_creado = new ofstream (nombre_archivo);
    ofstream& archivo = *archivo_creado;

    if (archivo_creado->is_open())
    {
        archivo << "Este es un archivo de texto." << endl;
        archivo << "Contiene algunas líneas de texto.y aaaaa4a?si4a" << endl;


        archivo_creado->close();
        delete archivo_creado; //lo pongo sin [] porque es un solo objeto, no varios como int[50]
        cout << "Archivo de texto creado correctamente." << endl;
    }
    else
    {
        cerr << "No se pudo crear el archivo de texto." << endl;
    }
}

ifstream* abrir_archivo(const string& nombre_archivo, const string& modo)
{
    ifstream* archivo = NULL;

    if (modo == "texto")
    {
        archivo = new ifstream(nombre_archivo);
    }
    if (modo == "binario")
    {
        archivo = new ifstream(nombre_archivo, ios::binary);
    }

    if (!archivo->is_open())
    {
        delete archivo;
        return NULL; // no se pudo abrir el archivo
    }

    archivo->seekg(0, ios::beg); //cursor al inicio del archivo
    return archivo;
}



//using namespace MiEspacioDeNombres;

int main()
{
    MiClase algo;
    algo.seleccion.valor = 0xAABBCCDD;
    unsigned aux = algo.seleccion.byte[0];
    char * p = new char[1];
    p[0] = 'x';
    p[1] = 'c';
    int m[2][3] = {{1, 2, 3}, {4, 5, 6}};
    cout << "m: " << sizeof(m) << " ";
    int* p1 = new int[6];
    cout << "p1: " << sizeof(p1);




    cout << hex << aux << dec<<endl;
    cout << hex << algo.seleccion.valor<< dec<<endl;
    cout << algo.seleccion.byte[0] << dec<<endl;
    cout << algo.seleccion.byte[1] << dec<<endl;
    cout << hex << algo.seleccion.byte[2] << dec<<endl;
    cout << hex << algo.seleccion.byte[3] << dec<<endl;

    // Crear archivos binario y de texto
    crear_archivo_binario("archivo_binario.bin");
    crear_archivo_texto("archivo_texto.txt");

    // Abrir y leer el archivo binario
    ifstream* archivo_binario = abrir_archivo("archivo_binario.bin", "binario");
    if (archivo_binario)
    {
        cout << "Contenido del archivo binario:" << endl;
        int dato;
        while (archivo_binario->read((char*)(&dato), sizeof(dato)))
        {
            cout << dato << " ";
        }
        cout << endl;

        archivo_binario->close();
        delete archivo_binario;
    }

    // Abrir y leer el archivo de texto
    ifstream* archivo_texto = abrir_archivo("archivo_texto.txt", "texto");
    if (archivo_texto)
    {
        cout << "Contenido del archivo de texto:" << endl;
        string linea;
        while (getline(*archivo_texto, linea))
        {
            cout << linea << endl;
        }

        archivo_texto->close();
        delete archivo_texto;
    }



    string nombreArchivo = "archivo_texto.txt";
    ifstream* archivo_texto2 = abrir_archivo(nombreArchivo, "texto");
    if (!archivo_texto2)
    {
        cout << "DI RE FALSO"<<endl;
    }
    string palabraClave = "o"; // Palabra clave para detener la lectura

    string linea = "";
    ifstream& aliasarchivo = *archivo_texto2;
    getline(aliasarchivo,linea,'o');
    cout << "encontre:"<< linea <<"fin"<<endl;
    getline(aliasarchivo,linea,'o');
    cout << "encontre:"<< linea <<"fin"<<endl;
    getline(*archivo_texto2,linea,'o');
    cout << "encontre:"<< linea <<"fin"<<endl;
    getline(*archivo_texto2,linea,'o');
    cout << "encontre:"<< linea <<"fin"<<endl;
    getline(*archivo_texto2,linea,'o');
    cout << "encontre:"<< linea <<"fin"<<endl;
    getline(*archivo_texto2,linea,'o');
    cout << "encontre:"<< linea <<"fin"<<endl; /// si llego al fin de linea mantiene lo que habia entontraod

    ifstream* archivoEntrada = abrir_archivo("personas.bin", "binario");

    Persona personas[2];


    for (int i = 0; i < 2; i++) {
        int longitudNombre;
        archivoEntrada->read((char*)(&longitudNombre), sizeof(longitudNombre));
        personas[i].nombre = new char[longitudNombre + 1];
        archivoEntrada->read(personas[i].nombre, longitudNombre);
        personas[i].nombre[longitudNombre] = '\0'; // Agregar el nulo al final
        archivoEntrada->read((char*)(&personas[i].id), sizeof(personas[i].id));
    }
    /// SALTEO LA PRIMER ESTRUCTURA
    /*
    cout << "antes de saltear : "<< archivoEntrada->tellg() << endl;
    archivoEntrada->seekg(1*sizeof(int)+8,ios::beg); ///tengo un entero y algo que ocupa 8 bytes

    cout<< endl<< endl << "en la linea hay:"<< archivoEntrada->tellg() <<endl<< endl;
    int longitudNombre;
    archivoEntrada->read((char*)(&longitudNombre), sizeof(longitudNombre));
    personas[0].nombre = new char[longitudNombre + 1];
    archivoEntrada->read(personas[0].nombre, longitudNombre);
    personas[0].nombre[longitudNombre] = '\0'; // Agregar el nulo al final
    archivoEntrada->read((char*)(&personas[0].id), sizeof(personas[0].id));
    */

    archivoEntrada->close();
    delete archivoEntrada;

    for (int i = 0; i < 2; i++)
    {
        std::cout << "ID: " << personas[i].id << std::endl;
        std::cout << "Nombre: " << personas[i].nombre << std::endl;
    }

    // Liberar la memoria asignada para los nombres
    for (int i = 0; i < 2; i++)
    {
        delete[] personas[i].nombre;
    }



    return 0;
}
