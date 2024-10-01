#include <iostream>
#include "Empresa.h"
#include "PlantaPermanente.h"
#include "PlantaTemporaria.h"
#include "Gerente.h"
using namespace std;

int main()
{
    Empresa boca;
    Gerente* roman=new Gerente("Roman Riquelme", 300, 2, true, 5);
    PlantaPermanente* chicho= new PlantaPermanente("Chicho Siesta", 70, 1, false, 1);
    PlantaTemporaria* martinez= new PlantaTemporaria("Diego Martinez", 100, 0, true);


    boca.agregarEmpleado(roman);
    boca.agregarEmpleado(chicho);
    boca.agregarEmpleado(martinez);
    cout<< "Sueldo Roman: $" << roman->calcularSalario()<<endl;
    cout<< "Sueldo Chicho: $" << chicho->calcularSalario()<<endl;
    cout<< "Sueldo gigolo: $" << martinez->calcularSalario()<<endl;

    cout<< "Monto total a pagar: $"<<boca.montoTotal()<<endl;
    delete roman;
    delete chicho;
    delete martinez;
    return 0;
}
