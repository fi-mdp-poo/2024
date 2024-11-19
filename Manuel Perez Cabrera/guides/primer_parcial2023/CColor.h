#ifndef CCOLOR_H
#define CCOLOR_H
#include <ostream>
#include <iomanip>

using namespace std;

class CColor
{
public:
    // Constructor que acepta un valor de color
    CColor(unsigned int color);

    ~CColor();
    // Métodos para obtener los valores de los componentes
    unsigned int getRed() const
    {
        return red;
    }
    unsigned int getGreen() const
    {
        return green;
    }
    unsigned int getBlue() const
    {
        return blue;
    }
    unsigned int getAlpha() const
    {
        return alpha;
    }

//    // Sobrecarga del operador << para mostrar el color
    friend ostream& operator<<(ostream& os, const CColor& color);


private:
    unsigned int red,
                 green,
                 blue,
                 alpha;
};

#endif // CCOLOR_H
