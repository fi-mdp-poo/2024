#include "fecha.h"
#include <iostream>
using namespace std;

int main() {
    Fecha fecha;
    
    // Prueba del constructor por defecto
    cout << "Fecha por defecto: ";
    fecha.imprimir_la();
    
    // Prueba de setFecha
    cout << "\nEstableciendo fecha usando setFecha(15, 7, 2023):" << endl;
    fecha.setFecha(15, 7, 2023);
    fecha.imprimir_la();
    
    // Prueba de los diferentes formatos de impresión
    cout << "\nDiferentes formatos de la misma fecha:" << endl;
    cout << "Formato latinoamericano: ";
    fecha.imprimir_la();
    cout << "Formato estadounidense: ";
    fecha.imprimir_us();
    cout << "Formato en letras: ";
    fecha.imprimir_letras();
    
    // Prueba de ingreso de fecha
    cout << "\nIngrese una nueva fecha:" << endl;
    fecha.ingresarFecha();
    
    cout << "\nFecha ingresada:" << endl;
    fecha.imprimir_la();
    fecha.imprimir_us();
    fecha.imprimir_letras();
    
    // Prueba de validación de fecha
    cout << "\nPrueba de validación con fecha inválida:" << endl;
    fecha.setFecha(31, 2, 2023); // 31 de febrero no existe
    
    return 0;
}