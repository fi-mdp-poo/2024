cmake_minimum_required(VERSION 3.29)
project(CalculadorImpositivo)

set(CMAKE_CXX_STANDARD 11)

add_executable(CalculadorImpositivo main.cpp
        CalculadorImpositivo/CalculadorImpositivo.cpp
        CalculadorImpositivo/CalculadorImpositivo.h
        CalculadorImpositivo/Contribuyente/Contribuyente.cpp
        CalculadorImpositivo/Contribuyente/Contribuyente.h
        CalculadorImpositivo/Factura/Factura.cpp
        CalculadorImpositivo/Factura/Factura.h
        CalculadorImpositivo/ReciboDePago/ReciboDePago.cpp
        CalculadorImpositivo/ReciboDePago/ReciboDePago.h
        CalculadorImpositivo/ContribuyenteFactory/ContribuyenteFactory.cpp
        CalculadorImpositivo/ContribuyenteFactory/ContribuyenteFactory.h
)
