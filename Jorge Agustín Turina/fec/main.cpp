#include "Fecha.h"

int main() {
    Fecha fecha;

    fecha.setFecha(31, 2, 2024); // Intentar establecer una fecha inválida
    fecha.setFecha(31, 2, 2024); // Intentar establecer una fecha inválida
    fecha.setFecha(31, 2, 2024); // Intentar establecer una fecha inválida
    Fecha otra_fecha = Fecha();
    std::cout << otra_fecha << std::endl;
    otra_fecha = fecha;
    Fecha alguna_otra(fecha);
    std::cout << alguna_otra << std::endl;
    Fecha a ;
    Fecha jj;
    (jj.obtenerFechaActual());
    std::cout << a << std::endl;
    std::cout << jj << "se supone la de hoy "<< std::endl;
    std::cout << "Fecha establecida (intento 1): " << fecha << std::endl;

    fecha.setDia(15); // Cambiar el día
    fecha.setMes(12); // Cambiar el mes
    fecha.setAnio(2023); // Cambiar el año

    std::cout << "Fecha modificada: " << fecha << std::endl;

    return 0;
}
