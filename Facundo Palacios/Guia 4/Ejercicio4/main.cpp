#include <iostream>

using namespace std;


class ClaseA {
public:
    ClaseA() : valorA(10) {}
    int LeerValor() const
    {
        return valorA;
    }
protected:
    int valorA;
};

class ClaseB : public virtual ClaseA {  // Herencia virtual
public:
    ClaseB() : valorB(20) {}
    int ObtenerValor() const  // Método diferente para evitar ambigüedad
    {
        return valorB;
    }
protected:
    int valorB;
};

class ClaseC : public virtual ClaseA, public ClaseB {
    // ClaseC hereda virtualmente de ClaseA también para resolver ambigüedad
};

int main()
{
    ClaseC CC;

    cout << CC.LeerValor() << endl;  // Ahora no hay ambigüedad y accede a ClaseA

    return 0;
}
