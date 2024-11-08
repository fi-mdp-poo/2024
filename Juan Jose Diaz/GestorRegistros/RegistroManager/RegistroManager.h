#ifndef REGISTROMANAGER_H
#define REGISTROMANAGER_H

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

template<typename T>
class RegistroManager {
    private:
        string _archivoActual;
        vector<T> _registros;
        size_t ultimaBusquedaIndex = 0;

        void _guardarRegistros() {
            ofstream archivo(_archivoActual);
            if (!archivo) {
                throw runtime_error("No se pudo escribir en el archivo.");
            }

            for (const auto& registro: _registros) {
                archivo << registro << endl;
            }

            archivo.close();
        }

    public:
        RegistroManager() = default;

        void nuevoArchivo(const string& nombreArchivo) {
            _archivoActual = nombreArchivo;
            ofstream archivo(_archivoActual, ios::trunc);
            if (!archivo) {
                throw runtime_error("No se pudo crear el archivo.");
            }

            cout << "Archivo " << _archivoActual << " creado exitosamente." << endl;
            archivo.close();
        }

        void abrirArchivo(const string& nombreArchivo) {
            _archivoActual = nombreArchivo;
            ifstream archivo(_archivoActual);
            if (!archivo.is_open()) {
                throw runtime_error("El archivo no existe o no se pudo abrir.");
            }

            T registro;
            while (archivo >> registro) {
                _registros.push_back(registro);
            }

            archivo.close();
            cout << "Archivo " << _archivoActual << " cargado exitosamente." << endl;
        }

        void agregarRegistro(const T& dato) {
            if (_archivoActual.empty()) {
                throw runtime_error("No hay un archivo abierto.");
            }

            _registros.push_back(dato);
            _guardarRegistros();
            cout << "Registro agregado exitosamente." << endl;
        }

        /**
         *
         * @param subcadena Criterio por el cual se va a buscar un registro.
         * @return Una referencia de un tipo T
         */
        T buscarRegistro(const string& subcadena) {
            T* encontrado = nullptr;
            const size_t longitud = _registros.size();
            size_t i = ultimaBusquedaIndex;

            while (!encontrado && i < longitud) {
                if (_registros[i]._nombre.find(subcadena) != string::npos) {
                    encontrado = &_registros[i];
                    ultimaBusquedaIndex = i + 1;
                }

                i++;
            }

            if (!encontrado) {
                throw runtime_error("No se encontró el registro");
            }

            return *encontrado;
        }

        bool modificarRegistro(const string& subcadena, const T& nuevoRegistro) {
            bool modificado = false;
            T* registro = buscarRegistro(subcadena);
            if (registro) {
                *registro = nuevoRegistro;
                _guardarRegistros();
                cout << "Registro modificado exitosamente." << endl;
                modificado = true;
            }

            return modificado;
        }

        bool eliminarRegistro(const string& subcadena) {
            bool eliminado = false;
            size_t i = 0;


            while (!eliminado && _registros.size() > 0 && i < _registros.end()) {
                if (_registros[0]._nombre.find(subcadena) != string::npos) {
                    _registros.erase(_registros.begin());
                    _guardarRegistros();
                    cout << "Registro eliminado exitosamente." << endl;
                    eliminado = true;
                }

                i++;
            }

            return eliminado;
        }
};

#endif //REGISTROMANAGER_H
