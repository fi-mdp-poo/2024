#include "estudiante.h"
#include "empleado.h"
#include "becario.h"
#include <fstream>

int main()
{
    fecha hoy(29,1,1959);

    persona *gente[6];

    /***** Objetos de la clase estudiante *****/
    gente[0] = new estudiante("Pablo Marmol", 27879654, hoy, "Electronica", fecha(1, 3, 2014), 6, 7.8);
    gente[1] = new estudiante();
    /***** Objetos de la clase empleado *****/
    gente[2] = new empleado("Roberto Hidalgo", 17123456, 29, 1, 1979,  // fecha como 3 enteros
                            "Titular", 1, 5, 1995, 75324.89);          // dd mm aa
    gente[3] = new empleado();
    /***** Objetos de la clase becario *****/
    gente[4] = new becario("Pedro Picapiedra", 11222333, fecha(18, 1, 1999),
                           "Computacion", fecha(1, 4, 2014), 15, 8.59,
                           "Becario", fecha(1, 4, 2016), 2345.67,
                           "Estudiante avanzado", 3, "LIVRA", "Juan Carlos");
    gente[5] = new becario();

    gente[1]->SetName("Betty McBricker");
    gente[1]->SetDocument(17555444);
    gente[1]->SetBirthDate(1, 1, 1987);
    dynamic_cast<estudiante *>(gente[1])->vSetCarrera("Mecanica");
    dynamic_cast<estudiante *>(gente[1])->vSetIngreso(01, 03, 2010);
    dynamic_cast<estudiante *>(gente[1])->vSetMaterias(10);
    dynamic_cast<estudiante *>(gente[1])->vSetPromedio(6.5);
    cout << endl<< endl << endl<< *dynamic_cast<estudiante *>(gente[1]) << endl << endl << endl;
    cout << *gente[1] << endl<< endl<< endl;
//    cout << endl<< endl<< endl<< dynamic_cast<estudiante *>(gente[1])->stGetCarrera() << endl<< endl<< endl;

    estudiante yo("Pablo Marmol", 27879654, hoy, "Electronica", fecha(1, 3, 2014), 6, 7.8);
    yo.vSetCarrera(string("otra carrera"));
    cout << endl << endl << yo << endl << endl;

    ofstream fileout;
    fileout.open("gente.txt");        // abro el archivo para escritura es ofstream

    for(int i=0; i<6; i++)
    {
        cout << *(gente[i]) << endl;
        fileout << *(gente[i]) << endl;
    }

    fileout.close();

    for(int i=0; i<6; i++)
    {
        delete gente[i];
    }

    return 0;
}
