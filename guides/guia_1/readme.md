# Guia 1

## Ejercicio 1: Proyecto de Consola

1. Genere un proyecto de Consola en C++ y comente las diferencias y similitudes que nota con un proyecto de consola en C.

## Ejercicio 2: Intercambio de Variables

2. Escriba una función en C++ que permita intercambiar los valores de dos variables enteras pasadas por referencias desde el `main`. Este problema ya se resolvió en programación estructurada usando punteros. 
    - ¿Cuál es la diferencia entre un puntero y una referencia?
    - ¿Le resultó más fácil la implementación usando las referencias?

## Ejercicio 3: Conversión de Tipos

3. El siguiente fragmento de código muestra cómo almacenar el resultado de la división entre dos números enteros. Escriba dicha conversión en lenguaje C++:
    ```cpp
    int a, b;
    float r;
    a = 5;
    b = 2;
    r = (float) a / b;
    ```

## Ejercicio 4: Contador de Invocaciones

4. Realice un programa que permita saber las veces que una función fue invocada desde el programa principal.

## Ejercicio 5: TDA Vehículo en C

5. Implementar un TDA (Tipo de Dato Abstracto) llamado Vehículo, organizando la definición en un archivo de cabecera y su implementación en un archivo `.c`. Utilice una estructura que contenga campos para representar los atributos del Vehículo: marca, puertas, kilometraje y cilindrada, y punteros a funciones: “getters” y “setters” para acceder a los atributos mencionados y algunas acciones que puede realizar el Vehículo: acelerar, frenar, prender, apagar. Además, son necesarias dos funciones encargadas de reservar y liberar memoria de forma dinámica: `crearVehículo` y `destruirVehículo`.

## Ejercicio 6: TDA Vehículo en C++

6. Implementar el mismo TDA del ejercicio 5, pero ahora usando una `class` y una `struct` de C++. 
    - ¿Qué diferencias y similitudes nota entre una `class` y una `struct` de C++?
    - ¿Y entre una `struct` de C y una de C++?
    - Experimente con los modificadores de acceso sobre métodos y atributos.
    - ¿Le resultó más fácil implementar el TDA en C++? ¿Por qué?

## Ejercicio 7: Atributos Públicos Estáticos

7. Agregue un atributo público estático llamado `valor_patente` de tipo `float` a la Clase Vehículo del ejercicio 6. Luego, desde el programa principal:
    - Cree dos instancias de tipo Vehículo y en una de las instancias cambie el valor de dicho atributo.
    - Si usando un `printf` muestra el valor del mismo atributo desde la otra instancia, ¿Qué valor se muestra en consola? ¿Por qué?
    - ¿Será posible acceder al atributo en cuestión SIN crear ninguna instancia de Vehículo? Experimente y comente.

## Ejercicio 8: Código C en C++

8. Antes de que el genio de Stroustrup inventara el lenguaje C++, se escribió mucho código en C. ¿Conoce la forma de usar código escrito en C desde C++? En la clase teórica se mencionó la palabra reservada `extern`. 
    - Escriba un conjunto de funciones en C, (los prototipos en un archivo `.h` y la implementación en `.c`), para sumar, restar, multiplicar y dividir enteros.
    - Luego, escriba un programa en C++ que use dichas funciones.