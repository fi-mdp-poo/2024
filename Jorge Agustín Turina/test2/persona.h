#ifndef PERSONA_H
#define PERSONA_H

using namespace std;
#include <string>

class persona
{
    public:
        persona(string = "unkdown", int = 2422424);
        virtual ~persona();

        string Getnombre() const { return nombre; }
        void Setnombre(string val) { nombre = val; }

    protected:

    private:
        string nombre;
        int documento;
};

#endif // PERSONA_H
