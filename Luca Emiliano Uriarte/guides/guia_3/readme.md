# Guia 3

## Ejercicio 1: Operaciones con Números Complejos

1. Escriba un programa en C++ que permita realizar operaciones con números complejos: suma, resta, multiplicación y división. Además, a cualquier número complejo se le puede pedir su módulo y ángulo. Este último deberá pertenecer al intervalo [0, 2π].

## Ejercicio 2: Salida del Programa

2. Observe el programa que sigue y piense cuál será su salida. Luego, escriba el código en su IDE favorito, compile y ejecute para verificar lo que usted pensó.
    ```cpp
    #include <string>
    #include <iostream>
    using namespace std;

    int main()
    {
        string bigNews("I saw Elvis in a UFO. ");
        cout << bigNews << endl;

        // How much data have we actually got?
        cout << "Size = " << bigNews.size() << endl;

        // How much can we store without reallocating?
        cout << "Capacity = " << bigNews.capacity() << endl;

        // Insert this string in bigNews immediately before bigNews[1]
        bigNews.insert(1, " thought I");
        cout << bigNews << endl;

        cout << "Size = " << bigNews.size() << endl;
        cout << "Capacity = " << bigNews.capacity() << endl;

        // Make sure that there will be this much space
        bigNews.reserve(500);

        // Add this to the end of the string:
        bigNews.append("I've been working too hard.");
        cout << bigNews << endl;

        cout << "Size = " << bigNews.size() << endl;
        cout << "Capacity = " << bigNews.capacity() << endl;
    }
    ```

## Ejercicio 3: Funciones `insert`, `find` y `replace`

3. El siguiente programa usa las funciones `insert`, `find` y `replace` del objeto `string`. Estudie las sentencias `assert` y verifique su funcionamiento. Piense las diferencias entre insertar y reemplazar una cadena en otra. ¿Cómo trabaja la función `replace`?
    ```cpp
    #include <cassert>
    #include <string>
    using namespace std;

    int main()
    {
        string s("A piece of text");
        string tag("$tag$");
        s.insert(8, tag + ' ');
        assert(s == "A piece $tag$ of text");
        int start = s.find(tag);
        assert(start == 8);
        assert(tag.size() == 5);
        s.replace(start, tag.size(), "hello there");
        assert(s == "A piece hello there of text");
    }
    ```

## Ejercicio 4: Reemplazo de String desde Teclado

4. Modifique el programa del ejercicio 3 para poder reemplazar un `string` ingresado por teclado dentro del `string` `s`. Se debe controlar que la cadena ingresada por teclado exista dentro de la cadena `s`. ¿Qué sucede con el tamaño del `string` `s` si la cadena a reemplazar tiene un tamaño igual o menor que el de la cadena reemplazada? ¿Aumenta, disminuye o se mantiene el tamaño de `s`? ¿Se le ocurre un caso en el que el reemplazo haga que el tamaño de `s` pueda aumentar?

## Ejercicio 5: Clase `CRacional`

5. El siguiente listado es un programa de prueba llamado `test.cpp` para probar el funcionamiento de una clase denominada `CRacional`. Copie el código en su IDE favorito y haga que compile sin advertencias y ejecute.
    ```cpp
    #include <iostream>
    #include "racional.h"
    using namespace std;

    int main()
    {
        CRacional a, b(3, 7), c;
        int d = 3;
        cout << "a: "; cin >> a;
        c = a + b;

        c += b;
        cout << c << endl;
        c = a + b; // equivale a: c = a.operator+(b)
        cout << c << endl;
        c = b + a; // equivale a: c = b.operator+(a)
        cout << c << endl;
        c = a + static_cast<CRacional>(d);
        cout << c << endl;
        c = static_cast<CRacional>(d) + a;
        cout << c << endl;

        double x = 2.0;
        c = x + a;
        cout << c << endl;

        if (a == b) cout << "a es igual a b\n";
        if (a < b) cout << "a es menor que b\n";
        if (a > b) cout << "a es mayor que b\n"; 
        if (!a) cout << "racional nulo\n";
        c = ++a;
        cout << "c = " << c << endl;
        cout << "a = " << a << endl;
        c = a++;
        cout << "c = " << c << endl;
        cout << "a = " << a << endl;

        c = --a;
        c = a--;
        c = -a + b;
        cout << c << endl;
        c = -a - b;
        cout << c << endl;
        c = a * b;
        cout << c << endl;
        c = a / b;
        cout << c << endl;

        x = c;
        cout << x << endl;
        return 0;
    }
    ```

## Ejercicio 6: Clase `CCadena`

6. El siguiente código contiene la declaración de una clase `string` básica. Se pide el código que implemente esa clase y un programa de prueba que demuestre su funcionamiento.
    ```cpp
    #if !defined(_CADENA_H_)
    #define _CADENA_H_

    #include <iostream>
    using namespace std;

    // Clase para operar con cadenas de caracteres
    class CCadena
    {
    private:
        char *pmCad;        // Puntero a la cadena de caracteres
        size_t nlong;       // Longitud de la cadena

    public:
        CCadena(const char * = 0);               // Constructor copia
        CCadena(const CCadena&);                  // Constructor copia
        CCadena(char, int);                       // Constructor
        ~CCadena();                               // Destructor

        // Comparación de cadenas de caracteres
        friend bool operator<(const CCadena&, const CCadena&);
        friend bool operator>(const CCadena&, const CCadena&);
        friend bool operator<=(const CCadena&, const CCadena&);
        friend bool operator>=(const CCadena&, const CCadena&);
        friend bool operator==(const CCadena&, const CCadena&);
        friend bool operator!=(const CCadena&, const CCadena&);

        // Operadores de entrada/salida
        friend istream& operator>>(istream&, CCadena&);
        friend ostream& operator<<(ostream&, const CCadena&);

        // Asignación, concatenación e indexación
        CCadena& operator=(const CCadena&);
        CCadena operator+(const CCadena&) const;
        char& operator[](unsigned int);
        const char& operator[](unsigned int) const;

        // Devuelve la longitud de la cadena
        size_t GetNlong() const { return nlong; }
    };

    #endif
    ```