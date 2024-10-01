# Guía 2

## Ejercicio 1: Problemas con la Entrada de Cadena

1. ¿Qué inconveniente presenta el programa que se muestra a continuación? Discuta las posibles soluciones.
    ```cpp
    int main (int argc, char *argv[]) 
    { 
        string cadena; 
        cin >> cadena; 
        getline(cin, cadena); 
        cout << "La cadena ingresada es: " << cadena << endl; 
        return 0; 
    }  
    ```

## Ejercicio 2: Corregir Programa

2. ¿Qué está mal en este programa? Mencione 3 formas de corregirlo.
    ```cpp
    #include <iostream>

    int main() 
    { 
        cout << "¡Hola, mundo!" << endl; 
        return 0; 
    }   
    ```

## Ejercicio 3: Clase Fecha

3. Crear la clase `Fecha` con todos los datos miembro y atributos que se muestran en el diagrama de clase siguiente y luego, crear un programa cliente que demuestre el uso de cada una de las funciones.

# Fecha

| **Atributos**    | **Tipo**  |
|------------------|-----------|
| - day            | int       |
| - month          | int       |
| - year           | int       |

| **Métodos**                              | **Tipo**          |
|------------------------------------------|-------------------|
| + Fecha()                                | Constructor       |
| + setFecha(in day: int, in month: int, in year: int) | void     |
| + setDay(in day: int)                    | void              |
| + setMonth(in month: int)                | void              |
| + setYear(in year: int)                  | void              |
| + ingresarFecha()                        | void              |
| + imprimir_la()                          | void              |
| + imprimir_us()                          | void              |
| + imprimir_letras()                      | void              |
| + mesLetras()                            | char*             |
| + validarFecha()                         | bool              |

## Ejercicio 4: Clase Tiempo

4. Crear la clase `Tiempo` con todos los datos miembro y atributos que se muestran en el diagrama que sigue y luego, crear un programa cliente que muestre el uso de cada una de las funciones.

# Tiempo

| **Atributos**     | **Tipo**  |
|-------------------|-----------|
| - hora            | int       |
| - minutos         | int       |
| - segundos        | int       |

| **Métodos**                                  | **Tipo**          |
|----------------------------------------------|-------------------|
| + Tiempo(in int, in int, in int)             | Constructor       |
| + setHora(in hora: int)                      | void              |
| + setMinutos(in minutos: int)                | void              |
| + setSegundos(in segundos: int)              | void              |
| + setDatos(in int, in int, in int)           | void              |
| + getHora()                                  | int               |
| + getMinutos()                               | int               |
| + getSegundos()                              | int               |
| + ingresarDatos()                            | void              |
| + muestra_fmt_estandard()                    | void              |
| + muestra_fmt_universal()                    | void              |

## Ejercicio 5: Composición en Programación Orientada a Objetos

5. El siguiente diagrama muestra un concepto fundamental de la programación orientada a objetos: La composición. Implementar la clase `Empleado` y escribir un programa que imprima en pantalla la siguiente información:
    ```
    Perez, Juan
    Contratado el: 1 de Julio de 1999
    Fecha de nacimiento: 31 de Diciembre de 1978
    Lopez, Pedro
    Contratado el: 1 de Julio de 1999
    Fecha de nacimiento: 25 de Febrero de 1980
    ```
 **TODO:** Agregar el diagrama

## Ejercicio 6: Competencia de Ciclismo

6. En una competencia de ciclismo intervienen un número desconocido de deportistas, cada uno realiza dos pruebas, una por tiempo y otra por número de vueltas. Se deben registrar los siguientes datos de cada participante:
    - Nombre
    - Fecha de nacimiento
    - Tiempo en la primera prueba
    - Número de vueltas en la segunda prueba

    Imprimir en pantalla el nombre del participante que realizó la primera prueba en el menor tiempo, el nombre del participante que hizo la mayor cantidad de vueltas y 5 columnas en las que se muestre para cada participante:
    - Nombre
    - Edad
    - Tiempo en la primera prueba
    - Número de vueltas en la segunda prueba
    - Diferencia de tiempo respecto del más rápido en la primera prueba
    - Diferencia de vueltas respecto del que hizo más vueltas en la segunda prueba

    Se pide implementar un programa en lenguaje C++, orientado a objetos, que resuelva el problema. Además, se pide el diagrama de clases y de secuencia.

**NOTA:** En todos los ejercicios, se deben instanciar los objetos en la memoria HEAP.
