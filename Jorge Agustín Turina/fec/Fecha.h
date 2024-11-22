#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <iostream>
#include <stdexcept>
#include <iomanip> // para imprimir bien
#include <ctime> // para obtener la fecha actual


class Fecha {
private:
    int dia;
    int mes;
    int anio;

    // Método auxiliar para verificar si un año es bisiesto
    bool esBisiesto(int anio) const {
        return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
    }

    // Método auxiliar para obtener los días en un mes
    int diasEnMes(int mes, int anio) const {
        static const int diasPorMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (mes == 2 && esBisiesto(anio)) {
            return 29;
        }
        return diasPorMes[mes - 1];
    }

    // Método auxiliar para validar una fecha
    void validarFecha(int dia, int mes, int anio) const {
        if (mes < 1 || mes > 12) {
            throw std::invalid_argument("Mes invalido.");
        }
        if (dia < 1 || dia > diasEnMes(mes, anio)) {
            throw std::invalid_argument("Dia invalido.");
        }
    }

public:
    // Constructor por defecto
    Fecha() : dia(1), mes(1), anio(1900) {}

    // Constructor con parámetros
    Fecha(int dia, int mes, int anio) {
        setFecha(dia, mes, anio);
    }

    // Setters con manejo interno de errores
    void setFecha(int dia, int mes, int anio) {
        try {
            validarFecha(dia, mes, anio);
            this->dia = dia;
            this->mes = mes;
            this->anio = anio;
        } catch (const std::exception& e) {
            std::cerr << "Error en setFecha: " << e.what() << std::endl;
            this->dia = 1;
            this->mes = 1;
            this->anio = 1900; // Fecha por defecto
        }
    }

    void setDia(int dia) {
        try {
            validarFecha(dia, this->mes, this->anio);
            this->dia = dia;
        } catch (const std::exception& e) {
            std::cerr << "Error en setDia: " << e.what() << std::endl;
        }
    }

    void setMes(int mes) {
        try {
            validarFecha(this->dia, mes, this->anio);
            this->mes = mes;
        } catch (const std::exception& e) {
            std::cerr << "Error en setMes: " << e.what() << std::endl;
        }
    }

    void setAnio(int anio) {
        try {
            validarFecha(this->dia, this->mes, anio);
            this->anio = anio;
        } catch (const std::exception& e) {
            std::cerr << "Error en setAnio: " << e.what() << std::endl;
        }
    }

    // Getters
    int getDia() const { return dia; }
    int getMes() const { return mes; }
    int getAnio() const { return anio; }

    // Sobrecarga del operador de inserción
    friend std::ostream& operator<<(std::ostream& os, const Fecha& fecha) {
        os << std::setw(2) << std::setfill('0') << fecha.dia << "/"
           << std::setw(2) << std::setfill('0') << fecha.mes << "/"
           << fecha.anio;
        return os;
    }

    // Constructor de copia
    Fecha(const Fecha& otraFecha) : dia(otraFecha.dia), mes(otraFecha.mes), anio(otraFecha.anio) {}

    // Operador de asignación
    Fecha& operator=(const Fecha& otraFecha) {
        if (this != &otraFecha) { // Evitar autoasignación
            dia = otraFecha.dia;
            mes = otraFecha.mes;
            anio = otraFecha.anio;
        }
        return *this;
    }

    // Método para obtener la fecha actual
    void obtenerFechaActual() {
        std::time_t t = std::time(nullptr);
        std::tm* ahora = std::localtime(&t);

        dia = ahora->tm_mday;
        mes = ahora->tm_mon + 1; // Los meses empiezan desde 0
        anio = ahora->tm_year + 1900; // El año se cuenta desde 1900
    }
};

#endif // FECHA_H_INCLUDED
