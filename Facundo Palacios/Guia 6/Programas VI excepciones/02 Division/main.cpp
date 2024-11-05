#include <iostream>

using namespace std;

void divide(double, double);

int main()
{
    double num, den;

    do
    {
        cout << "Numerador (0 para salir): ";
        cin >> num;
        if(num)
        {
            cout << "Denominador: ";
            cin >> den;
            divide(num, den);
        }
    } while(num);

    return 0;
}

void divide(double num, double den)
{
    try
    {
        if( !den )                    // controla la division por 0
        {
            //cout << "lo lamento, no puedo hacer la división" << endl;
            //return ;
            throw(0xFF);               // lanza la excepcion
            //throw("\nNo se puede dividir por 0!!!");
        }
        cout << "\nResultado: " << num/den << endl << endl << endl;
    }
    catch(int codigo)
    {
        cout << "\nNo se puede dividir por cero (codigo = " << codigo << ").\n\n\n";
    }
    catch(const char *codigo)
    {
        cout << codigo << "\n\n\n";
    }
}

