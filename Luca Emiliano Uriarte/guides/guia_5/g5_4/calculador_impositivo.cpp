#include "calculador_impositivo.h"

double categoria_limitado::calcular_monto_variable(double monto) const {
    return monto * 0.005; // 0.5% de lo facturado
}

double categoria_completo::calcular_monto_variable(double monto) const {
    return monto > 5000 ? monto * 0.5 : 0.0; // 50% si el monto supera 5000
}

double categoria_extendido::calcular_monto_variable(double monto) const {
    return monto > 5000 ? monto * 0.5 + 10.0 : 10.0; // 50% + $10 extra
}

std::unique_ptr<categoria_base> categoria_factory::crear_categoria(categoria_enum tipo) {
    switch (tipo) {
        case LIMITADO:
            return std::make_unique<categoria_limitado>();
        case COMPLETO:
            return std::make_unique<categoria_completo>();
        case EXTENDIDO:
            return std::make_unique<categoria_extendido>();
        default:
            return nullptr;
    }
}

factura::factura(const std::string& detalle, int numero, double monto)
    : detalle_(detalle), numero_(numero), monto_(monto) {}

int factura::numero() const {
    return numero_;
}

double factura::monto() const {
    return monto_;
}

recibo_de_pago::recibo_de_pago(const std::string& nombre, double monto_fijo, double monto_variable, int primera_factura, int ultima_factura)
    : nombre_contribuyente_(nombre), monto_fijo_(monto_fijo), monto_variable_(monto_variable), primera_factura_(primera_factura), ultima_factura_(ultima_factura) {}

std::string recibo_de_pago::nombre_del_contribuyente() const {
    return nombre_contribuyente_;
}

double recibo_de_pago::monto_total() const {
    return monto_fijo_ + monto_variable_;
}

double recibo_de_pago::monto_fijo() const {
    return monto_fijo_;
}

double recibo_de_pago::monto_variable() const {
    return monto_variable_;
}

int recibo_de_pago::primera_factura_considerada() const {
    return primera_factura_;
}

int recibo_de_pago::ultima_factura_considerada() const {
    return ultima_factura_;
}

calculador_impositivo::calculador_impositivo() : monto_fijo_(5.0) {}

void calculador_impositivo::inicializar(const std::string& nombre, categoria_enum tipo_categoria) {
    nombre_contribuyente_ = nombre;
    categoria_ = categoria_factory::crear_categoria(tipo_categoria);
}

void calculador_impositivo::cargar_factura(const std::string& detalle, int numero, double monto) {
    facturas_.emplace_back(detalle, numero, monto);
}

recibo_de_pago calculador_impositivo::calcular_impuesto(int desde, int hasta) const {
    double monto_variable = 0.0;
    for (const auto& factura : facturas_) {
        if (factura.numero() >= desde && factura.numero() <= hasta) {
            monto_variable += categoria_->calcular_monto_variable(factura.monto());
        }
    }

    return recibo_de_pago(nombre_contribuyente_, monto_fijo_, monto_variable, desde, hasta);
}