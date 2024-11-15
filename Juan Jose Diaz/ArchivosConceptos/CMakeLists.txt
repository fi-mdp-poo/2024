cmake_minimum_required(VERSION 3.29)
project(ArchivosConceptos)

set(CMAKE_CXX_STANDARD 20)

add_executable(ArchivosConceptos main.cpp
        Archivo/Archivo.cpp
        Archivo/Archivo.h
        Archivo/ArchivoExceptions/ArchivoException.h
        Archivo/ArchivoExceptions/ArchivoAperturaException.h
        Archivo/ArchivoExceptions/ArchivoLecturaException.h)
