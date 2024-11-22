#include "ManejadorColor.h"
#include "ManejadorArchivos.h"

int main()
{
    CColor color(255, 127, 64, 128);
    std::cout << color << std::endl;

    color.setRed(10);
    color.setBlue(190);
    color.setAlpha(0);
    color.setGreen(24);

    std::cout << color << std::endl;

    color.setColor(0x12345678);
    std::cout << color << std::endl;

    ManejadorColor colores = ManejadorColor(color);
    colores.getColor().setRed(99);

    std::cout <<colores.getColor()<< std::endl;

    ManejadorArchivos* archivero = new ManejadorArchivos("archivo.txt", "escritura", "texto");
    fstream& salida = archivero->getFlujoTexto();
    colores.setColor(0xffffffff);
    salida << colores.getColor() << endl;
    archivero->escribir_texto("hola");
    colores.getColor().setRed(99);
    archivero->escribir_texto(colores.getColor());
    colores.getColor().setRed(100);
    archivero->escribir_texto(colores.getColor());
    colores.getColor().setRed(101);
    archivero->escribir_texto(colores.getColor());
    colores.getColor().setRed(102);
    archivero->escribir_texto(colores.getColor());

    delete archivero;
    //archivero->leer_texto();
    archivero = new ManejadorArchivos("servicios.bin","lectura", "binario");

    int cant = archivero->leer_binario<int>();
    cout << "la long de char es " << sizeof(char) << "y la de unsigned es" << sizeof(unsigned char) << endl;
    cout << "cantidad de trabajos "<< cant;
    char a = 'a';
    cant = archivero->leer_binario<char>();
    //cant = archivero->leer_binario<unsigned char>();

    cout << hex << "tipo de trabajo "<< cant;
    //cant = archivero->leer_binario<unsigned char>();


    cant = archivero->leer_binario<int>();
    cout << dec << "long "<< cant;


    delete archivero;
    archivero = new ManejadorArchivos("ALGOO.bin","escritura", "binario");

    int cc = 800;
    archivero->escribir_binario(cc);
    archivero->escribir_binario(colores.getColor());
    archivero->escribir_binario("el color rojo es:");

    archivero->escribir_binario(colores.getColor().getRed());
    archivero->escribir_binario(colores.getColor().getRed());


    cout << endl<< "lo que devuelve get color es , que escribo en binario "<< colores.getColor() <<endl;

    // Obtener el flujo binario directamente y escribir
    fstream& sal = archivero->getFlujoBinario();
    int kl = 25;

    for (int i=0 ; i<400000 ; i++)
    {
        sal.write(reinterpret_cast<const char*>(&kl), sizeof(kl));
        archivero->escribir_binario(colores.getColor().getRed());
    }

    delete archivero;
    cout << endl;
    archivero = new ManejadorArchivos("archivo.txt","lectura", "texto");
    cout << archivero->leer_texto() << endl;


    delete archivero;
    cout << endl;
    archivero = new ManejadorArchivos("archivo.txt","lectura", "texto");
    cout << archivero->leer_texto() << endl;


    return 0;
}
