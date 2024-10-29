/****EJERCICIO 2***/

#include <iostream>
#include "MiExcepcion.h"

using namespace std;

int dividir(int a, int b);

int main(){
    int num1, num2, resultado;

    cout << "Ingrese el numerador: ";
    cin >> num1;
    cout << "Ingrese el denominador: ";
    cin >> num2;

    try{
        resultado = dividir(num1, num2);
        cout << "El resultado es: " << resultado << endl;
    }
    catch(const MiExcepcion& e){
        cout << "Error: " << e.what() << endl;
        cout << "Intento de dividir " << e.getNumerador() << " entre " << e.getDenominador() << "." << endl;
    }

    return 0;
}

int dividir(int a, int b){
    if (!b){
        throw MiExcepcion(a, b);
    }
    return a / b;
}


/*****EJERCICIO 3*****/
/*
    } catch (const MiExcepcion& e) {
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << "Intento de dividir " << e.getNumerador() << " entre " << e.getDenominador() << "." << std::endl;
    }

    return 0;
}
*/


/****EJERCICIO 4****/
/*
#include <iostream>
#include <stdexcept> // Para std::runtime_error

// Excepción base
class MiExcepcion : public std::runtime_error {
public:
    MiExcepcion(const std::string& mensaje)
        : std::runtime_error(mensaje) {}
};

// Excepción derivada para división por cero
class DivisionPorCero : public MiExcepcion {
public:
    DivisionPorCero(int numerador, int denominador)
        : MiExcepcion("División por cero no permitida."), num(numerador), den(denominador) {}

    int getNumerador() const { return num; }
    int getDenominador() const { return den; }

private:
    int num; // Para almacenar el numerador
    int den; // Para almacenar el denominador
};

// Excepción derivada para otro tipo de error (por ejemplo, error en los datos)
class ErrorDeDatos : public MiExcepcion {
public:
    ErrorDeDatos(const std::string& mensaje)
        : MiExcepcion(mensaje) {}
};

int dividir(int a, int b) {
    if (b == 0) {
        throw DivisionPorCero(a, b);
    }
    return a / b;
}

int main() {
    int num1, num2;

    std::cout << "Ingrese el numerador: ";
    std::cin >> num1;
    std::cout << "Ingrese el denominador: ";
    std::cin >> num2;

    try {
        if (num2 < 0) {
            throw ErrorDeDatos("El denominador no puede ser negativo.");
        }
        int resultado = dividir(num1, num2);
        std::cout << "El resultado es: " << resultado << std::endl;
    } catch (const DivisionPorCero& e) {
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << "Intento de dividir " << e.getNumerador() << " entre " << e.getDenominador() << "." << std::endl;
    } catch (const MiExcepcion& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
*/
