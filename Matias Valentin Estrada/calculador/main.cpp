#include <iostream>
#include "CalculadorImpositivo.h"

using namespace std;

int main()
{
    // Creo el calculador
    CalculadorImpositivo calculador;

    // Inicializacion del sistema
    calculador.inicializar("Juan Perez", COMPLETO);

    // Funcionamiento correcto de la carga de facturas
    calculador.cargarFactura("Servicio 1", 1, 4000);
    calculador.cargarFactura("Servicio 2", 2, 6000);
    calculador.cargarFactura("Servicio 3", 3, 5500);

    // Funcionamiento correcto de la generacion de recibo de pago
    ReciboDePago recibo = calculador.calcularImpuesto(1, 3);

    cout << "Nombre del contribuyente: " << recibo.nombreDelContribuyente() << endl;
    cout << "Monto total: " << recibo.montoTotal() << endl;
    cout << "Monto fijo: " << recibo.montoFijo() << endl;
    cout << "Monto variable: " << recibo.montoVariable() << endl;
    cout << "Primera factura considerada: " << recibo.primeraFacturaConsiderada() << endl;
    cout << "Ultima factura considerada: " << recibo.ultimaFacturaConsiderada() << endl;

    return 0;
}
