#include <iostream>
#include "MiExcepcion.h"

using namespace std;

float dividir(int a, int b);

int main(){
    int num1, num2;
    float resultado;

    cout << "Ingrese el numerador: ";
    cin >> num1;
    cout << "Ingrese el denominador: ";
    cin >> num2;

    try{
        resultado = dividir(num1, num2);
        cout << "El resultado es: " << resultado << endl;
    }
    catch(const DivisionPorCero& e){
        cout << "Error: " << e.what() << endl;
        cout << "Intento de dividir " << e.getNumerador() << " entre " << e.getDenominador() << "." << endl;
    }

    return 0;
}

float dividir(int a, int b){
    if(!b){
        throw DivisionPorCero(a, b);
    }
    return float(a) / float(b);
}
