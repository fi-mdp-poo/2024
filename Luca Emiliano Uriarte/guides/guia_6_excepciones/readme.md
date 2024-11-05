# Unidad VI: Flujos y Excepciones

## Ejercicios

1. Explique cada línea del siguiente fragmento de código.

2. Cree un bloque `try`, una instrucción `catch` y una excepción simple.

3. Modifique la respuesta del ejercicio 2, coloque datos en la excepción junto con una función *getter*, y utilícela en el bloque `catch`.

4. Modifique la clase del ejercicio 3 para que sea una jerarquía de excepciones. Cambie el bloque `catch` para utilizar los objetos derivados y los objetos base.

5. Escriba un programa que tome un nombre de archivo como parámetro y que abra el archivo para lectura. Lea todos los caracteres del archivo y despliegue en la pantalla solo las letras y los signos de puntuación (ignore todos los caracteres no imprimibles).

6. Escriba un programa que tome un nombre de archivo como parámetro y que abra el archivo para lectura. Lea todos los bytes y presente en pantalla la información en formato Hex, como se muestra a continuación. Además, genere un nuevo archivo de texto y guarde la información presentada en pantalla, respetando el mismo formato.

7. Realizar un programa que permita crear un archivo nuevo, abrir uno existente, agregar, buscar, modificar y borrar registros. El nombre del archivo será ingresado por teclado. Cada registro del archivo será un objeto `persona` con los atributos `nombre`, `dirección` y `teléfono`. Así mismo, para que el usuario pueda elegir cualquiera de las opciones mencionadas, el programa visualizará en pantalla un menú similar al siguiente:
   ```plaintext
   Archivo actual: ninguno
   ----------------------------------------------------------
   1. Nuevo archivo
   2. Abrir archivo
   3. Agregar registro
   4. Buscar un registro
   5. Buscar siguiente
   6. Modificar un registro
   7. Eliminar un registro
   8. Salir
   ----------------------------------------------------------
   Opción (1 - 8): 1
   Nombre del archivo: telefonos.dat

La opción `Nuevo` abrirá un archivo para agregar registros; si el archivo existe, preguntará si se desea sobreescribir. La opción `Abrir` permitirá abrir un archivo para leer y escribir o para agregar; estas dos opciones se elegirán de un menú. La opción `Buscar` permitirá buscar un registro por el campo `nombre`; se permitirá introducir una subcadena de nombre, incluso vacía. La opción `Buscar siguiente` buscará el siguiente registro que cumpla con las mismas condiciones que el anteriormente buscado. Finalmente, la opción `Eliminar` permitirá marcar un registro para borrar. Se deberá realizar al menos un método para cada una de las opciones, excepto para las opciones `Buscar`, que compartirán ambas el mismo método, y para `Salir`.

**Nota**: En todos los programas, use excepciones para manejar situaciones anómalas.