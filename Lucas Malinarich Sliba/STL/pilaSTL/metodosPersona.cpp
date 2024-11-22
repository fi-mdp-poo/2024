#include "clasePersona.h"

ostream& operator<<(ostream &Cout, const Persona &persona){
    cout<<persona.getNombre()<<" "<<persona.getApellido()<<endl;
    cout<<"DNI: "<<persona.getDNI()<<endl;
    return Cout;
}

Persona::Persona(string Nombre, string Apellido, int Dni){
    nombre=Nombre;
    apellido=Apellido;
    dni=Dni;
}

Persona::~Persona(){  }

string Persona::getNombre()const{ return nombre; }
string Persona::getApellido()const{ return apellido; }
int Persona::getDNI()const{ return dni; }

bool Persona::operator==(const Persona &persona1){
    return (getDNI()==persona1.getDNI());
}
