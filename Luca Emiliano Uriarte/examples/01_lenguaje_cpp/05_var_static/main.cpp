#include <iostream>
#include "prueba.h"

using namespace std;

int prueba::m_Counter = 0;

int main()
{
    prueba obj1,
           obj2 = obj1,     // crea un nuevo objeto igual a obj1
           obj3(obj1),      // crea un nuevo objeto igual a obj1
           obj4(5),         // inicializa el valor de obj5
           *obj5;           // crea un puntero al nuevo objeto

 	cout << "\nExisten " <<	obj1.getCounter() << " instancias de la clase prueba\n\n";   // getCounter desde obj1
 	cout << "\nExisten " <<	prueba::getCounter() << " instancias de la clase prueba\n\n";  // getCounter desde la clase
    obj5 = new prueba;
 	cout << "\nExisten " <<	obj5->getCounter() << " instancias de la clase prueba\n\n";  // getCounter desde obj5

    obj1.setValor(181);
    obj5->setValor(255);

    cout << "\nValor en obj1 = " << obj1.getValor() <<
            "\n\nValor en obj5 = " << obj5->getValor() << endl;

	delete obj5;

	cout << "\n\nSe borro una instancia y ahora existen " << obj2.getCounter() <<        // getCounter desde obj2
		    " instancias de la clase prueba\n\n\n";

    return 0;
}
