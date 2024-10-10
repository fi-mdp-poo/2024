#include "claseEmpresa.h"
#include <iostream>

Empresa::Empresa(){  }

Empresa::~Empresa(){
    Empleado* aux=NULL;
    while(!empleados.empty()){
        aux=empleados[0];
        despedirEmpleado(aux->getNombre());
        delete aux;
    }
}

void Empresa::agregarEmpleado(Empleado* e){
    empleados.push_back(e);
}

Empleado* Empresa::despedirEmpleado(string nombre){
    Empleado* aux=NULL;
    int longitud=empleados.size(), i=0;
    bool flag=false;
    while(!flag&&i<longitud){
        aux=empleados[i];
        flag=(aux->getNombre()==nombre);
        if(!flag)
            i++;
    }
    if(flag)
        empleados.erase(empleados.begin()+i);
    return (flag)? aux : NULL;
}

double Empresa::montoTotal(const Fecha& fecha) const{
    double total=0.0;
    Empleado* aux=NULL;
    int longitud=empleados.size();
    for (int i=0; i<longitud; i++){
        aux=empleados[i];
        total+=aux->calcularSalario(aux->calcularAntiguedad(fecha));
    }
    return total;
}
