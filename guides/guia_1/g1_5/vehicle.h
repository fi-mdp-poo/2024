#ifndef VEHICLE_H
#define VEHICLE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Forward declaration de la estructura vehicle_t
struct vehicle_t;

// Definir los punteros a funciones usando la forward declaration
typedef void (*vehicle_start_func)(struct vehicle_t* v);
typedef void (*vehicle_stop_func)(struct vehicle_t* v);
typedef void (*vehicle_set_manufacturer_func)(struct vehicle_t* v, const char* manufacturer);
typedef const char* (*vehicle_get_manufacturer_func)(struct vehicle_t* v);
typedef void (*vehicle_set_doors_func)(struct vehicle_t* v, int doors);
typedef int (*vehicle_get_doors_func)(struct vehicle_t* v);
typedef void (*vehicle_set_km_func)(struct vehicle_t* v, int km);
typedef int (*vehicle_get_km_func)(struct vehicle_t* v);

// Definir la estructura con los punteros a funciones
typedef struct vehicle_t
{
    char manufacturer[20];
    int doors;
    int km;
    bool is_started;

    // Punteros a funciones (métodos)
    vehicle_start_func start;
    vehicle_stop_func stop;
    vehicle_set_manufacturer_func set_manufacturer;
    vehicle_get_manufacturer_func get_manufacturer;
    vehicle_set_doors_func set_doors;
    vehicle_get_doors_func get_doors;
    vehicle_set_km_func set_km;
    vehicle_get_km_func get_km;
} vehicle_t;

// Funciones que actúan como "métodos" de la estructura
void vehicle_start(vehicle_t* v);
void vehicle_stop(vehicle_t* v);
void vehicle_set_manufacturer(vehicle_t* v, const char* manufacturer);
const char* vehicle_get_manufacturer(vehicle_t* v);
void vehicle_set_doors(vehicle_t* v, int doors);
int vehicle_get_doors(vehicle_t* v);
void vehicle_set_km(vehicle_t* v, int km);
int vehicle_get_km(vehicle_t* v);

// Funciones para inicializar, crear y destruir instancias de vehicle_t
void vehicle_init(vehicle_t* v);
vehicle_t* create_vehicle();
void destroy_vehicle(vehicle_t* v);

#endif