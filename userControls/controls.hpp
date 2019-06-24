#ifndef CONTROLS_H
#define CONTROLS_H

#include <stdio.h>
#include "player.hpp"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

/**
 * Store here all possible user controls
 */

enum InputType
{
    KeyboardInput,
    MouseInput,
    JoystickInput,
    COUNT_INPUTTYPE
};

struct Keys
{
    InputType myInputType;
    sf::Event::EventType myEventType;
    sf::Keyboard::Key myKeyCode;
    sf::Mouse::Button myMouseButton;
};

struct Controls
{
    Keys action[COUNT_ACTION];
};

// Executes the action requested by the event and returns the action type executed
Action controlEvent(Controls control, sf::Event event);

//Check which event has been triggered
bool testEvent(Keys key, sf::Event event);

// Changes the key binding for an action
// TODO: CHECK THAT ONE KEY IS NOT SET FOR ANOTHER ACTION
// TODO: VERIFY SHAPE OF INPUT BEFORE REGISTERING IT
bool updateActionKey(Controls *control, Action actionType, sf::Event::EventType, sf::Keyboard::Key keyCode);
bool updateActionButton(Controls *control, Action actionType, sf::Event::EventType, sf::Mouse::Button button);

// Initation function
Controls instantiateControls(void);
#endif
