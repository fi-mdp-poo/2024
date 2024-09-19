#ifndef PRUEBA_H_INCLUDED
#define PRUEBA_H_INCLUDED

class prueba
{
    private:
        int m_Valor;
        static int m_Counter;
    public:
        prueba(int);
        prueba();
        prueba(prueba &);
        ~prueba();
        int getValor() { return m_Valor; }
        void setValor(int val) { m_Valor = val; }
        static int getCounter() { return m_Counter; }
        prueba operator= (prueba &);
};

#endif // PRUEBA_H
