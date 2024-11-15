cmake_minimum_required(VERSION 3.29)
project(GestorRegistros)

set(CMAKE_CXX_STANDARD 20)

add_executable(GestorRegistros main.cpp
        Persona/Persona.cpp
        Persona/Persona.h
        RegistroManager/RegistroManager.h)
