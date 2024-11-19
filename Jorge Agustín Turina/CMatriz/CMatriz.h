#ifndef CMATRIZ_
#define CMATRIZ_
#include <ostream>
using namespace std;
class CMatriz
{
    public:
        CMatriz(int = 5, int = 5, unsigned int* = nullptr);
        virtual ~CMatriz();

        unsigned int Getfilas() { return filas; }
        void Setfilas(unsigned int val) { filas = val; }
        unsigned int Getcolumnas() { return columnas; }
        void Setcolumnas(unsigned int val) { columnas = val; }
        unsigned int* Getdatos() { return datos; }
        void Setdatos(unsigned int* val) { datos = val; }

        void cargar(char*);
        CMatriz& operator=(const CMatriz& other);  // Sobrecarga de asignación
        friend ostream& operator<<(ostream& os, const CMatriz& m);  // Sobrecarga de <<
        CMatriz& operator+=(const CMatriz& other);  // Sobrecarga de asignación
        CMatriz& operator+(const CMatriz& other);  // Sobrecarga de asignación


    protected:

    private:
        unsigned int filas;
        unsigned int columnas;
        unsigned int* datos;
};

#endif // CMATRIZ_
