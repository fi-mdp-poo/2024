#include <iostream>

using namespace std;

template <class Derived>
class Equality
{
public:
    // Define el operador == usando el operador <
    friend bool operator==(const Derived& lhs, const Derived& rhs)
    {
        return !(lhs < rhs) && !(rhs < lhs);
    }

    // También podrías definir otros operadores aquí, por ejemplo, !=
    friend bool operator!=(const Derived& lhs, const Derived& rhs)
    {
        return !(lhs == rhs);
    }
};


struct Apple : public Equality<Apple>
{
    int size;

    // Define el operador < para que funcione Equality
    friend bool operator<(const Apple& a1, const Apple& a2)
    {
        return a1.size < a2.size;
    }
};

int main()
{

    Apple a1;
    Apple a2;
    Apple a3;

    a1.size = 10;
    a2.size = 10;
    a3.size = 11;


    if (a1 == a2)
    {
        std::cout << "a1 es igual a a2" << std::endl;  // Esto imprime.
    }

    if (a1 != a3)
    {
        std::cout << "a1 es diferente de a3" << std::endl;  // Esto imprime.
    }

    return 0;
}

