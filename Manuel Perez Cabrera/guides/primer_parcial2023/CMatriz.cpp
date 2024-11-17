#include "CMatriz.h"

CMatriz::CMatriz()
{
    //ctor
}

CMatriz::~CMatriz()
{
    //dtor
}

unsigned int CMatriz::Get_columnas()
{
    return columnas;
}
unsigned int CMatriz::Get_filas()
{
    return filas;
}
void CMatriz::Set_filas(unsigned int f)
{
    filas = f;
}
void CMatriz::Set_columnas(unsigned int c)
{
    columnas = c;
}


void CMatriz::cargar(string nombre_archivo)
{

    ifstream* archivo = new ifstream(nombre_archivo, ios::binary);

    if (!archivo->is_open())
    {
        delete archivo;
        return ;                  // no se pudo abrir el archivo
    }

    archivo->seekg(0, ios::beg);  //cursor al inicio del archivo

    if (archivo)
    {
        cout << "Contenido del archivo binario:" << endl;
        unsigned int  dato;
        unsigned int  v[2];

        for (int i = 0 ; i<2 ; i++)
        {
            archivo->read((char*)(&dato), sizeof(dato)); /// porque aca va un char*
            v[i] = dato ;

            cout << v[i] << " ";
        }


        matriz = new unsigned int*[ v[0] + 1 ] ;
        for (int i = 0; i < v[0] ; i++)
        {
            matriz[i] = new unsigned int[ v[i] + 1 ];
        }

        for (int i = 0 ; i < v[0] ; i ++)
        {
            for (int j = 0 ; j < v[1] ; j ++)
            {
                archivo->read((char*)(&dato), sizeof(dato));
                matriz[i][j] = dato;

            }
        }


        cout << endl;

        Set_filas(v[0]);
        Set_columnas(v[1]);


        archivo->close();
        delete archivo;
    }

}


ostream& operator << (ostream& os, CMatriz& m)
{

    unsigned int f = m.Get_filas();
    unsigned int c = m.Get_columnas();

    for (unsigned int i = 0; i < f; i++)
    {
        for (unsigned int j = 0; j < c; j++)
        {
            os << std::hex << std::uppercase  // Formato hexadecimal en mayúsculas
               << std::setw(8)                // Ancho fijo de 8 caracteres
               << std::setfill(' ')           // Relleno con espacios
               << m.matriz[i][j] << "   ";    // Espaciado extra entre columnas
        }
        os << std::endl;                      // Nueva línea después de cada fila
    }

    return os;
}
