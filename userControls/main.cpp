#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "controls.hpp"
#include "player.hpp"

int main()
{
    printf("Hello world\n");

    Controls control1 = instantiateControls();
    Controls *controlPtr = &control1;
    bool status = updateActionKey(controlPtr, UP, sf::Event::KeyPressed, sf::Keyboard::Up);
    status = updateActionKey(controlPtr, LEFT, sf::Event::KeyPressed, sf::Keyboard::Left);
    status = updateActionKey(controlPtr, RIGHT, sf::Event::KeyPressed, sf::Keyboard::Right);
    status = updateActionKey(controlPtr, DOWN, sf::Event::KeyPressed, sf::Keyboard::Down);
    status = updateActionKey(controlPtr, JUMP, sf::Event::KeyPressed, sf::Keyboard::Space);

    // Create main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    window.setFramerateLimit(60);

    // Declare event here
    sf::Event event;

    Player player;
    setPlayerName(&player, "salut les connards");

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                printf("Salut\n");
                window.close();
            }
            // else if (event.type == sf::Event::KeyPressed || sf::Event::MouseButtonPressed)
            else if (event.type == sf::Event::KeyPressed)
            {
                // printf("Event: %i\n",event.type);
                // fflush( stdout );
                switch (controlEvent(control1, event))
                {
                case UP:
                    printf("UP requested\n");
                    fflush(stdout);
                    break;
                case LEFT:
                    printf("LEFT requested\n");
                    fflush(stdout);
                    break;
                case RIGHT:
                    printf("RIGHT requested\n");
                    fflush(stdout);
                    break;
                case DOWN:
                    printf("DOWN requested\n");
                    fflush(stdout);
                    break;
                case JUMP:
                    printf("JUMP requested\n");
                    // jump(player);
                    player.jump();
                    fflush(stdout);
                    break;

                default:
                    printf("Action not found\n");
                    fflush(stdout);
                    break;
                }
            }
        }
        window.clear();
        window.display();
    }
    return 1;
}
