#include <iostream>

using namespace std;

int sumar(int a, int b,int);

int main()
{
    float a = 2.0 ;
//    int b = 6 ;
//
//    int c = c+1;
//    int c++;
//
    cout<<&a;
    cout<<a;

    cout<<sumar(5,6,1);
    return 0;
}

int sumar(int a, int b,int w)
{

    int c = a + b-w;

    return c;
}
