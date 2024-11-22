#include "C_ManejadordeServicios.h"
#include <algorithm>

C_ManejadordeServicios::C_ManejadordeServicios()
{
    //ctor
}

C_ManejadordeServicios::~C_ManejadordeServicios()
{
    //dtor
}

void C_ManejadordeServicios::Cargar_Servicios(string filename)
{
try {
        ifstream ptr_fn;
        ptr_fn.open(filename, ios::binary);

        if (!ptr_fn.is_open()) {
            throw runtime_error("Error: No se pudo abrir el archivo " + filename);
        }

        int test;
        uint8_t id;
        int cant;
        int id_trabajador;
        int id_cliente;
        string name_trabajador;
        string name_cliente;
        int dia;
        int dia1;
        int mes;
        int mes1;
        int anio;
        int anio1;
        int cant_alarmas;

        float valor_superficie;
        float valor_precio;
        char* buffer = nullptr;

        ptr_fn.read(reinterpret_cast<char*>(&test), sizeof(int));

        for (int i = 0; i < test; i++) {
            ptr_fn.read(reinterpret_cast<char*>(&id), sizeof(char));
            if (id == 0xAA) {
                ptr_fn.read(reinterpret_cast<char*>(&cant), sizeof(int));
                buffer = new char[cant + 1]; // +1 para el terminador nulo
                ptr_fn.read(buffer, cant);
                buffer[cant] = '\0'; // Asegurar terminación nula
                name_trabajador = string(buffer); // Asignar al string

                // Levanto el dia, mes y anio de la fecha de ingreso del trabajador + el id
                ptr_fn.read(reinterpret_cast<char*>(&dia), sizeof(int));
                ptr_fn.read(reinterpret_cast<char*>(&mes), sizeof(int));
                ptr_fn.read(reinterpret_cast<char*>(&anio), sizeof(int));
                ptr_fn.read(reinterpret_cast<char*>(&id_trabajador), sizeof(int));

                // Levanto el dia, mes y anio de la fecha del servicio
                ptr_fn.read(reinterpret_cast<char*>(&dia1), sizeof(int));
                ptr_fn.read(reinterpret_cast<char*>(&mes1), sizeof(int));
                ptr_fn.read(reinterpret_cast<char*>(&anio1), sizeof(int));

                ptr_fn.read(reinterpret_cast<char*>(&cant), sizeof(int));
                buffer = new char[cant + 1]; // +1 para el terminador nulo
                ptr_fn.read(buffer, cant);
                buffer[cant] = '\0'; // Asegurar terminación nula
                name_cliente = string(buffer); // Asignar al string

                ptr_fn.read(reinterpret_cast<char*>(&id_cliente), sizeof(int));
                ptr_fn.read(reinterpret_cast<char*>(&valor_superficie), sizeof(int));
                ptr_fn.read(reinterpret_cast<char*>(&valor_precio), sizeof(int));

                // Crear el servicio ya con todas las variables cargadas y meterlo en el vector
                servicios.push_back(new C_TrabajoPintura(name_trabajador, dia, mes, anio, id_trabajador, dia1, mes1, anio1, name_cliente, id_cliente, valor_superficie, valor_precio));
            }
            else if (id == 0x55) {
                // Dia, mes y anio de la fecha de servicio
                ptr_fn.read(reinterpret_cast<char*>(&dia1), sizeof(int));
                ptr_fn.read(reinterpret_cast<char*>(&mes1), sizeof(int));
                ptr_fn.read(reinterpret_cast<char*>(&anio1), sizeof(int));

                ptr_fn.read(reinterpret_cast<char*>(&cant), sizeof(int));
                buffer = new char[cant + 1]; // +1 para el terminador nulo
                ptr_fn.read(buffer, cant);
                buffer[cant] = '\0'; // Asegurar terminación nula
                name_cliente = string(buffer); // Asignar al string

                // Codigo id del cliente y cantidad de alarmas
                ptr_fn.read(reinterpret_cast<char*>(&id_cliente), sizeof(int));
                ptr_fn.read(reinterpret_cast<char*>(&cant_alarmas), sizeof(int));

                servicios.push_back(new C_RevisionAlarma(dia1, mes1, anio1, name_cliente, id_cliente, cant_alarmas));
            }
        }

        delete[] buffer;
        ptr_fn.close();
    }
    catch (const exception& e) {
//        cout<<"jorge mi puta"<<endl;
//        cerr << e.what() << '\n';
        // Podrías agregar más manejo de errores aquí (como la liberación de recursos)
        throw;
    }
}

void C_ManejadordeServicios::ImprimirServicios(ostream& os)
{
      int tam = servicios.size();

    for(int i = 0 ; i < tam ; i++)
    {
        servicios[i]->vImprimir(os);
        os << *servicios[i];
    }
}

// Ordenar los servicios por fecha (en orden creciente)
void C_ManejadordeServicios::OrdenarPorFecha() {
    sort(servicios.begin(), servicios.end(), [](C_Servicio* a, C_Servicio* b) {
        // Comparar fechas de inicio de los servicios para ordenarlas en orden creciente
        return !a->Getinicio_servicio().fechaEsMayor(b->Getinicio_servicio()); // Primero los más antiguos
    });
}

// Ordenar los servicios por nombre de cliente (en orden decreciente)
void C_ManejadordeServicios::OrdenarPorNombre() {
    sort(servicios.begin(), servicios.end(), [](C_Servicio* a, C_Servicio* b) {
        // Comparar nombres de cliente en orden decreciente
        return a->Getcliente().Getnombre_cliente() > b->Getcliente().Getnombre_cliente();
    });
}

