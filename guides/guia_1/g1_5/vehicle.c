#include "vehicle.h"

// Funciones que actúan como "métodos" de la estructura
void vehicle_start(vehicle_t* v) {
    v->is_started = true;
}

void vehicle_stop(vehicle_t* v) {
    v->is_started = false;
}

void vehicle_set_manufacturer(vehicle_t* v, const char* manufacturer) {
    strncpy(v->manufacturer, manufacturer, sizeof(v->manufacturer) - 1);
    v->manufacturer[sizeof(v->manufacturer) - 1] = '\0'; // Asegurar el terminador nulo
}

const char* vehicle_get_manufacturer(vehicle_t* v) {
    return v->manufacturer;
}

void vehicle_set_doors(vehicle_t* v, int doors) {
    v->doors = doors;
}

int vehicle_get_doors(vehicle_t* v) {
    return v->doors;
}

void vehicle_set_km(vehicle_t* v, int km) {
    v->km = km;
}

int vehicle_get_km(vehicle_t* v) {
    return v->km;
}

// Inicialización de la estructura
void vehicle_init(vehicle_t* v) {
    // Inicializar valores
    v->is_started = false;
    v->doors = 0;
    v->km = 0;
    memset(v->manufacturer, 0, sizeof(v->manufacturer));

    // Asignar las funciones como "métodos"
    v->start = vehicle_start;
    v->stop = vehicle_stop;
    v->set_manufacturer = vehicle_set_manufacturer;
    v->get_manufacturer = vehicle_get_manufacturer;
    v->set_doors = vehicle_set_doors;
    v->get_doors = vehicle_get_doors;
    v->set_km = vehicle_set_km;
    v->get_km = vehicle_get_km;
}

// Crear una instancia de vehicle_t dinámicamente
vehicle_t* create_vehicle() {
    vehicle_t* v = (vehicle_t*)malloc(sizeof(vehicle_t));  // Asignar memoria dinámica
    if (v != NULL) {
        vehicle_init(v);  // Inicializar la estructura
    }
    return v;
}

// Liberar la memoria asignada al vehículo
void destroy_vehicle(vehicle_t* v) {
    free(v);  // Liberar la memoria
}