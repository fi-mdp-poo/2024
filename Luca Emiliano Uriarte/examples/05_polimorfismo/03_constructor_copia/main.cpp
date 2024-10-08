#include <iostream>
#include <string.h>

using namespace std;

class Persona
{
    public:
        Persona(char const *nom_param) { strcpy(nombre, nom_param); }
        Persona(const Persona& p)
            { strcpy(nombre, p.nombre); cout << "Per: constructor copia." << endl; }
        virtual ~Persona() { ; }
        virtual void VerNombre() { cout << nombre << endl; }
        virtual Persona* Clonar() { return new Persona(*this); }
    protected:
        char nombre[30];
};

class Empleado : public Persona
{
    public:
        Empleado(char const *nom_param) : Persona(nom_param) {}
        Empleado(const Empleado &e) : Persona(e)
            { cout << "Emp: constructor copia." << endl; }
        void VerNombre() { cout << "Emp: " << nombre << endl; }
        virtual Persona* Clonar() { return new Empleado(*this); }
};

class Estudiante : public Persona
{
    public:
        Estudiante(char const *nom_param) : Persona(nom_param) {}
        Estudiante(const Estudiante &e) : Persona(e)
            { cout << "Est: constructor copia." << endl; }
        virtual void VerNombre() { cout << "Est: " << nombre << endl; }
        virtual Persona* Clonar() { return new Estudiante(*this); }
};

int main()
{
   Persona *Pepito = new Estudiante("Jose");
   Persona *Carlos = new Empleado("Carlos");
   Persona *Gente[2];
   // Estudiante Nueva(*Pepito);     // muy rebuscado

   Carlos->VerNombre();
   Pepito->VerNombre();

   Gente[0] = Carlos->Clonar();
   Gente[0]->VerNombre();

   Gente[1] = Pepito->Clonar();
   Gente[1]->VerNombre();

   delete Pepito;
   delete Carlos;
   delete Gente[0];
   delete Gente[1];

   return 0;
}
