#include <iostream>
#include "complejos.h"

using namespace std;

int main()
{
    complejos c1(1,-1),c2(3,4),c3(5,6),c4;
    float m=c1.modulo();
    float f=c1.fase();
    cout<<m<<endl;
    cout<<f<<endl;
    return 0;
}
