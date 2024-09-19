#include "composicion.h"

int main() {
    Auto auto1("Toyota Corolla");

    auto1.agregar_cedula("Juan Perez", 12345678, true);
    auto1.agregar_cedula("Maria Garcia", 87654321, false);
    
    auto1.agregar_infraccion("Av. Libertador", "Exceso de velocidad", 1500);
    auto1.agregar_infraccion("Calle 9 de Julio", "Estacionamiento indebido", 500);
    
    auto1.mostrar_informacion();
    
    return 0;
}
