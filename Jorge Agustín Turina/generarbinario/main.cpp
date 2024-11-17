#include <iostream>
#include <fstream>
#include <string>

void textToBinary(const std::string& inputFile, const std::string& outputFile) {
    // Abrimos el archivo de texto en modo lectura
    std::ifstream textFile(inputFile, std::ios::in);
    if (!textFile.is_open()) {
        std::cerr << "Error al abrir el archivo de texto: " << inputFile << std::endl;
        return;
    }

    // Abrimos el archivo binario en modo escritura
    std::ofstream binFile(outputFile, std::ios::out | std::ios::binary);
    if (!binFile.is_open()) {
        std::cerr << "Error al abrir el archivo binario: " << outputFile << std::endl;
        return;
    }

    // Leemos el archivo de texto carácter por carácter y lo escribimos en el archivo binario
    char ch;
    while (textFile.get(ch)) {
        // Escribimos el carácter como byte en el archivo binario
        binFile.put(ch);
    }

    // Cerramos ambos archivos
    textFile.close();
    binFile.close();

    std::cout << "Conversión exitosa: " << inputFile << " a " << outputFile << std::endl;
}

int main() {
    std::string inputFile = "archivo.txt";    // Archivo de texto a convertir
    std::string outputFile = "archivo.bin";   // Archivo binario de salida

    textToBinary(inputFile, outputFile);

    return 0;
}
