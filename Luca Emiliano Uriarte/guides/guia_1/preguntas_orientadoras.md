## Preguntas orientadoras

1. **¿Qué entiende por paradigma? ¿Qué paradigma de programación utilizó hasta ahora? ¿Cuáles son sus características?**

   - **Paradigma**: Un paradigma de programación es una forma de organizar y estructurar el código, ofreciendo un enfoque o modelo para resolver problemas mediante la programación. Los paradigmas determinan el estilo y las herramientas que un lenguaje de programación proporciona para expresar soluciones.

   - **Paradigma utilizado**: Hasta ahora use el paradigma **imperativo**, que es el paradigma base del lenguaje C.

   - **Características del paradigma imperativo**:
   - **Secuencialidad**: Las instrucciones se ejecutan en un orden específico, una tras otra, lo que hace que el flujo del programa sea fácil de seguir.
   - **Control del estado**: El estado del programa (valores de variables, estructuras de datos) se modifica a través de sentencias que alteran su valor, como asignaciones o llamadas a funciones.
   - **Estructuras de control**: Se utilizan bucles (`for`, `while`) y condicionales (`if`, `switch`) para controlar el flujo de ejecución del programa.
   - **Modularidad**: A través de funciones, el código puede ser dividido en bloques reutilizables y más fáciles de entender.
   - **Eficiencia**: El paradigma imperativo suele ser muy eficiente en cuanto al uso de memoria y recursos, lo que lo hace adecuado para sistemas de bajo nivel como la programación en C.

2. **Describa el tipo de Dato Abstracto (TAD). ¿Puede el lenguaje C trabajar con TAD’s? Dé un ejemplo de tipo de dato abstracto en C si el lenguaje lo soporta o de lo contrario indique cómo lo haría.**

   - **Tipo de Dato Abstracto (TAD)**: Un TAD es una estructura que define un conjunto de operaciones sobre un tipo de datos sin especificar cómo se implementan estas operaciones. El TAD proporciona una interfaz para interactuar con los datos sin exponer los detalles de su implementación.
   
   - **TAD en C**: Aunque C no tiene soporte directo para TADs como C++, se pueden simular usando estructuras (`struct`) y funciones para operar sobre ellas.
   
   - **Ejemplo en C**:
     ```c
     // Definición del TAD 'Pila' en C
     typedef struct {
         int *array;
         int top;
         int capacity;
     } Pila;

     // Prototipos de funciones para operar sobre el TAD 'Pila'
     void init_pila(Pila *p, int capacity);
     void push(Pila *p, int value);
     int pop(Pila *p);
     int is_empty(Pila *p);
     ```

3. **¿En qué se basa la programación orientada a objetos (POO)? ¿Qué ventajas presenta respecto de otros lenguajes? ¿Qué características salientes posee?**

   - **Base de la POO**: La POO se basa en la creación y manipulación de objetos que combinan datos y comportamientos. Los objetos interactúan entre sí a través de métodos y se basan en clases que definen sus características y comportamientos.
   
   - **Ventajas**:
    C++ ofrece varias ventajas sobre C, ya que extiende sus capacidades mientras mantiene la eficiencia de bajo nivel. Algunas de las principales ventajas de C++ respecto de C son:

    1. **Programación Orientada a Objetos (POO)**: 
    - C++ permite trabajar con clases y objetos, lo que facilita la encapsulación, herencia y polimorfismo. Esto mejora la organización y reusabilidad del código.

    2. **Sobrecarga de funciones y operadores**: 
    - En C++, se pueden definir múltiples versiones de una función o de un operador con diferentes tipos de argumentos, lo que permite más flexibilidad.

    3. **Manejo automático de memoria**: 
    - C++ introduce el uso de constructores y destructores que ayudan a manejar la inicialización y liberación de recursos de manera automática, además de permitir control manual como en C.

    4. **Plantillas (templates)**: 
    - C++ permite la creación de código genérico mediante plantillas, lo que facilita la reutilización del código y permite escribir funciones y clases independientes del tipo de datos.

    5. **Biblioteca estándar más amplia (STL)**: 
    - C++ incluye una rica biblioteca estándar que proporciona estructuras de datos (como listas, vectores, mapas) y algoritmos, lo que reduce la necesidad de implementar estas funcionalidades desde cero.

    6. **Excepciones**: 
    - C++ maneja errores de manera más robusta mediante excepciones, permitiendo capturar y manejar errores de forma estructurada sin afectar el flujo general del programa.

    En resumen, C++ introduce características más avanzadas y abstrae muchos aspectos complejos de C, mejorando la modularidad, la reutilización y la facilidad de mantenimiento del código.

   - **Características salientes**:
     - **Clases y objetos**
     - **Encapsulamiento**: Protege los datos internos de las clases y permite la implementación de detalles privados.
     - **Herencia**: Permite que las clases hereden características y comportamientos de otras clases.
     - **Polimorfismo**: Permite que diferentes clases sean tratadas a través de una interfaz común.

4. **Defina clase y objeto. Explicite de qué manera se puede fijar el nivel de acceso a los miembros de una clase.**

   - **Clase**: Una clase es una plantilla o esquema que define un conjunto de atributos (datos) y métodos (funciones) que los objetos de esa clase compartirán.
   
   - **Objeto**: Un objeto es una instancia de una clase. Contiene datos y métodos definidos por la clase.

   - **Nivel de acceso**:
     - **`public`**: Los miembros son accesibles desde cualquier parte del programa.
     - **`private`**: Los miembros solo son accesibles dentro de la misma clase.
     - **`protected`**: Los miembros son accesibles en la misma clase y en las clases derivadas.

5. **¿Cómo se definen las funciones o métodos en una clase?**

   - **Definición de métodos en una clase**:
     - Los métodos se definen dentro del cuerpo de la clase, utilizando la sintaxis de C++ para especificar el tipo de retorno, el nombre del método y los parámetros.

     ```cpp
     class MiClase {
     public:
         void miMetodo(); // Declaración del método
     };

     void MiClase::miMetodo() {
         // Implementación del método
     }
     ```

6. **Defina Lenguaje Unificado de Modelado (UML). ¿Qué tipos de diagramas UML conoce? Cree una clase, defina la visibilidad de los atributos y métodos, genere 3 clases adicionales que hereden métodos y atributos de la clase anterior. Genere para esa situación un Diagrama UML.**

   - **Lenguaje Unificado de Modelado (UML)**: UML es un lenguaje estándar para la modelización de sistemas de software. Permite representar el diseño, la estructura y el comportamiento del software utilizando diferentes tipos de diagramas.

   - **Tipos de diagramas UML**:
     - **Diagrama de Clases**
     - **Diagrama de Casos de Uso**
     - **Diagrama de Estado**

   - **Ejemplo de clase y herencia**:
     ```cpp
     class Animal {
     public:
         void comer();
         void dormir();
     protected:
         int edad;
     private:
         std::string nombre;
     };

     class Perro : public Animal {
     public:
         void ladrar();
     };

     class Gato : public Animal {
     public:
         void maullar();
     };

     class Pajaro : public Animal {
     public:
         void cantar();
     };
     ```

   - **Diagrama UML**:
```plaintext
                        +-----------------------+
                        |      Animal           |
                        +-----------------------+
                        | - nombre: std::string |
                        | # edad: int           |
                        +-----------------------+
                        | + comer(): void       |
                        | + dormir(): void      |
                        +-----------------------+
                                    |
           ----------------------------------------------------
           |                        |                         |
+----------------------+ +----------------------+ +----------------------+
|        Perro         | |        Gato          | |        Pajaro        |
+----------------------+ +----------------------+ +----------------------+
| + ladrar(): void     | | + maullar(): void    | | + cantar(): void     |
+----------------------+ +----------------------+ +----------------------+
```

7. **En C, para el manejo de archivos, utilizó `File*`, el cual es un TDA. Investigue al respecto.**

   - **Investigación sobre `File*` en C**:
     `FILE*` es un tipo de dato en C utilizado para manejar archivos. Se define en la biblioteca estándar `<stdio.h>` y permite realizar operaciones de entrada y salida en archivos, como abrir, leer, escribir y cerrar archivos. Aunque el contenido interno de `FILE` no está expuesto a los programadores (es decir, es un tipo de datos abstracto), permite la interacción con archivos mediante funciones estándar proporcionadas por la biblioteca.
