#include <iostream>
#include "contribuyente.h"
#include "factura.h"
#include "recibo.h"
#include "calculador.h"

using namespace std;

int main(){
    Contribuyente* contribuyente1 = new Limitado("Matias Estrada");
    Contribuyente* contribuyente2 = new Completo("Amilcar Alcaraz");
    Contribuyente* contribuyente3 = new Extendido("Ricardo Fort");

    // Cargo las facturas de cada contribuyente
    contribuyente1->agregarFactura(Factura(1001, "EDEA Energia", 3123.49));
    contribuyente1->agregarFactura(Factura(1002, "Camuzzi Gas", 6736.23));

    contribuyente2->agregarFactura(Factura(1003, "Movistar Internet", 7288.15));

    contribuyente3->agregarFactura(Factura(1004, "ARBA Automotores", 9934.88));

    // Creo el calculador
    Calculador calculador;

    // Calculo los impuestos de cada contribuyente
    ReciboDePago recibo1 = calculador.calcularImpuesto(*contribuyente1, 1001, 1002);
    ReciboDePago recibo2 = calculador.calcularImpuesto(*contribuyente2, 1003, 1003);
    ReciboDePago recibo3 = calculador.calcularImpuesto(*contribuyente3, 1004, 1004);

    // Muestro los recibos
    recibo1.printRecibo();
    cout << endl << endl;
    recibo2.printRecibo();
    cout << endl << endl;
    recibo3.printRecibo();
    cout << endl << endl;

    return 0;
}
