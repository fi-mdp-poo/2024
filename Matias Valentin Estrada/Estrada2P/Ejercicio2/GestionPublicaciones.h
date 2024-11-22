#ifndef GESTIONPUBLICACIONES_H_INCLUDED
#define GESTIONPUBLICACIONES_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>  // Para manejo de excepciones
#include <fstream>    // Para manejar archivos

using namespace std;

// Clase para gestionar la lista de publicaciones
template <typename T>
class GestionPublicaciones {
    private:
        vector<T> publicaciones;

    public:
        // Agregar una nueva publicaci�n
        void agregar(const T& pub) {
            publicaciones.push_back(pub);
        }

        // Buscar una publicaci�n por t�tulo
        T* buscarPorTitulo(const string& titulo) {
            for (auto& pub : publicaciones) {
                if (pub.getTitulo() == titulo) {
                    return &pub;
                }
            }
            return nullptr;  // Si no se encuentra
        }

        // Eliminar una publicaci�n por t�tulo
        bool eliminarPorTitulo(const string& titulo) {
            for (auto it = publicaciones.begin(); it != publicaciones.end(); ++it) {
                if (it->getTitulo() == titulo) {
                    publicaciones.erase(it);
                    return true;
                }
            }
            return false;  // Si no se encuentra
        }

        // Modificar una publicaci�n
        bool modificarPorTitulo(const string& titulo, const T& nuevaPub) {
            for (auto& pub : publicaciones) {
                if (pub.getTitulo() == titulo) {
                    pub = nuevaPub;
                    return true;
                }
            }
            return false;  // Si no se encuentra
        }

        // Imprimir todas las publicaciones
        void imprimirTodo() const {
            for (const auto& pub : publicaciones) {
                pub.imprimir();
                cout << "---------------------" << endl;
            }
        }
};

#endif // GESTIONPUBLICACIONES_H_INCLUDED
