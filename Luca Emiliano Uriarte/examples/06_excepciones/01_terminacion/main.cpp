#include <iostream>

#define    SWITCH      0       // 1 ==> se produce el cuelgue del programa

using namespace std;

int main()
{
    int *x = NULL;
    //long unsigned int y = 0x7FFFFFFF;   // 2147 millones de enteros
    long long unsigned int y = 0x83679DB200/64;  // 8 GB/64
                                   // con menor cantidad anda OK
    if(SWITCH)
    {
        x = new int[y];
        if(x)		// si != NULL
        {
            x[y-100] = 10;
            cout << "Puntero: " << (void *) x << endl;
            delete [] x;
        }
        else
        {
            cout << "Memoria insuficiente." << endl;
        }
    }
    else
    {
        try
        {
            x = new int[y];
            x[y-100] = 10;
            cout << "Puntero: " << (void *) x << endl;
            delete[] x;
        }

        catch(std::bad_alloc&)
        { // Los limitadores {} son OBLIGATORIOS
            cout << "Memoria no es suficiente\n" << endl;
        }
    }

    return 0;
}
