#include "headers/clasePersona.h"

std::ostream& operator<<(std::ostream &Cout, Persona &persona){
    return Cout;
}

Persona::Persona(std::string nom, unsigned doc, const Fecha &nac){
    setNombre(nom);
    setDocumeno(doc);
    setNacimiento(nac);
}

Persona::~Persona(){  }
void Persona::setNombre(std::string nom){ nombre=nom; }
void Persona::setDocumeno(unsigned int doc){ documento=doc; }
void Persona::setNacimiento(const Fecha &nac){ nacimiento=nac; }

std::string Persona::getNombre()const{ return nombre; }
unsigned int Persona::getDocumento()const{ return documento; }
Fecha Persona::getNacimieno()const{ return nacimiento; }
