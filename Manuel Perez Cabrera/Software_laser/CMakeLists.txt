cmake_minimum_required(VERSION 3.16)

project(Software_laser VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Software_laser
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        logindialog.h logindialog.cpp logindialog.ui
        registerdialog.h registerdialog.cpp registerdialog.ui
        producto.h producto.cpp
        gestionstock.h gestionstock.cpp
        dialogagregarproducto.h dialogagregarproducto.cpp dialogagregarproducto.ui
        dialogeliminarproducto.h dialogeliminarproducto.cpp dialogeliminarproducto.ui

        clienteClientes/cliente.h clienteClientes/cliente.cpp
        clienteClientes/gestorclientes.h clienteClientes/gestorclientes.cpp
        clienteClientes/dialogclientes.h clienteClientes/dialogclientes.cpp clienteClientes/dialogclientes.ui
        clienteClientes/dialogagregarcliente.h clienteClientes/dialogagregarcliente.cpp clienteClientes/dialogagregarcliente.ui
        clienteClientes/dialogeliminarcliente.h clienteClientes/dialogeliminarcliente.cpp clienteClientes/dialogeliminarcliente.ui

        pedidosClientes/pedidos.h pedidosClientes/pedidos.cpp
        pedidosClientes/dialogpedido.h pedidosClientes/dialogpedido.cpp pedidosClientes/dialogpedido.ui
        pedidosClientes/gestorpedidos.h pedidosClientes/gestorpedidos.cpp
        pedidosClientes/pedidoespecial.h pedidosClientes/pedidoespecial.cpp
        pedidosClientes/pedidonormal.h pedidosClientes/pedidonormal.cpp



    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Software_laser APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Software_laser SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Software_laser
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Software_laser PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Software_laser)
endif()
set_target_properties(Software_laser PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Software_laser
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Software_laser)
endif()
