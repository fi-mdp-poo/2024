# Guía 6: Plantillas

## Ejercicio 1: Declaración de Funciones y Clases de Plantillas

1. A continuación, se da una lista de descripciones de funciones y clases de plantillas. Escriba una declaración apropiada para cada una:
   - a) Declarar una función que toma dos parámetros de plantilla distintos, de los cuales uno es el tipo de retorno y el otro es un argumento.
   - b) Declarar una clase que toma un parámetro de plantilla, el cual es una variable miembro (atributo) de la misma.
   - c) Declarar una clase que toma dos parámetros de plantilla: uno como argumento al constructor y otro como tipo de retorno de una función miembro (método) sin argumentos.
   - d) Declarar una clase de plantilla con un parámetro entero con un valor por defecto cualquiera, que sirva como el tamaño de un atributo array.
   - e) Declarar una clase que tiene como amiga a una clase de plantilla distinta (con tantos parámetros como se desee).
   - f) Declarar una clase en la que uno de los parámetros es a su vez una clase de plantilla.

## Ejercicio 2: Implementación de una Clase de Plantilla `Vector`

Cree una clase de plantilla `Vector` que facilite el manejo de arrays y proporcione seguridad en el acceso a índices fuera de rango. La clase `Vector` recibirá un único parámetro de plantilla para el tipo a almacenar. Las funciones a implementar serán:

   - a) Un constructor que inicializa los atributos a valores seguros.
   - b) Un método `redimensionar` que cambia el tamaño máximo del vector, reserva espacio cuando sea necesario (por ejemplo, en la primera reserva de memoria) y copia los datos del array viejo cuando sea necesario (por ejemplo, al redimensionar a un tamaño mayor).
   - c) Un destructor que liberará la memoria.
   - d) Sobrecarga del operador `[]` para acceder a un elemento, devolviendo el valor por referencia, de modo que el siguiente código sea válido:
     ```cpp
     Vector<int> v;
     v.redimensionar(1); 
     v[0] = 10; // Modificación 
     std::cout << v[0] << std::endl; // Acceso
     ```
     Si se intenta acceder a un elemento por encima del tamaño máximo, se debe imprimir un mensaje de error. Nota: Un diseño más correcto incluiría una sobrecarga adicional del operador `[]` con modificadores `const`.
   - e) No hemos definido un constructor de copia. ¿Qué peligros tendría asignar un `Vector` a otro? Defina el constructor de copia para que no haya peligro alguno. (Pista: por simplicidad, el array interno no puede ser compartido; debe copiarse).
   - f) Un constructor de copia desde otro tipo de vector distinto que funcione cuando existe una conversión válida entre ambos tipos. Preocúpese solo de los tipos escalares (`int`, `float`, `double`), ya que entre ellos sí hay conversión.