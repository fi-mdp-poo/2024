#include "cManejadorServicios.h"

cManejadorServicios::cManejadorServicios()
{
    //ctor
}

cManejadorServicios::~cManejadorServicios()
{
    //dtor
}


void cManejadorServicios::cargarServicios(string fn)
{
    ifstream ptr_fn;
    ptr_fn.open("servicios.bin", ios::binary);

    if (!ptr_fn.is_open())
    {
        cerr << "Error: No se pudo abrir el archivo " << fn << endl;
        return ;
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
    char* buffer;

    ptr_fn.read(reinterpret_cast<char*>(&test),sizeof(int));

    for(int i = 0 ; i < test ; i++)
    {
        ptr_fn.read(reinterpret_cast<char*>(&id),sizeof(char));
        if ( id == 0xAA)
        {

            ptr_fn.read(reinterpret_cast<char*>(&cant),sizeof(int));

            buffer = new char[cant + 1]; // +1 para el terminador nulo
            ptr_fn.read(buffer, cant);
            buffer[cant] = '\0'; // Asegurar terminación nula
            name_trabajador = string(buffer);// Asignar al string
            //delete[] buffer;

            ///levanto el dia mes y anio de la fecha de ingreso del trabajador + el id
            ptr_fn.read(reinterpret_cast<char*>(&dia),sizeof(int));
            ptr_fn.read(reinterpret_cast<char*>(&mes),sizeof(int));
            ptr_fn.read(reinterpret_cast<char*>(&anio),sizeof(int));
            ptr_fn.read(reinterpret_cast<char*>(&id_trabajador),sizeof(int));

            ///levanto el dia mes y anio de la fehca del servicio

            ptr_fn.read(reinterpret_cast<char*>(&dia1),sizeof(int));
            ptr_fn.read(reinterpret_cast<char*>(&mes1),sizeof(int));
            ptr_fn.read(reinterpret_cast<char*>(&anio1),sizeof(int));

            ptr_fn.read(reinterpret_cast<char*>(&cant),sizeof(int));
            buffer = new char[cant + 1]; // +1 para el terminador nulo
            ptr_fn.read(buffer, cant);
            buffer[cant] = '\0'; // Asegurar terminación nula
            name_cliente = string(buffer);// Asignar al string


            ptr_fn.read(reinterpret_cast<char*>(&id_cliente),sizeof(int));
            ptr_fn.read(reinterpret_cast<char*>(&valor_superficie),sizeof(int));
            ptr_fn.read(reinterpret_cast<char*>(&valor_precio),sizeof(int));

            ///crear el servicio ya con todas las variables cargadas y merterlo en el vector
             //new cPintura(name_trabajador,dia,mes,anio,id_trabajador,dia1,mes1,anio1,name_cliente,id_cliente,valor_superficie,valor_precio);
            servicios.push_back(new cPintura(name_trabajador,dia,mes,anio,id_trabajador,dia1,mes1,anio1,name_cliente,id_cliente,valor_superficie,valor_precio));


        }
        else if( id == 0x55)
        {
            ///dia mes y anio de la fecha de servicio
            ptr_fn.read(reinterpret_cast<char*>(&dia1),sizeof(int));
            ptr_fn.read(reinterpret_cast<char*>(&mes1),sizeof(int));
            ptr_fn.read(reinterpret_cast<char*>(&anio1),sizeof(int));

            ptr_fn.read(reinterpret_cast<char*>(&cant),sizeof(int));
            buffer = new char[cant + 1]; // +1 para el terminador nulo
            ptr_fn.read(buffer, cant);
            buffer[cant] = '\0'; // Asegurar terminación nula
            name_cliente = string(buffer);// Asignar al string

            ///codigo id del cliente , cant de alarmas
            ptr_fn.read(reinterpret_cast<char*>(&id_cliente),sizeof(int));
            ptr_fn.read(reinterpret_cast<char*>(&cant_alarmas),sizeof(int));

            servicios.push_back(new cAlarma(dia1,mes1,anio1,name_cliente,id_cliente,cant_alarmas));



        }

    }

    delete[] buffer;
    ptr_fn.close();
}


void cManejadorServicios::ImprimirServicios(ostream& os)
{
    int tam = servicios.size();

    for(int i = 0 ; i < tam ; i++)
    {
        servicios[i]->vImprimir(os);
        os << *servicios[i];
    }

}
