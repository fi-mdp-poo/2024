#ifndef CCOLOR_H
#define CCOLOR_H

#include <iostream>
#include <iomanip>
#include <cstdint>
#include <string>
#include <sstream>
using namespace std;

class CColor
{
public:
    // Enumeración para seleccionar un componente del color
    enum Component { Red = 0, Green = 1, Blue = 2, Alpha = 3 };

private:
    // Unión para acceder al color como un valor completo o como bytes individuales
    union
    {
        uint32_t value;         // Color completo (0xAARRGGBB)
        uint8_t byte[4];        // Bytes individuales: byte[0]=Blue, byte[1]=Green, ...
    } color;

public:
    CColor();
    CColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255);

    void setRed(uint8_t value);
    uint8_t getRed() const;
    void setBlue(uint8_t value);
    uint8_t getBlue() const;
    void setAlpha(uint8_t value);
    uint8_t getAlpha() const;

    void setGreen(uint8_t value);
    uint8_t getGreen() const;


    // Método para obtener un componente usando la enumeración
    uint8_t getComponent(Component component) const;

    void setColor(uint32_t value);
    uint32_t getColor() const;

    CColor& operator=(const CColor& other);

    // Sobrecarga del operador << para imprimir el color

private:

    // Método para establecer un componente usando la enumeración
    void setComponent(Component component, uint8_t value)
    {
        color.byte[component] = value;
    }
};
ostream& operator<<(ostream& os, const CColor& color_a_imprimir);


#endif

