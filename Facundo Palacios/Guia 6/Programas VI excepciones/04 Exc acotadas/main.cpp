// Restringiendo tipos notificabless.
#include <iostream>

using namespace std;

/*************************
The following table summarizes the Microsoft C++ implementation of exception specifications:

Exception       Meaning
specification

noexcept        The function does not throw an exception. In c++14 mode (which is the default),
noexcept(true)  noexcept and noexcept(true) are equivalent. When an exception is thrown from a function
trow()          that is declared noexcept or noexcept(true), terminate is invoked. When an exception is
                thrown from a function declared as throw() in c++14 mode, the result is undefined behavior.
                No specific function is invoked. This is a divergence from the C++14 standard, which
                required the compiler to invoke unexpected. Visual Studio 2017 version 15.5 and later:
                In c++17 mode, noexcept, noexcept(true), and throw() are all equivalent. When an exception
                is thrown from a function declared with any of these specifications, terminate is invoked.

noexcept(false) The function can throw an exception of any type.
throw(...)
No specification

throw(type)	    (C++14 and earlier) The function can throw an exception of type type. The compiler accepts
                the syntax, but interprets it as noexcept(false). In /std:c++17 mode and later, the compiler
                issues warning C5040.
********************/

/* OJO: a partir de C++11 lanza un warning y a partir de C++17 no se puede hacer */
void Xhandler(int test) throw(int, char, double, const char *)
{
    if(test==0)
        throw 5;                // throw un int
    if(test==1)
        throw 'A';              // throw un char
    if(test==2)
        throw 123.45;           // throw un double
    if(test==3)
        throw "pepe";           // throw un const char*
    if(test==4)
        throw unsigned(10);     // throw un unsigned --> ERROR! (no está en la lista de parametros)
}

int main()
{
    cout << "Inicio\n\n";
    try
    {
        Xhandler(0);                // probar pasando otros valores
    }
    catch(int i)
    {
        cout << "Capturado integer = " << i << "\n\n";
    }
    catch(char c)
    {
        cout << "Capturado char = " << c << "\n\n";
    }
    catch(double d)
    {
        cout << "Capturado double = " << d << "\n\n";
    }
    catch(...)
    {
        cout << "Capturado mensaje \n\n";
    }
    cout << "\nFin\n\n";

    return 0;
}
