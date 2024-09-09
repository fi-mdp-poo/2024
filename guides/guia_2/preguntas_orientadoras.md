## Preguntas orientadoras

1. **Mencione y defina los tipos de ámbitos de las variables que se presentaron en la teoría. ¿Por qué definiría como global una variable de tipo static?**

   - **Ámbito de la variable**:
     - **Ámbito local**: La variable es accesible solo dentro del bloque en el que se define (por ejemplo, dentro de una función).
     - **Ámbito global**: La variable es accesible en todo el archivo o en todo el programa si se define fuera de cualquier función.
     - **Ámbito de archivo**: La variable es accesible solo dentro del archivo en el que se define, si se utiliza el modificador `static`.

   - **Definición global de `static`**: Definir una variable global como `static` restringe su visibilidad al archivo en el que se define.

2. **¿Qué modificador elegiría para indicar que una variable puede cambiar su valor entre accesos aún cuando no pareciera haber sido modificado? ¿En qué aplicaciones se utiliza este modificador?**

   - **Modificador**: `volatile`
   - **Aplicaciones**: Cuando se usa `volatile`, el compilador evita optimizaciones que podrían suponer que el valor de la variable no cambia de forma inesperada. Esto garantiza que cada vez que se accede a la variable, se lea directamente desde su ubicación en memoria y no desde una copia almacenada en un registro. Se utiliza en sistemas de programación de hardware, especialmente en el manejo de variables que pueden ser modificadas por hardware o procesos externos, como flags de interrupciones o variables compartidas entre diferentes hilos de ejecución.

3. **¿Por qué puede ser que el operador `new` retorna un puntero y no una referencia?**

   - **Razón**: El operador `new` retorna un puntero porque el puntero permite la gestión dinámica de la memoria y el control sobre la existencia del objeto. Las referencias, por otro lado, deben ser inicializadas en el momento de la creación y no pueden ser reasignadas, lo cual no es adecuado para el manejo dinámico de memoria.

4. **Indique cuál es la función de los constructores y para qué existen los destructores.**

   - **Constructores**: Son funciones miembro especiales de una clase que se utilizan para inicializar los miembros de datos de la clase cuando se crea un objeto.
   - **Destructores**: Existen para liberar recursos y realizar limpieza cuando un objeto es destruido.

5. **Llena los espacios en blanco**:
   
   - Se tiene acceso a los miembros de clase vía el operador `.` en conjunción con un objeto de clase o vía el operador `->` en conjunción con un apuntador a un objeto de clase.
   - Los miembros de una clase especificados como `private` son sólo accesibles a las funciones miembro de la clase y amigos de la clase.
   - Un `constructor` es una función miembro especial utilizada para inicializar los miembros de datos de una clase.
   - El acceso por omisión para los miembros de una clase es `private`.
   - Los miembros de una clase especificados como `public` son accesibles en cualquier parte en que un objeto de la clase esté en alcance.
   - El operador `new` asigna dinámicamente memoria para un objeto de un tipo específico y regresa un `puntero` a dicho tipo.
   - Las operaciones de entrada son soportadas por la clase `istream`.
   - Las operaciones de salida son soportadas por la clase `ostream`.

6. **Encuentre el o los errores y corrija**:
   
   - `void ~Time(int);`
   - Error: El destructor no debe tener tipo de retorno ni parámetros
   - Corrección:
     ```cpp
     ~Time(); // Destructor sin tipo de retorno ni parámetros
     ```

   - Suponga la siguiente definición parcial de la clase `Time`:
     ```cpp
     class Time
     {
     public:
         //Function prototypes
         
     private:
         int hour = 0;
         int minute = 0;
         int second = 0;
     };
     ```

7. **¿Se pueden utilizar los nombres definidos en un espacio de nombres sin utilizar la palabra reservada `using`?**

   - Sí, se pueden utilizar los nombres definidos en un espacio de nombres especificando el nombre del espacio de nombres seguido del operador de resolución de ámbito (`::`). Por ejemplo, `Namespace::name`.

