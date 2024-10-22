#ifndef CALCULADOR_IMPOSITIVO_H
#define CALCULADOR_IMPOSITIVO_H

#include <string>
#include <vector>
#include <memory>

enum categoria_enum {
    LIMITADO,
    COMPLETO,
    EXTENDIDO
};

class categoria_base {
public:
    virtual ~categoria_base() = default;
    virtual double calcular_monto_variable(double monto) const = 0;
};

class categoria_limitado : public categoria_base {
public:
    double calcular_monto_variable(double monto) const override;
};

class categoria_completo : public categoria_base {
public:
    double calcular_monto_variable(double monto) const override;
};

class categoria_extendido : public categoria_base {
public:
    double calcular_monto_variable(double monto) const override;
};

class categoria_factory {
public:
    static std::unique_ptr<categoria_base> crear_categoria(categoria_enum tipo);
};

class factura {
public:
    factura(const std::string& detalle, int numero, double monto);
    int numero() const;
    double monto() const;

private:
    std::string detalle_;
    int numero_;
    double monto_;
};

class recibo_de_pago {
public:
    recibo_de_pago(const std::string& nombre, double monto_fijo, double monto_variable, int primera_factura, int ultima_factura);

    std::string nombre_del_contribuyente() const;
    double monto_total() const;
    double monto_fijo() const;
    double monto_variable() const;
    int primera_factura_considerada() const;
    int ultima_factura_considerada() const;

private:
    std::string nombre_contribuyente_;
    double monto_fijo_;
    double monto_variable_;
    int primera_factura_;
    int ultima_factura_;
};

class calculador_impositivo {
public:
    calculador_impositivo();
    
    void inicializar(const std::string& nombre, categoria_enum tipo_categoria);
    void cargar_factura(const std::string& detalle, int numero, double monto);
    recibo_de_pago calcular_impuesto(int desde, int hasta) const;

private:
    std::string nombre_contribuyente_;
    std::unique_ptr<categoria_base> categoria_;
    std::vector<factura> facturas_;
    double monto_fijo_;
};

#endif // CALCULADOR_IMPOSITIVO_H