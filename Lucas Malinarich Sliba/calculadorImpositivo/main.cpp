#include <iostream>
#include "claseCalculador.h"

using namespace std;

// Programa de prueba
int main() {
    CalculadorImpositivo calculador;

    // Inicialización del sistema
    calculador.inicializar("Juan Prez", EXTENDIDO);

    // Funcionamiento correcto de la carga de facturas
    calculador.cargarFactura("Servicio 1", 1, 4000);
    calculador.cargarFactura("Servicio 2", 2, 6000);
    calculador.cargarFactura("Servicio 3", 3, 5500);

    // Funcionamiento correcto de la generación de recibo de pago
    ReciboDePago recibo = calculador.calcularImpuesto(1, 3);

    std::cout << "Nombre del contribuyente: " << recibo.nombreDelContribuyente() << std::endl;
    std::cout << "Monto total: " << recibo.getMontoTotal() << std::endl;
    std::cout << "Monto fijo: " << recibo.getMontoFijo() << std::endl;
    std::cout << "Monto variable: " << recibo.getMontoVariable() << std::endl;
    std::cout << "Primera factura considerada: " << recibo.primeraFacturaConsiderada() << std::endl;
    std::cout << "ltima factura considerada: " << recibo.ultimaFacturaConsiderada() << std::endl;

    return 0;
}
