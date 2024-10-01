# Guia 5

## Ejercicio 1: Auto y Camión

1. Escriba un programa que derive un **Auto** y un **Camión** de la clase **Vehículo**. Convierta a **Vehículo** en un **ADT** que tenga dos funciones virtuales puras. Haga que **Auto** y **Camión** no sean **ADTs**.

## Ejercicio 2: Derivación de Auto

2. Modifique el programa del inciso 1 para que **Auto** sea un **ADT**, y derive de **Auto** a **AutoDeportivo**, **Furgoneta** y **Sedan**. En la clase **Auto**, proporcione una implementación para una de las funciones virtuales puras de **Vehículo** y hágala no pura.

## Ejercicio 3: Cuentas Bancarias y Banco

3. Modele una clase que represente una **cuenta bancaria** que tenga un **saldo** y un **titular**, y que pueda realizar operaciones de **extracciones** y **depósitos**. Una vez modelada la clase **Cuenta**, modele la clase **Banco** que contiene un conjunto de cuentas, e implemente el mensaje que le permita saber cuál es el **activo disponible** del Banco, es decir, la suma de los saldos de las cuentas.

   Existen dos tipos de cuentas bancarias: **Cuentas corrientes** y **Cajas de ahorro**.

   - Ambas llevan cuenta de su saldo.
   - Ambas permiten realizar depósitos.
   - Ambas permiten realizar extracciones.

   Pero cada una tiene un tipo de restricción distinto en cuanto a las extracciones:

   - **Cuentas corrientes**: permiten que el cliente gire en descubierto (con un tope pactado con cada cliente).
   - **Cajas de ahorro**: poseen una cantidad máxima de extracciones mensuales (para todos los clientes). No se permite girar en descubierto.
   - **Cuentas universitarias**: permite extracciones de no más de 100$ diarios.

   Modele estas clases y los métodos correspondientes.

## Ejercicio 4: Calculador Impositivo

4. Se pide que implemente el “**calculador impositivo**” con el que una persona puede calcular su impuesto. El calculador funciona así:

   El usuario configura (inicializa) el calculador indicando su nombre y su categoría. El usuario carga, una a una, las facturas de cada servicio que ha brindado, incluyendo detalle del servicio, número de factura y monto.

   El usuario pide al calculador que calcule el impuesto para todas las facturas cargadas cuyos números se encuentren entre dos que él indica como parámetros.

   Como resultado, se obtiene un objeto **ReciboDePago** que entiende los mensajes:
   - `nombreDelContribuyente()`
   - `montoTotal()`
   - `montoFijo()`
   - `montoVariable()`
   - `primeraFacturaConsiderada()`
   - `ultimaFacturaConsiderada()`

   El impuesto se calcula así:
   - Todos los contribuyentes abonan un monto fijo por pago. Dicho monto es idéntico para todos y se actualiza regularmente. Inicialmente, el monto es de $5.
   - Además, cada contribuyente paga un monto variable, relativo a sus ingresos, de acuerdo a la categoría en la que se inscribió el contribuyente:
     - Los contribuyentes inscriptos como **“Limitado”** pagan un 0,5% de lo facturado.
     - Los contribuyentes inscriptos en categoría **“Completo”** abonan un 50% por cada servicio facturado cuyo monto supere los $5000.
     - Los contribuyentes en categoría **“Extendido”** pagan lo mismo que los **Completos**, pero además se les agrega $10 por cada servicio facturado.

   ### Tareas a realizar:
   
   1. Implemente en C++ todas las clases necesarias para proveer la funcionalidad antes descripta.
   2. Construya un programa de test que demuestre:
      - Correcta inicialización del sistema.
      - Funcionamiento correcto de la carga de facturas.
      - Funcionamiento correcto de la generación de recibo de pago.
   3. Construya un diagrama de clases UML donde quede claro qué clases componen el sistema, de qué forma se relacionan, herencia y atributos.