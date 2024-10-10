#include <iostream>
#include "claseEmpresa.h"

using namespace std;

int main(){
    Fecha diaHoy(8, 1, 2024);
    Empresa corporation=Empresa();
    Empleado* trabajador1=new PlantaPerm("Hugo Wakanda", Fecha(5, 1, 2018), 0, 48, true);
    Empleado* trabajador2=new PlantaTemp("Carlos Ortega", Fecha(11, 9, 2023), 0, 48, false);
    Empleado* trabajador3=new Gerente("Uilson Mubi", Fecha(3, 4, 2016), 2, 48, true);
    corporation.agregarEmpleado(trabajador1);
    corporation.agregarEmpleado(trabajador2);
    corporation.agregarEmpleado(trabajador3);
    cout<<corporation.montoTotal(diaHoy)<<endl;
    delete corporation.despedirEmpleado("Uilson Mubi");
    cout<<corporation.montoTotal(diaHoy)<<endl;
    return 0;
}
