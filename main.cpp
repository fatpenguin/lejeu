#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    window.setFramerateLimit(60);

    // Load textures
    sf::Texture texture;
    texture.loadFromFile("assets/image1.jpeg");

    sf::Sprite sprite(texture);
    sf::Event event;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                case (sf::Keyboard::Up):
                    sprite.move(0, -5.f);
                    break;
                case (sf::Keyboard::Down):
                    sprite.move(0, 5.f);
                    break;
                case (sf::Keyboard::Left):
                    sprite.move(-5.f, 0);
                    break;
                case (sf::Keyboard::Right):
                    sprite.move(5.f,0);
                    break;
                default:
                    break;
                }
            }
        }
        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}