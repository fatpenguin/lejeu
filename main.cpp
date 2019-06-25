#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main()
{
    // Load textures
    sf::Texture texture;
    if(!texture.loadFromFile("assets/sprites/image1.jpeg"))
    {
        printf("Not able to load file assets/image1.jpeg\n");
        return -1;
    }
    sf::Sprite sprite(texture);

    // Load sound
    sf::SoundBuffer buffer;
    if(!buffer.loadFromFile("assets/sounds/music1.wav"))
    {
        printf("Not able to load file assets/sounds/music1.wav\n");
        return -1;
    }

    // Create main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    window.setFramerateLimit(60);

    // Declare event here
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