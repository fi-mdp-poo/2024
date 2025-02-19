#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdint>

int main() {
    // Dimensiones de la matriz
    const int width = 800;
    const int height = 600;

    // Color en formato 0xAARRGGBB (Ejemplo: Rojo semi-transparente)
    uint32_t color = 0xFFFF0000; // Rojo opaco (FF de alpha, FF de red, 00 de green, 00 de blue)

    // Separar los componentes del color
    sf::Uint8 alpha = (color >> 24) & 0xFF;
    sf::Uint8 red = (color >> 16) & 0xFF;
    sf::Uint8 green = (color >> 8) & 0xFF;
    sf::Uint8 blue = color & 0xFF;

    // Crear la ventana
    sf::RenderWindow window(sf::VideoMode(width, height), "Matriz de Color");

    // Crear una textura y un sprite para mostrar los píxeles
    sf::Texture texture;
    texture.create(width, height);

    // Crear un vector para almacenar los píxeles en formato RGBA
    std::vector<sf::Uint8> pixels(width * height * 4); // Cada píxel tiene 4 bytes: R, G, B, A

    // Llenar el vector con el color deseado
    for (int i = 0; i < width * height; ++i) {
        pixels[i * 4] = red;     // R
        pixels[i * 4 + 1] = green; // G
        pixels[i * 4 + 2] = blue;  // B
        pixels[i * 4 + 3] = alpha; // A
    }

    // Asignar los píxeles a la textura
    texture.update(pixels.data());

    // Crear un sprite para dibujar la textura
    sf::Sprite sprite(texture);

    // Bucle principal
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Dibujar en la ventana
        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
