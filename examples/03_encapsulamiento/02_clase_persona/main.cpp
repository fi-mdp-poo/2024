#include "persona.h"

int main()
{
    fecha dma(6,5),
          hoy;
    persona empleado,
            profesor("Pablo Marmol"),
            estudiante("Betty", 27879654, dma);

    print(empleado);
    print(profesor);
    print(estudiante);

    profesor.SetBirthDate(16,4,2016);
    print(profesor);

    empleado.SetName("Super");
    empleado.SetDocument(18988788);
    empleado.SetBirthDate(hoy);
    print(empleado);

    cout << profesor;         // uso el operador << sobrecargado

    return 0;
}
