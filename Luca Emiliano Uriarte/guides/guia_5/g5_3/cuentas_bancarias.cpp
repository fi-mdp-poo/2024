#include "cuentas_bancarias.h"

Cuenta::Cuenta(const std::string &titular, double saldo_inicial)
    : titular(titular), saldo(saldo_inicial) {}

void Cuenta::depositar(double monto) { saldo += monto; }

double Cuenta::obtener_saldo() const { return saldo; }

std::string Cuenta::obtener_titular() const { return titular; }

CuentaCorriente::CuentaCorriente(const std::string &titular,
                                 double saldo_inicial, double limite)
    : Cuenta(titular, saldo_inicial), limite_descubierto(limite) {}

bool CuentaCorriente::extraer(double monto) {
  if (saldo + limite_descubierto >= monto) {
    saldo -= monto;
    return true;
  }
  return false;
}

const int CajaAhorro::limite_extracciones = 5;

CajaAhorro::CajaAhorro(const std::string &titular, double saldo_inicial,
                       int extracciones_mensuales)
    : Cuenta(titular, saldo_inicial),
      extracciones_mensuales(extracciones_mensuales),
      extracciones_realizadas(0) {}

bool CajaAhorro::extraer(double monto) {
  if (saldo >= monto && extracciones_realizadas < limite_extracciones) {
    saldo -= monto;
    extracciones_realizadas++;
    return true;
  }
  return false;
}

void CajaAhorro::reiniciar_extracciones() { extracciones_realizadas = 0; }

const double CuentaUniversitaria::limite_diario = 100.0;

CuentaUniversitaria::CuentaUniversitaria(const std::string &titular,
                                         double saldo_inicial)
    : Cuenta(titular, saldo_inicial) {}

bool CuentaUniversitaria::extraer(double monto) {
  if (monto <= limite_diario && saldo >= monto) {
    saldo -= monto;
    return true;
  }
  return false;
}

void Banco::agregar_cuenta(const std::shared_ptr<Cuenta> &cuenta) {
  cuentas.push_back(cuenta);
}

double Banco::obtener_activo_disponible() const {
  double total = 0.0;
  for (const auto &cuenta : cuentas) {
    total += cuenta->obtener_saldo();
  }
  return total;
}