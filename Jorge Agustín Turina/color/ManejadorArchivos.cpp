#include "ManejadorArchivos.h"

    // Constructor: abre un archivo en modo texto o binario
    ManejadorArchivos::ManejadorArchivos(const string& nombre_archivo, const string& modo, const string& tipo)
    {
        try
        {
            if (tipo == "texto")
            {

                if (modo == "lectura")
                {
                    archivo_texto.open(nombre_archivo, ios::in);  // Modo solo lectura
                    if (!archivo_texto.is_open())
                    {
                        throw runtime_error("No se pudo abrir el archivo de texto para lectura: " + nombre_archivo);
                    }
                }
                else if (modo == "escritura")
                {
                    archivo_texto.open(nombre_archivo, ios::out | ios::app);  // Modo solo escritura
                    if (!archivo_texto.is_open())
                    {
                        throw runtime_error("No se pudo abrir el archivo de texto para escritura: " + nombre_archivo);
                    }
                }
                else
                {
                    throw invalid_argument("Modo no válido para texto: " + modo);
                }

            }
            else if (tipo == "binario")
            {

                if (modo == "lectura")
                {
                    archivo_binario.open(nombre_archivo, ios::in | ios::binary);  // Modo solo lectura binaria
                    if (!archivo_binario.is_open())
                    {
                        throw runtime_error("No se pudo abrir el archivo binario para lectura: " + nombre_archivo);
                    }
                }
                else if (modo == "escritura")
                {
                    archivo_binario.open(nombre_archivo, ios::out | ios::binary | ios::app);  // Modo solo escritura binaria
                    if (!archivo_binario.is_open())
                    {
                        throw runtime_error("No se pudo abrir el archivo binario para escritura: " + nombre_archivo);
                    }
                }
                else
                {
                    throw invalid_argument("Modo no válido para binario: " + modo);
                }

            }
            else
            {
                throw invalid_argument("Tipo de archivo no válido: " + tipo);
            }
        }
        catch (const exception& e)
        {
            cerr << "Error en el constructor archivos: " << e.what() << endl;
            throw;
        }
    }

    ManejadorArchivos::~ManejadorArchivos()
    {
            if (archivo_texto.is_open())
            {
                archivo_texto.close();
            }
            if (archivo_binario.is_open())
            {
                archivo_binario.close();
            }
    }



    string ManejadorArchivos::leer_texto()
    {
        try
        {
            string linea;
            if (archivo_texto.is_open())
            {
                if (getline(archivo_texto, linea))
                {
                    return linea;
                }
                else
                {
                    throw runtime_error("Error al leer del archivo de texto o fin de archivo alcanzado.");
                }
            }
            else
            {
                throw runtime_error("El archivo de texto no está abierto para lectura.");
            }
        }
        catch (const exception& e)
        {
            cerr << "Error al leer del archivo de texto: " << e.what() << endl;
            throw;
        }
    }




    fstream& ManejadorArchivos::getFlujoTexto()
    {
        if (!archivo_texto.is_open())
        {
            throw runtime_error("El archivo de texto no está abierto.");
        }
        return archivo_texto;
    }



    fstream& ManejadorArchivos::getFlujoBinario()
    {
        if (!archivo_binario.is_open())
        {
            throw runtime_error("El archivo binario no está abierto.");
        }
        return archivo_binario;
    }

