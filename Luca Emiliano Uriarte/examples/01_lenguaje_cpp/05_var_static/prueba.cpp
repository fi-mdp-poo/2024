#include "prueba.h"

prueba::prueba(int val)
{
    m_Valor = val;
    m_Counter++;
}

prueba::~prueba()
{
    m_Counter--;
}

prueba::prueba()
{
    m_Counter++;
}

prueba prueba::operator= (prueba& obj)
{
    m_Counter++;
    m_Valor = obj.m_Valor;

    return obj;
}

prueba::prueba(prueba &obj)
{
    m_Valor = obj.m_Valor;
    m_Counter++;
}
