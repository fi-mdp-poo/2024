#include "RegistroManager/RegistroManager.h"
#include "Persona/Persona.h"

int main() {
    try {
        RegistroManager<Persona> registroPersonas;
        registroPersonas.nuevoArchivo("personas.dat");

        const Persona juan("Juan Diaz", "Av. Corrientes 344", "2236112233");
        registroPersonas.agregarRegistro(juan);

        const Persona ceci("Cecilia Crocce", "El Chimango 234", "2234556677");
        registroPersonas.agregarRegistro(ceci);

        const Persona marcela("Marcela Rio", "El Chimango 234", "2234423839");
        registroPersonas.agregarRegistro(marcela);

        const Persona corina("Corina Crocce", "Belgrano 118", "22345543289");
        registroPersonas.agregarRegistro(corina);

        const Persona julieta("Julieta Cardinal", "Av. Corriente 222", "11343578953");
        registroPersonas.agregarRegistro(julieta);

        // ** Consultar si es mejor devolver una referencia, y el caso de error contemplarlo con una excepción
        Persona buscada = registroPersonas.buscarRegistro("C");
        cout << buscada << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
