#include <iostream>

using namespace std;

void ej_2(void);
void ej_3(void);
void ej_4(void);

int main (void)
{
    /* Ejercicio 2 */
    ej_2();

    /* Ejercicio 3 */
    ej_3();

    /* Ejercicio 4 */
    ej_4();
}

void swap(int& a, int& b)
{
    int aux;
    aux = a;
    a = b;
    b = aux;
}

void ej_2(void)
{
    int a = 10;
    int b = 20;
    swap(a, b);
}

void ej_3(void)
{
    int a = 5;
    int b = 2;

    float r;
    r = float(a) / float(b);
}

void funcion_a_contar()
{
    static int a;
    a++;
}

void ej_4(void)
{
    for(int i=0 ; i<4 ; i++)
    {
        funcion_a_contar();
    }
}