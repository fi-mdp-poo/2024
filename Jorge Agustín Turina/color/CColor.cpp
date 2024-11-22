#include "CColor.h"

// Constructor por defecto: color negro con alpha completo
CColor::CColor()
{
    color.value = 0xFF000000;
}

// Constructor con valores iniciales
CColor::CColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
    setComponent(Red, red);
    setComponent(Green, green);
    setComponent(Blue, blue);
    setComponent(Alpha, alpha);
}


void CColor::setRed(uint8_t value)
{
    setComponent(Red, value);
}

uint8_t CColor::getRed() const
{
    return getComponent(Red);
}

void CColor::setBlue(uint8_t value)
{
    setComponent(Blue, value);
}

uint8_t CColor::getBlue() const
{
    return getComponent(Blue);
}

void CColor::setAlpha(uint8_t value)
{
    setComponent(Alpha, value);
}

uint8_t CColor::getAlpha() const
{
    return getComponent(Alpha);
}

void CColor::setGreen(uint8_t value)
{
    setComponent(Green, value);
}

uint8_t CColor::getGreen() const
{
    return getComponent(Green);
}

// Método para establecer el color completo
void CColor::setColor(uint32_t value)
{
    color.value = value;
}

// Método para obtener el color completo
uint32_t CColor::getColor() const
{
    return color.value;
}



// Sobrecarga del operador = para asignar un color a otro
CColor& CColor::operator=(const CColor& other)
{
    if (this != &other)
    {
        color.value = other.color.value;  // Copiar el valor completo
    }
    return *this;
}


ostream& operator<<(ostream& os, const CColor& color_a_imprimir)
{
    uint8_t rojo = color_a_imprimir.getRed();
    uint8_t verde = color_a_imprimir.getGreen();
    uint8_t azul = color_a_imprimir.getBlue();
    uint8_t transparencia = color_a_imprimir.getAlpha();

    os << "Color: 0x" << hex << uppercase << setw(8)
       << setfill('0') << color_a_imprimir.getColor()

       << " (red="   << dec << setw(3) << (int)rojo  << hex << "(" << setw(2) << (int)rojo  << ")"
       << ", green=" << dec << setw(3) << (int)verde << hex << "(" << setw(2) << (int)verde << ")"
       << ", blue="  << dec << setw(3) << (int)azul  << hex << "(" << setw(2) << (int)azul  << ")"
       <<", alpha="  << dec << setw(3) << (int)transparencia << hex << "(" << setw(2) << (int)transparencia << ")"
       << ")" << dec;
    return os;
}


// Método para obtener un componente usando la enumeración
uint8_t CColor::getComponent(Component component) const
{
    return color.byte[component];
}
