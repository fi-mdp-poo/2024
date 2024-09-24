#include <stdio.h>
#include "vehicle.h"

int main() {
    // Crear una instancia de vehicle_t
    vehicle_t* my_vehicle = create_vehicle();

    if (my_vehicle == NULL) {
        printf("Error al crear el vehículo.\n");
        return -1;
    }

    // Usar los "métodos" de la estructura
    my_vehicle->set_manufacturer(my_vehicle, "Toyota");
    printf("Manufacturer: %s\n", my_vehicle->get_manufacturer(my_vehicle));

    my_vehicle->set_doors(my_vehicle, 4);
    printf("Doors: %d\n", my_vehicle->get_doors(my_vehicle));

    my_vehicle->set_km(my_vehicle, 50000);
    printf("Kilometers: %d\n", my_vehicle->get_km(my_vehicle));

    // Iniciar el vehículo
    my_vehicle->start(my_vehicle);
    printf("Vehicle started: %s\n", my_vehicle->is_started ? "Yes" : "No");

    // Detener el vehículo
    my_vehicle->stop(my_vehicle);
    printf("Vehicle started: %s\n", my_vehicle->is_started ? "Yes" : "No");

    // Destruir la instancia y liberar la memoria
    destroy_vehicle(my_vehicle);

    return 0;
}