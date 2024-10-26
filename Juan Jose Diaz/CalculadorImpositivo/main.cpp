#include <fstream>

#include "CalculadorImpositivo/CalculadorImpositivo.h"

using namespace std;

CategoriaEnum getCategoria(const int opcion) {
    switch (opcion) {
        case 1:
            return CategoriaEnum::Limitado;
        case 2:
            return CategoriaEnum::Completo;
        case 3:
            return CategoriaEnum::Extendido;
        default:
            throw invalid_argument("Categoria del contribuyente inválida");
    }
}

ostream& operator<<(ostream& out, const ReciboDePago& recibo) {
    out << "Nombre del contribuyente: " << recibo.getNombreDelContribuyente() << endl;
    out << "Monto fijo: $" << recibo.getMontoFijo() << endl;
    out << "Monto variable: $" << recibo.getMontoVariable() << endl;
    out << "Monto total: $" << recibo.getMontoTotal() << endl;
    out << "Primera factura considerada: " << recibo.getPrimeraFacturaConsiderada() << endl;
    out << "Última factura considerada: " << recibo.getUltimaFacturaConsiderada() << endl;

    return out;
}

int main() {
    // La idea es que el calculador impositivo reciba los datos que necesite del contribuyente para operar
    string nombre;
    int opcionCategoria;

    cout << "Ingrese su nombre: ";
    getline(cin, nombre);

    cout << "Seleccione la categoria del contribuyente:" << endl;
    cout << "1. Limitado" << endl;
    cout << "2. Completo" << endl;
    cout << "3. Extendido" << endl;

    cout << "Opción: ";
    cin >> opcionCategoria;

    try {
        const CategoriaEnum categoria = getCategoria(opcionCategoria);
        CalculadorImpositivo calculador;
        calculador.inicializar(nombre, categoria);

        // @TODO: realizar interfaz para agregar facturas
        calculador.agregarFactura("Asesoría", 1001, 6000);
        calculador.agregarFactura("Consultoría", 1002, 30000);
        calculador.agregarFactura("Mantenimiento", 1003, 8000);

        const ReciboDePago recibo = calculador.calcularImpuesto(1001, 1003);

        /**
         * La idea es dejar flexible la salida, sobrecargando del operador <<.
         * En este caso, creando un archivo de texto para imprimir el recibo de pago
         */
        const string nombreArchivo = "recibo_" + nombre + ".txt";
        ofstream fout(nombreArchivo); // se crea una instancia de un archivo de texto para imprimir el recibo
        fout << recibo;
        cout << "Se creó el archivo " << nombreArchivo << " exitosamente" << endl;
        fout.close();

        return EXIT_SUCCESS;
    } catch (const exception& e) {
        cerr << e.what() << endl;
        return EXIT_FAILURE;
    }
}
