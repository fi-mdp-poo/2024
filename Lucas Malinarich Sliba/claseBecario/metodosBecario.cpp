#include "headers/claseBecario.h"

Becario::Becario(std::string tip, std::string lab, std::string dir, unsigned int dur){
    setTipo(tip);
    setLaboratorio(lab);
    setDirector(dir);
    setDuracion(dur);
}

Becario::~Becario(){  }

void Becario::setTipo(std::string tip){ tipo=tip; }
void Becario::setLaboratorio(std::string lab){ laboratorio=lab; }
void Becario::setDirector(std::string dir){ director=dir; }
void Becario::setDuracion(unsigned int dur){ duracion=dur; }

std::string Becario::getTipo()const{ return tipo; }
std::string Becario::getLaboratorio()const{ return laboratorio; }
std::string Becario::getDirector()const{ return director; }
unsigned int Becario::getDuracion()const{ return duracion; }
