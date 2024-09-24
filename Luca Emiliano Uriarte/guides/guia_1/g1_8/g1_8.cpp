#include <iostream>
#include "math_operations.h"

using namespace std;

int main()
{
    int a = 10;
    int b = 5;

    cout << "Suma: " << add(a, b) << endl;
    cout << "Resta: " << subtract(a, b) << endl;
    cout << "Multiplicación: " << multiply(a, b) << endl;
    cout << "División: " << divide(a, b) << endl;

    return 0;
}