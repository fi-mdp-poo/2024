#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include <iostream>

using namespace std;

class fecha
{
    public:
        int       Day;
        int       Month;
        int       Year;

        fecha(int, int, int a = 2016);
        fecha();
};

class persona
{
    public:
        persona(string nombre = "Pedro", unsigned numero = 12345678, fecha ddmmaa = fecha());
        ~persona();
        void SetName(string);
        bool SetDocument(unsigned);     // retorna TRUE si el formato es correcto
        bool SetBirthDate(fecha);       // chequea la validez de la fecha
        bool SetBirthDate(int, int, int);       // chequea la validez de la fecha
        string GetName();
        unsigned GetDocument();
        fecha GetBirthDate();
        friend ostream& operator << (ostream&, persona&);
    private:
    protected:
        string Name;
        unsigned Document;
        fecha BirthDate;
};

void print(persona &);

#endif // PERSONA_H_INCLUDED
