#ifndef CCOLOR_H
#define CCOLOR_H
#include <iostream>

using namespace std;

class CColor
{
public:
    CColor(int Color = 2);
    //virtual ~CColor();

    int GetRed()
    {
        return Red;
    }
    void SetRed(int val)
    {
        Red = val;
        int aux = GetColor();
        val = val<< 16;
        aux = aux & 0xFF00FFFF;
        aux = aux | val ;

        SetColor(aux);

    }
    int GetGreen()
    {
        return Green;
    }
    void SetGreen(int val)
    {
        Green = val;
        int aux = GetColor();
        aux &= 0xFFFF00FF;          // Limpiar el tercer byte (Green)
        aux |= (val << 8);          // Establecer el nuevo valor para Green
        SetColor(aux);

    }
    int GetBlue()
    {
        return Blue;
    }
    void SetBlue(int val)
    {
        Blue = val;
        int aux = GetColor();
        aux &= 0xFFFFFF00;          // Limpiar el cuarto byte (Blue)
        aux |= val;                 // Establecer el nuevo valor para Blue
        SetColor(aux);

    }
    int GetAlpha()
    {
        return Alpha;
    }
    void SetAlpha(int val)
    {
        Alpha = val;
    }
    int GetColor()
    {
        return Color;
    }
    void SetColor(int val)
    {
        Color = val;
    }

    friend ostream& operator << (ostream& os, CColor& t);
protected:

private:


    int Color;
    int Red;
    int Green;
    int Blue;
    int Alpha;
};

#endif // CCOLOR_H
