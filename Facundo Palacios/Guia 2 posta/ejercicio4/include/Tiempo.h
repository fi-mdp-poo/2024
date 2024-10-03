#ifndef TIEMPO_H
#define TIEMPO_H


class Tiempo
{
    public:
        Tiempo();
        virtual ~Tiempo();

        int Gethora() { return hora; }
        void Sethora(int val) { hora = val; }
        int Getminutos() { return minutos; }
        void Setminutos(int val) { minutos = val; }
        int Getsegundos() { return segundos; }
        void Setsegundos(int val) { segundos = val; }

        void ingresarDatos();
        void muestra_fmt_estandard() const;
        void muestra_fmt_universal() const;

    protected:

    private:
        int hora;
        int minutos;
        int segundos;
};

#endif // TIEMPO_H
