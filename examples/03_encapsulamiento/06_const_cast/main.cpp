#include <iostream>

using namespace std;

class fecha
{
public:
    int day, month, year;
};

void print(fecha &f)
{
    cout << f.day << "/" << f.month << "/" << f.year << "\n\n";
    f.year = 2000;
}

int main()
{
    const fecha hoy = {30, 8, 2017};
    fecha manana = {31, 8, 2017};

    print(manana);
    print(const_cast<fecha&>(hoy));   // me tengo que asegurar que la funcion no cambie el valor!!!

    cout << hoy.year << ", " << manana.year << "\n\n";

    /***** comportamiento indefinido *****/
    const int x = 10;
    int *x_var,
         y = 20;

    //x_var = &x;                   // el compilador produce un error!!
    //x_var = (int *)&x;            // formato antiguo, válido pero desaconsejado
    x_var = const_cast<int*> (&x);  // válido, pero el comportamiento es indefinido ...
    *x_var = 14;                    // modifica el contenido de la dirección de x pero no su valor

    cout << *x_var << ", " << x << endl;
    y+= x;
    cout << "\nValor de y = " << y << endl << endl;


    return 0;
}

