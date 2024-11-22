#ifndef MANEJADORARCHIVOS_H
#define MANEJADORARCHIVOS_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>  // Para excepciones estándar

using namespace std;

class ManejadorArchivos
{
public:
    // Constructor: abre un archivo en modo texto o binario
    ManejadorArchivos(const string& nombre_archivo, const string& modo, const string& tipo);

    ~ManejadorArchivos();



    string leer_texto();

    fstream& getFlujoTexto();

    fstream& getFlujoBinario();


    template <typename T>
    void escribir_texto(const T& dato)
    {
        try
        {
            if (archivo_texto.is_open())
            {
                archivo_texto << dato << endl;
            }
            else
            {
                throw runtime_error("El archivo de texto no está abierto para escritura.");
            }
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error al escribir en el archivo de texto: " << e.what() << std::endl;
            throw;
        }
    }


    template<typename T>
    void escribir_binario(const T& dato)
    {
        try
        {
            if (archivo_binario.is_open())
            {
                archivo_binario.write(reinterpret_cast<const char*>(&dato), sizeof(dato));
                if (!archivo_binario)
                {
                    throw runtime_error("Error al escribir en el archivo binario.");
                }
            }
            else
            {
                throw runtime_error("El archivo binario no está abierto para escritura.");
            }
        }
        catch (const exception& e)
        {
            cerr << "Error al escribir en el archivo binario: " << e.what() << endl;
            throw;
        }
    }


    template<typename T>
    T leer_binario()
    {
        try
        {
            T dato;
            if (archivo_binario.is_open())
            {
                archivo_binario.read(reinterpret_cast<char*>(&dato), sizeof(dato));
                if (!archivo_binario)
                {
                    throw runtime_error("Error al leer del archivo binario.");
                }
            }
            else
            {
                throw runtime_error("El archivo binario no está abierto para lectura.");
            }
            return dato;
        }
        catch (const exception& e)
        {
            cerr << "Error al leer del archivo binario: " << e.what() << endl;
            throw;
        }
    }




private:
    fstream archivo_texto;
    fstream archivo_binario;
};

#endif // MANEJADORARCHIVOS_H

