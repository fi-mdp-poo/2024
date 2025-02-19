// Definimos un functor que realiza una suma
#include <iostream>

class Sumar {
public:
    int d =4;

    // Sobrecarga del operador () para que funcione como una función
    int operator()(int a, int b) {

        d = a + b + d;

        return d;
    }
};

using namespace std ;

int main() {
    Sumar s; // Creamos un objeto de tipo Sumar

    // Usamos el objeto como si fuera una función
    int resultado = s(3, 5); // Llamada al operador () que realiza la suma

    resultado = s(3,5);


    cout << "El resultado de la suma es: " << resultado <<endl;

     resultado = s(3,5);
    cout << "El resultado de la suma es: " << resultado <<endl;

    return 0;
}
