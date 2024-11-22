#include "ManejadorServicios.h"

ManejadorServicios::ManejadorServicios()
{
    //ctor
}

ManejadorServicios::~ManejadorServicios()
{
    //dtor
}

void ManejadorServicios::cargar_datos(string nombre_archivo)
{
    ifstream flujo_entrada;
    flujo_entrada.open(nombre_archivo, ios_base::binary);


     // Variable para almacenar un entero leído desde el archivo
    int cantidad_trabajos = 0;
    int tipo_de_trabajo = 0;
    char caracter = 'a';

    // Leer un solo número entero desde el archivo binario
    flujo_entrada.read(reinterpret_cast<char*>(&cantidad_trabajos), sizeof(cantidad_trabajos));
    for (int i=0 ; i< cantidad_trabajos ; i++){

    flujo_entrada.read(reinterpret_cast<char*>(&tipo_de_trabajo), sizeof(caracter));
    ///cout << "lei" << tipo_de_trabajo << endl;
    if(tipo_de_trabajo == 85){
        cout << "alarma"<< endl;
    }

    if(tipo_de_trabajo == 170){
        cout << "pintura"<< endl;
        TrabajoPintura pintura = TrabajoPintura();
        int longitud_nombre = 0;
        //string nombre = "";
        //char* nombre = new char(longitud_nombre);
        flujo_entrada.read(reinterpret_cast<char*>(&longitud_nombre), sizeof(longitud_nombre));
        char* nombre = new char(longitud_nombre);

        flujo_entrada.read(reinterpret_cast<char*>(&nombre), sizeof(longitud_nombre*caracter));

        pintura.Setnombre(nombre);


    }




    }


    cout << cantidad_trabajos << endl;


}




void ManejadorServicios::cargar_datos2(string nombre_archivo)
{
    ifstream flujo_entrada;
    flujo_entrada.open(nombre_archivo, ios_base::binary);

    // Variable para almacenar un entero leído desde el archivo binario
    int cantidad_trabajos = 0;
    int tipo_de_trabajo = 0;

    // Leer el número de trabajos desde el archivo binario
    flujo_entrada.read(reinterpret_cast<char*>(&cantidad_trabajos), sizeof(cantidad_trabajos));

    for (int i = 0; i < cantidad_trabajos; i++) {

        // Leer el tipo de trabajo (alarma o pintura)
        flujo_entrada.read(reinterpret_cast<char*>(&tipo_de_trabajo), sizeof(tipo_de_trabajo));

        if (tipo_de_trabajo == 55) {
            // Si es un trabajo de alarma
            cout << "alarma" << endl;

            // Leer la fecha de servicio
            int dia, mes, anio;
            flujo_entrada.read(reinterpret_cast<char*>(&dia), sizeof(dia));
            flujo_entrada.read(reinterpret_cast<char*>(&mes), sizeof(mes));
            flujo_entrada.read(reinterpret_cast<char*>(&anio), sizeof(anio));

            // Leer el nombre del cliente
            int longitud_nombre_cliente = 0;
            flujo_entrada.read(reinterpret_cast<char*>(&longitud_nombre_cliente), sizeof(longitud_nombre_cliente));
            char* nombre_cliente = new char[longitud_nombre_cliente];
            flujo_entrada.read(reinterpret_cast<char*>(nombre_cliente), longitud_nombre_cliente * sizeof(char));

            // Leer el código identificatorio del cliente
            int codigo_cliente = 0;
            flujo_entrada.read(reinterpret_cast<char*>(&codigo_cliente), sizeof(codigo_cliente));

            // Leer la cantidad de alarmas a revisar
            int cantidad_alarmas = 0;
            flujo_entrada.read(reinterpret_cast<char*>(&cantidad_alarmas), sizeof(cantidad_alarmas));
        }
        else if (tipo_de_trabajo == 85) {
            // Si es un trabajo de pintura
            cout << "pintura" << endl;
            TrabajoPintura pintura;

            // Leer la información del trabajador
            int longitud_nombre_trabajador = 0;
            flujo_entrada.read(reinterpret_cast<char*>(&longitud_nombre_trabajador), sizeof(longitud_nombre_trabajador));
            char* nombre_trabajador = new char[longitud_nombre_trabajador];
            flujo_entrada.read(reinterpret_cast<char*>(nombre_trabajador), longitud_nombre_trabajador * sizeof(char));

            // Leer la fecha de ingreso del trabajador
            int dia_ingreso, mes_ingreso, anio_ingreso;
            flujo_entrada.read(reinterpret_cast<char*>(&dia_ingreso), sizeof(dia_ingreso));
            flujo_entrada.read(reinterpret_cast<char*>(&mes_ingreso), sizeof(mes_ingreso));
            flujo_entrada.read(reinterpret_cast<char*>(&anio_ingreso), sizeof(anio_ingreso));

            // Leer el código identificatorio del trabajador
            int codigo_trabajador = 0;
            flujo_entrada.read(reinterpret_cast<char*>(&codigo_trabajador), sizeof(codigo_trabajador));

            // Leer la fecha del servicio
            int dia_servicio, mes_servicio, anio_servicio;
            flujo_entrada.read(reinterpret_cast<char*>(&dia_servicio), sizeof(dia_servicio));
            flujo_entrada.read(reinterpret_cast<char*>(&mes_servicio), sizeof(mes_servicio));
            flujo_entrada.read(reinterpret_cast<char*>(&anio_servicio), sizeof(anio_servicio));

            // Leer el nombre del cliente
            int longitud_nombre_cliente = 0;
            flujo_entrada.read(reinterpret_cast<char*>(&longitud_nombre_cliente), sizeof(longitud_nombre_cliente));
            char* nombre_cliente = new char[longitud_nombre_cliente];
            flujo_entrada.read(reinterpret_cast<char*>(nombre_cliente), longitud_nombre_cliente * sizeof(char));

            // Leer el código identificatorio del cliente
            int codigo_cliente = 0;
            flujo_entrada.read(reinterpret_cast<char*>(&codigo_cliente), sizeof(codigo_cliente));

            // Leer la superficie y el precio de la pintura
            float superficie = 0.0f;
            flujo_entrada.read(reinterpret_cast<char*>(&superficie), sizeof(superficie));

            float precio_pintura = 0.0f;
            flujo_entrada.read(reinterpret_cast<char*>(&precio_pintura), sizeof(precio_pintura));

            // Asignar los datos a la clase de trabajo de pintura
            pintura.Setnombre(nombre_trabajador);
        }
    }

    cout << "Cantidad de trabajos leídos: " << cantidad_trabajos << endl;
}

