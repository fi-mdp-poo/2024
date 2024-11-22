#ifndef PUBLICACION_H_INCLUDED
#define PUBLICACION_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>  // Para manejo de excepciones
#include <fstream>    // Para manejar archivos

using namespace std;

// Clase base para las publicaciones
class Publicacion {
    protected:
        string titulo;
        string autor;
        int ano_publicacion;

    public:
        // Constructor base
        Publicacion(const string& t, const string& a, int ano);

        // Método virtual para imprimir información (será sobrescrito en las clases derivadas)
        virtual void imprimir() const;

        // Métodos getters
        string getTitulo() const;
        string getAutor() const;
        int getAnoPublicacion() const;

        // Destructor virtual para permitir la correcta eliminación de objetos derivados
        virtual ~Publicacion() = default;
};

// Clase derivada: Libro
class Libro : public Publicacion {
    private:
        string genero;

    public:
        // Constructor del libro
        Libro(const string& t, const string& a, int ano, const string& g);

        // Sobrescribir el método imprimir
        void imprimir() const override {
            Publicacion::imprimir();  // Llamamos al método base
            cout << "Genero: " << genero << endl;
        }

        string getGenero() const;
};

// Clase derivada: Revista
class Revista : public Publicacion {
    private:
        int numero_edicion;

    public:
        // Constructor de la revista
        Revista(const string& t, const string& a, int ano, int num_ed);

        // Sobrescribir el método imprimir
        void imprimir() const override {
            Publicacion::imprimir();
            cout << "Numero de Edicion: " << numero_edicion << endl;
        }

        int getNumeroEdicion() const;
};

// Clase derivada: Periodico
class Periodico : public Publicacion {
    private:
        string ciudad;

    public:
        // Constructor del periódico
        Periodico(const string& t, const string& a, int ano, const string& c);

        // Sobrescribir el método imprimir
        void imprimir() const override {
            Publicacion::imprimir();
            cout << "Ciudad: " << ciudad << endl;
        }

        string getCiudad() const;
};

#endif // PUBLICACION_H_INCLUDED
