#include "calculador_impositivo.h"
#include <iostream>

int main() {
    calculador_impositivo calculador;

    // Inicialización del sistema
    calculador.inicializar("Juan Pérez", COMPLETO);

    // Funcionamiento correcto de la carga de facturas
    calculador.cargar_factura("Servicio 1", 1, 4000);
    calculador.cargar_factura("Servicio 2", 2, 6000);
    calculador.cargar_factura("Servicio 3", 3, 5500);

    // Funcionamiento correcto de la generación de recibo de pago
    recibo_de_pago recibo = calculador.calcular_impuesto(1, 3);

    std::cout << "Nombre del contribuyente: " << recibo.nombre_del_contribuyente() << std::endl;
    std::cout << "Monto total: " << recibo.monto_total() << std::endl;
    std::cout << "Monto fijo: " << recibo.monto_fijo() << std::endl;
    std::cout << "Monto variable: " << recibo.monto_variable() << std::endl;
    std::cout << "Primera factura considerada: " << recibo.primera_factura_considerada() << std::endl;
    std::cout << "Última factura considerada: " << recibo.ultima_factura_considerada() << std::endl;

    return 0;
}