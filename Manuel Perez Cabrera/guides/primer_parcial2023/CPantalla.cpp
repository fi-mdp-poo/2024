#include "CPantalla.h"

CPantalla::CPantalla(CMatriz& m)
{
    filas = m.Get_filas();
    columnas = m.Get_columnas();

    matriz = new unsigned int*[filas];
    for (int i = 0 ; i < filas; i ++)
    {
        matriz[i] = new unsigned int [columnas];
    }

    for (int i = 0 ; i < filas ; i ++)
    {
        for (int j = 0 ; j < columnas ; j ++)
        {
            matriz[i][j] = m.Get_component_matriz(i,j);
        }
    }
}

CPantalla::~CPantalla()
{
    //dtor
}

unsigned int CPantalla::Get_columnas()const
{
    return columnas;
}
unsigned int CPantalla::Get_filas()const
{
    return filas;
}
void CPantalla::Set_filas(unsigned int f)
{
    filas = f;
}
void CPantalla::Set_columnas(unsigned int c)
{
    columnas = c;
}


ostream& operator << (ostream& os, CPantalla& m)
{

    unsigned int f = m.Get_filas();
    unsigned int c = m.Get_columnas();
    os  << "AARRGGBB"
        << "   "
        << "AARRGGBB"
        << "   "
        << "AARRGGBB"
        << "   "
        << "AARRGGBB"
        << "   "
        << "AARRGGBB"
        << "   "
        << "AARRGGBB"
        << "   "
        << "AARRGGBB"
        << "   "
        << "AARRGGBB"
        <<endl<<endl;
    for (unsigned int i = 0; i < f; i++)
    {
        for (unsigned int j = 0; j < c; j++)
        {
            os << std::hex << std::uppercase  // Formato hexadecimal en mayúsculas
               << std::setw(8)                // Ancho fijo de 8 caracteres
               << std::setfill('0')           // Relleno con espacios
               << m.matriz[i][j] << "   ";    // Espaciado extra entre columnas
        }
        os << std::endl;                  // Nueva línea después de cada fila
    }

    return os;

}

void CPantalla::ajustarColor(int valor)
{

    unsigned int mask_lower_bytes = 0x00FFFFFF;  // Conserva los 3 bytes menos significativos
    unsigned int mask_higher_byte = 0xFF000000;  // Conserva solo el último byte (más significativo)
    unsigned int c;

    for (int i = 0; i < Get_filas(); i++)
    {
        for (int j = 0; j < Get_columnas(); j++)
        {
            // Obtiene el valor original
            c = matriz[i][j];

            // Extrae los bytes menos significativos
            unsigned int lower_bytes = c & mask_lower_bytes;

            // Extrae el último byte, le suma el valor y asegura que sigue siendo un byte
            unsigned int higher_byte = ((c & mask_higher_byte) >> 24) + valor;
            higher_byte = (higher_byte & 0xFF) << 24;  // Mantener solo el byte más significativo

            // Combina los valores
            matriz[i][j] = lower_bytes | higher_byte;
        }
    }
}

void CPantalla::borrarVerde()
{
     for (int i = 0; i < Get_filas(); i++)
    {
        for (int j = 0; j < Get_columnas(); j++)
        {
           matriz[i][j] = matriz[i][j] & 0xFFFF00FF;
        }
    }

}

void CPantalla::reforzarRojo(float valor)
{
     for (int i = 0; i < Get_filas(); i++)
    {
        for (int j = 0; j < Get_columnas(); j++)
        {
            unsigned int c = matriz[i][j] & 0x00FF0000;
            unsigned int d = matriz[i][j];
            c = (c >> 2*8) * valor;
            c = c << 2*8 ;
            d = d & 0xFF00FFFF;
            matriz[i][j] = d | c;

        }
    }
}

unsigned int** CPantalla::getPtr()
{
    return matriz ;
}
