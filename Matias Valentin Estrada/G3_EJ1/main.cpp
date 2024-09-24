#include <iostream>
#include "Complex.h"

using namespace std;

int main()
{
    Complex c1(1,2), c2(3,4), c3;
    c3 = c1/c2;
    cout << c3 << endl;
    return 0;
}
