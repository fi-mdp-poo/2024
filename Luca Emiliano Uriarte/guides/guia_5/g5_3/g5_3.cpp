#include "cuentas_bancarias.h"
#include <iostream>

int main() {
  // Crear instancias de las cuentas
  std::shared_ptr<Cuenta> cc =
      std::make_shared<CuentaCorriente>("Juan Perez", 1000.0, 500.0);
  std::shared_ptr<Cuenta> ca =
      std::make_shared<CajaAhorro>("Maria Lopez", 2000.0, 5);
  std::shared_ptr<Cuenta> cu =
      std::make_shared<CuentaUniversitaria>("Ana Garcia", 500.0);

  // Crear banco y agregar cuentas
  Banco banco;
  banco.agregar_cuenta(cc);
  banco.agregar_cuenta(ca);
  banco.agregar_cuenta(cu);

  // Realizar algunas operaciones
  cc->extraer(1200); // Extracción permitida con descubierto
  ca->extraer(300);  // Extracción permitida
  cu->extraer(80);   // Extracción permitida
  cu->extraer(150);  // Extracción no permitida (supera el límite diario)

  // Imprimir el activo disponible en el banco
  std::cout << "Activo disponible en el banco: $"
            << banco.obtener_activo_disponible() << std::endl;

  return 0;
}