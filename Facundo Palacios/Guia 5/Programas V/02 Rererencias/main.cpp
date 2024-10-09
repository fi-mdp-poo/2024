#include <iostream>
#include <string>

using namespace std;

class Persona
{
    public:
        Persona(string n)
            { nombre = n; }
        virtual void VerNombre() { cout << nombre << endl; }
        virtual ~Persona() { ; }
    protected:
        string nombre;
};

class Empleado : public Persona
{
    public:
        Empleado(string n) : Persona(n) {}
        void VerNombre()
        {
            cout << "Emp: " << nombre << endl;
        }
};

class Estudiante : public Persona
{
    public:
        Estudiante(string n) : Persona(n) {}
        void VerNombre()
        {
            cout << "Est: " << nombre << endl;
        }
};

int main()
{
    Estudiante Pepito("Jose");
    Empleado Carlos("Carlos");

    Persona &rPepito = Pepito; // Referencia como Persona
    Persona &rCarlos = Carlos; // Referencia como Persona

    rCarlos.VerNombre();
    rPepito.VerNombre();

    return 0;
}

