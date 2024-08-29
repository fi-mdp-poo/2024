cmake_minimum_required(VERSION 3.5.0)
project(poo VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_BUILD_TYPE Debug)

# Flags para debug y para deshabilitar optimizaciones
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g")

set(SOURCES
    tests/composicion/main.cpp
    tests/composicion/composicion.cpp
)

# Define el ejecutable con todos los archivos fuente
add_executable(APP ${SOURCES})