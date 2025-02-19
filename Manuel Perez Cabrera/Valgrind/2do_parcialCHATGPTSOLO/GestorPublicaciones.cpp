#include "GestorPublicaciones.h"
#include <fstream>

// Destructor para liberar memoria
GestorBiblioteca::GestorBiblioteca()
{

}

GestorBiblioteca::~GestorBiblioteca()
{
    for (auto publicacion : publicaciones)
    {
        delete publicacion;
    }
    publicaciones.clear();
}

// M�todo para agregar una publicaci�n al gestor
void GestorBiblioteca::agregarPublicacion(Publicacion* publicacion)
{
    publicaciones.push_back(publicacion);
}

// M�todo para buscar una publicaci�n por t�tulo
Publicacion* GestorBiblioteca::buscarPorTitulo(const std::string& titulo) const
{
    for (auto it = publicaciones.begin(); it != publicaciones.end(); ++it)
    {
        if ((*it)->getTitulo() == titulo)
        {
            return *it;
        }
    }
    throw std::runtime_error("Publicaci�n no encontrada: " + titulo);
}

// M�todo para eliminar una publicaci�n por t�tulo
void GestorBiblioteca::eliminarPorTitulo(const std::string& titulo)
{
    for (auto it = publicaciones.begin(); it != publicaciones.end(); ++it)
    {
        if ((*it)->getTitulo() == titulo)
        {
            delete *it; // Liberar memoria
            publicaciones.erase(it);
            return;
        }
    }
    throw std::runtime_error("No se pudo eliminar. Publicaci�n no encontrada: " + titulo);
}

// M�todo para mostrar todas las publicaciones
void GestorBiblioteca::mostrarPublicaciones() const
{
    if (publicaciones.empty())
    {
        std::cout << "No hay publicaciones en la biblioteca." << std::endl;
        return;
    }
    for (auto it = publicaciones.begin(); it != publicaciones.end(); ++it)
    {
        (*it)->mostrarInformacion();
        std::cout << "---------------------" << std::endl;
    }
}

// M�todo para guardar publicaciones en un archivo de texto
void GestorBiblioteca::guardarEnArchivo(const std::string& nombreArchivo) const
{
    std::ofstream archivo(nombreArchivo);
    if (!archivo)
    {
        throw std::ios_base::failure("Error al abrir el archivo para escritura: " + nombreArchivo);
    }
    for (auto it = publicaciones.begin(); it != publicaciones.end(); ++it)
    {
        (*it)->guardarEnArchivo(archivo);
    }
    archivo.close();
}

// M�todo para cargar publicaciones desde un archivo de texto
void GestorBiblioteca::cargarDesdeArchivo(const std::string& nombreArchivo)
{


    std::ifstream archivo(nombreArchivo);
    if (!archivo)
    {
        throw std::ios_base::failure("Error al abrir el archivo para lectura: " + nombreArchivo);
    }



    while (!archivo.eof())
    {
        string basura;
        std::getline(archivo, basura);

        if (basura == "Libro")
        {
            Publicacion* pub = new Libro(); // Cambiar seg�n la l�gica de tipo
            pub->cargarDesdeArchivo(archivo);
            if (archivo)   // Evitar agregar objetos incompletos al final del archivo
            {
                publicaciones.push_back(pub);
            }
             else
            {
                delete pub; // Liberar memoria si la lectura falla
            }

        }
        if (basura == "Revista")
        {
            Publicacion* pub = new Revista(); // Cambiar seg�n la l�gica de tipo
            pub->cargarDesdeArchivo(archivo);
            if (archivo)   // Evitar agregar objetos incompletos al final del archivo
            {
                publicaciones.push_back(pub);
            }
             else
            {
                delete pub; // Liberar memoria si la lectura falla
            }

        }


    }
    archivo.close();
}
