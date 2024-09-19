#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

using namespace std;

class Tiempo
{
    public:
        Tiempo(int h = 0, int m = 0) :
               hora(h), minutos(m) { ; }
        void Mostrar() {cout << hora << ":" << minutos << endl;}
        operator int() {return hora*60 + minutos;}

    private:
        int hora;
        int minutos;
};

void print (double number) { cout << number << endl; }
void print (int number)    { cout << number << endl; }
void print (int number, string s) { cout << number << ", " << s << endl; }

#endif // TIPOS_H_INCLUDED
