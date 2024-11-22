#ifndef CUENTAS_BANCARIAS_H
#define CUENTAS_BANCARIAS_H

#include <memory>
#include <string>
#include <vector>

class Cuenta {
protected:
  std::string titular;
  double saldo;

public:
  Cuenta(const std::string &titular, double saldo_inicial);
  virtual ~Cuenta() = default;

  virtual bool extraer(double monto) = 0; // Método virtual puro
  void depositar(double monto);
  double obtener_saldo() const;
  std::string obtener_titular() const;
};

class CuentaCorriente : public Cuenta {
private:
  double limite_descubierto;

public:
  CuentaCorriente(const std::string &titular, double saldo_inicial,
                  double limite);
  bool extraer(double monto) override;
};

class CajaAhorro : public Cuenta {
private:
  int extracciones_mensuales;
  int extracciones_realizadas;
  static const int limite_extracciones;

public:
  CajaAhorro(const std::string &titular, double saldo_inicial,
             int extracciones_mensuales);
  bool extraer(double monto) override;
  void reiniciar_extracciones();
};

class CuentaUniversitaria : public Cuenta {
private:
  static const double limite_diario;

public:
  CuentaUniversitaria(const std::string &titular, double saldo_inicial);
  bool extraer(double monto) override;
};

class Banco {
private:
  std::vector<std::shared_ptr<Cuenta>> cuentas;

public:
  void agregar_cuenta(const std::shared_ptr<Cuenta> &cuenta);
  double obtener_activo_disponible() const;
};

#endif // CUENTAS_BANCARIAS_H