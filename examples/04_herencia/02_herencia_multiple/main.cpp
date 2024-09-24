#include "estudiante.h"
#include "empleado.h"
#include "becario.h"

int main()
{
    fecha hoy;             // el dia actual
    /***** Objetos de la clase estudiante *****/
    estudiante Pablo("Pablo Marmol", 27879654, hoy, "Electronica", fecha(1, 3, 2014), 6, 7.8),
               Betty;

    Betty.SetName("Betty McBricker");
    Betty.SetDocument(17555444);
    Betty.SetBirthDate(1, 1, 1987);
    Betty.vSetCarrera("Mecanica");
    Betty.vSetIngreso(01, 03, 2010);
    Betty.vSetMaterias(10);
    Betty.vSetPromedio(6.5);

    cout << "/***** Estudiantes *****/" << "\n\n";
    cout << "Impresion solo de los datos personales: \n\n";
    cout << Pablo;

    cout << "Impresion de todos los datos:\n\n";
    vPrint(Pablo);          // funcion print en clase estudiante
    cout << Betty;          // uso el operador << sobrecargado

    /***** Objetos de la clase empleado *****/
    empleado Roberto("Roberto Hidalgo", 17123456, 29, 1, 1979,  // fecha como 3 enteros
                     "Titular", 1, 5, 1995, 75324.89),          // dd mm aa
             Paula;

    Paula.SetName("Paula Cervellini");
    Paula.SetDocument(39888777);
    Paula.SetBirthDate(15, 6, 1990);
    Paula.vSetCategoria("Jefe Trabajos Practicos");
    Paula.vSetIngreso(01, 04, 2015);
    Paula.vSetSueldo(48895.36);

    cout << "\n\n/***** Empleados *****/" << "\n\n";
    vPrint(Paula);
    cout << Roberto << endl;

    /***** Objetos de la clase becario *****/
    becario Pedro("Pedro Picapiedra", 11222333, fecha(18, 1, 1999),
                  "Computacion", fecha(1, 4, 2014), 15, 8.59,
                  "Becario", fecha(1, 4, 2016), 2345.67,
                  "Estudiante avanzado", 3, "LIVRA", "Juan Carlos"),
            Vilma;

    //Vilma.empleado::SetName("Vilma Slaghoople");
    Vilma.estudiante::SetName("Vilma Slaghoople");
    //Vilma.SetName("Vilma Slaghoople");
    Vilma.estudiante::SetDocument(13456789);
    Vilma.estudiante::SetBirthDate(fecha(3, 5, 1990));
    Vilma.vSetCarrera("Infomatica");
    Vilma.estudiante::vSetIngreso(1, 3, 2010);
    Vilma.vSetMaterias(4);
    Vilma.vSetPromedio(6.02);
    Vilma.vSetCategoria("Becario");
    Vilma.empleado::vSetIngreso(fecha(1, 3, 2016));
    Vilma.vSetSueldo(23.52);
    Vilma.vSetTipo("Auxiliar");
    Vilma.vSetDuracion(2);
    Vilma.vSetLaboratorio("LIC");
    Vilma.vSetDirector("Unknown");

    cout << "\n\n/***** Becarios *****/" << "\n\n";
    vPrint(Pedro);
    cout << Vilma << endl << endl;

    return 0;
}
