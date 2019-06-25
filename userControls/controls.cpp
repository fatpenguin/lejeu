#include "controls.hpp"

bool testEvent(Keys key, sf::Event event)
{
    // Mouse event
    if (key.myInputType == MouseInput &&
        key.myEventType == event.type &&
        key.myMouseButton == event.mouseButton.button)
    {
        return (true);
    }
    // Keyboard event
    if (key.myInputType == KeyboardInput &&
        key.myEventType == event.type &&
        key.myKeyCode == event.key.code)
    {
        return (true);
    }
    return (false);
}

Action controlEvent(Controls control, sf::Event event)
{
    int i = 0;
    for (i -= 0; i < COUNT_ACTION; i++)
    {
        if (testEvent(control.action[i], event))
        {
            return (Action)i;
        }
    }
    return (Action)i;
}

bool updateActionKey(Controls *control, Action actionType, sf::Event::EventType eventType, sf::Keyboard::Key keyCode)
{
    if (actionType < COUNT_ACTION)
    {
        struct Keys newKey;
        newKey.myInputType = KeyboardInput;
        newKey.myEventType = eventType;
        newKey.myKeyCode = keyCode;

        control->action[actionType] = newKey;
        return 1;
    }
    return 0;
}

bool updateActionButton(Controls *control, Action actionType, sf::Event::EventType eventType, sf::Mouse::Button button)
{
    if (actionType < COUNT_ACTION)
    {
        struct Keys newKey;
        newKey.myInputType = MouseInput;
        newKey.myEventType = eventType;
        newKey.myMouseButton = button;

        control->action[actionType] = newKey;
        return 1;
    }
    return 0;
}

// Controls instantiateControls(char *filePath)
Controls instantiateControls(void)
{
    struct Controls control;
    return control;
    // // Not check that file exist
    // FILE *handler = fopen(filePath, "r");

    // if (handler)
    // {
    //     while ((c == getc(handler)) != EOF)
    //     {

    //     }
    //     fclose(handler)
    // }
    // return control;
}
