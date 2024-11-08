#include <iostream>
#include <fstream>

using namespace std;

class ExcepDeriv : public exception                 // derivo de la clase exception
{
    public:
        ExcepDeriv(int mot) : exception(), motivo(mot) {}
        const char* what() const throw();           // sobrescribo el método what(), que es virtual
    private:
        int motivo;                                 // código del error
};

const char* ExcepDeriv :: what() const throw()
{
   switch(motivo)
   {
       case 1:
           return "Fichero de origen no existe";
       case 2:
           return "No es posible abrir el fichero de salida";
   }
   return "Error inesperado";
}

void CopiaFichero(const char* Origen, const char *Destino)
{
    ifstream fe(Origen, ios::in | ios::binary);
    if( !fe.good() )
        throw ExcepDeriv(1);                    // se produce un error en la apertura del archivo fuente

    ofstream fs(Destino, ios::out | ios::binary);
    if( !fs.good() )
        throw ExcepDeriv(2);                    // se produce un error en el archivo destino (SOLO LECTURA)

    fe.seekg(0, ios::end);
    streampos cnt = fe.tellg();
    fe.seekg(0, ios::beg);

    char *buffer = new char[cnt];
    fe.read(buffer, cnt);
    fs.write(buffer, cnt);

    fe.close();
    fs.close();
    delete [] buffer;
}

int main()
{
//    char Desde[] = "excepcion.cpp";      // no existe, cambiar por main.cpp
    char Desde[] = "main.cpp";
    char Hacia[] = "excepcion.cpy";      // poner propiedades en Read Only --> error

    try
    {
        CopiaFichero(Desde, Hacia);
    }
    catch(ExcepDeriv &ex)                        // pasa la excepcion por referencia
    {
        cout << ex.what() << endl;
    }

    return 0;
}

