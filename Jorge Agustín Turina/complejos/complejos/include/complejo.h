#ifndef COMPLEJO_H
#define COMPLEJO_H

#include <iostream>
using namespace std;

class complejo
{
    public:
        complejo();
        complejo(int, int=8);
        //complejo(int);

        void set_real(int);
        void set_imaginario(int);
        int get_real() const;
        int get_imaginario() const;
        int* get();

        friend ostream& operator << (ostream&, complejo&);
        //ostream& operator << (complejo&);
        complejo& operator + (complejo&);


        complejo operator - (complejo&);
        friend int operator + (int, const complejo&);
        complejo complejo_suma();


        complejo operator * (const complejo&);
        ///int operator * (const complejo&);

        complejo operaciones(const complejo&, complejo) const;
        complejo operaciones1(const complejo, complejo);

       /// int operator (int)(complejo &);
    /// tira error

    protected:

    private:
        int* real;
        int* imaginario;


};

#endif // COMPLEJO_H
