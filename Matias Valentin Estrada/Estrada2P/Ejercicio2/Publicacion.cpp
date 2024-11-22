#include "Publicacion.h"

Publicacion::Publicacion(const string& t, const string& a, int ano): titulo(t), autor(a), ano_publicacion(ano) {}

void Publicacion::imprimir() const {
    cout << "Titulo: " << titulo << ", Autor: " << autor << ", Año: " << ano_publicacion << endl;
}

string Publicacion::getTitulo() const{
    return titulo;
}

string Publicacion::getAutor() const{
    return autor;
}

int Publicacion::getAnoPublicacion() const {
    return ano_publicacion;
}


Libro::Libro(const string& t, const string& a, int ano, const string& g): Publicacion(t, a, ano), genero(g) {}

string Libro::getGenero() const {
    return genero;
}


Revista::Revista(const string& t, const string& a, int ano, int num_ed) : Publicacion(t, a, ano), numero_edicion(num_ed) {}

int Revista::getNumeroEdicion() const {
    return numero_edicion;
}


Periodico::Periodico(const string& t, const string& a, int ano, const string& c) : Publicacion(t, a, ano), ciudad(c) {}

string Periodico::getCiudad() const {
    return ciudad;
}
