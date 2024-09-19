#include <iostream>
#include "c_string.h"

int main() {
    // Crear cadenas
    c_string str1("Hello");
    c_string str2("World");
    
    // Prueba de longitud
    std::cout << "Length of str1: " << str1.length() << std::endl;  // Debería ser 5
    std::cout << "Length of str2: " << str2.length() << std::endl;  // Debería ser 5

    // Prueba de concatenación
    c_string str3 = str1 + str2;
    std::cout << "Concatenation of str1 and str2: " << str3 << std::endl;  // Debería imprimir "HelloWorld"

    // Prueba de búsqueda de carácter
    char searchChar = 'o';
    int32_t index = str1.find(searchChar);
    std::cout << "Index of character '" << searchChar << "' in str1: " << index << std::endl;  // Debería ser 4

    // Prueba de búsqueda de subcadena
    c_string subStr("llo");
    int32_t subStrIndex = str1.find(subStr);
    std::cout << "Index of substring \"llo\" in str1: " << subStrIndex << std::endl;  // Debería ser 2

    // Prueba de comparación de igualdad
    c_string str4("Hello");
    std::cout << "str1 == str4: " << (str1 == str4 ? "true" : "false") << std::endl;  // Debería ser true
    std::cout << "str1 == str2: " << (str1 == str2 ? "true" : "false") << std::endl;  // Debería ser false

    // Prueba de comparación de desigualdad
    std::cout << "str1 != str4: " << (str1 != str4 ? "true" : "false") << std::endl;  // Debería ser false
    std::cout << "str1 != str2: " << (str1 != str2 ? "true" : "false") << std::endl;  // Debería ser true

    // Prueba de asignación
    c_string str5("Initial");
    std::cout << "Before assignment, str5: " << str5 << std::endl;  // Debería imprimir "Initial"

    str5 = str3;  // Asigna str3 a str5
    std::cout << "After assignment, str5: " << str5 << std::endl;  // Debería imprimir "HelloWorld"

    return 0;
}