#include <iostream>
#include "complejo.h"
#include "Cpolar.h"
#include <math.h>
using namespace std;

int main()
{
    complejo c1;
    Cpolar p1;


    Cpolar p2(sqrt(2),0.785398);

    cout << p2;

    return 0;
}
