#include <iostream>

#include <iterator>
#include <stack>

using namespace std;

/**
 *  Implementar un programa que permita introducir una frase, escribiendo palabra por palabra,
 *  escribir la frase introducida y escribirla al revés.
 *
 *  Ejemplo:
 *  Ingrese una frase palabra por palabra, 0 para finalizar: hola, cómo estás?
 *  La frase al revés es: ¿sátse omóc ,aloh;
 */
int main() {
    cout << "Ingrese una frase palabra por palabra, 0 para finalizar:\n";

    istream_iterator<string> entrada(cin); // Lee frase desde la consola
    const istream_iterator<string> end;
    ostream_iterator<string> salida(cout, " ");

    stack<string> frase; // Contenedor temporal para almacenar frase

    while (*entrada != "0" && entrada != end) {
        frase.push(*entrada++); // Al hacer ++entrada, internamente queda pendiente del operador >>
    }

    string temp;

    cout << "\nLa frase al revés es: ";
    while (!frase.empty()) {
        temp = frase.top();
        *salida = string(temp.rbegin(), temp.rend());
        frase.pop();
    }

    return 0;
}
