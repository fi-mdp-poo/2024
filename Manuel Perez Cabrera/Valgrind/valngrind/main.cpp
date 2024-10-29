#include <iostream>

int main()
{
    int* arr = new int[10];  // Reserva memoria para un array de 10 enteros

    // Inicializar el array
    for (int i = 0; i < 10; ++i) {
        arr[i] = i;
    }

    // Imprimir los valores del array
    for (int i = 0; i < 10; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Aquí falta liberar la memoria
    // delete[] arr;

    return 0;
}
