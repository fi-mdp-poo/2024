#include <iostream>

using namespace std;

/*** Clase genérica ***/
template <class T> class myclass
{
    private:
        T x;
    public:
        myclass(T a)
        {
            cout << "Dentro de la clase generica\n";
            x = a;
        }
        T getx() { return x; }
};

/*** Especialización explícita para el tipo int ***/
template <> class myclass<int>
{
    private:
        int x;
    public:
        myclass(int a)
        {
            cout << "Dentro de la especializacion myclass<int>\n";
            x = a * a;
        }
        int getx() { return x; }
};

int main()
{
    myclass<double> d(10.1);
    cout << "\tdouble: " << d.getx() << "\n\n";

    myclass<int> i(5);
    cout << "\tint: " << i.getx() << "\n\n";

    return 0;
}
