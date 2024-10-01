#ifndef MESA_H
#define MESA_H


class mesa
{
    public:
        mesa();
        mesa(float altura);
        virtual ~mesa();

        float Getaltura() { return altura; }
        void Setaltura(float val) { altura = val; }

    protected:

    private:
        float altura;
};

#endif // MESA_H
