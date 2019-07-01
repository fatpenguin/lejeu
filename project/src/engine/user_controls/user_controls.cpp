#include "user_controls.hpp"
#include <iostream>


using namespace std;

controls_ctx_t controls_ctx = {};

//TODO: Find old key binding and delete it before assigning a new one
static bool update_action_kb(int key, enum action_type action)
{
	if (key >= NB_KB_ACTIONS) {
		cout << "[CONTROLS] Key event id %d not valid" << key << "\n";
		return -1;
	}

	controls_ctx.key_action[key] = action;

	return 0;
}

static bool update_action_mouse(int key, enum action_type action)
{
	if (key >= NB_MOUSE_ACTIONS) {
		cout << "[CONTROLS] Mouse event id %d not valid" << key << "\n";
		return -1;
	}

	controls_ctx.mouse_action[key] = action;

	return 0;
}

static bool update_action_joystick(int key, enum action_type action)
{
	if (key >= NB_JOYSTICK_ACTIONS) {
		cout << "[CONTROLS] Joystick id %d not valid" << key << "\n";
		return -1;
	}

	controls_ctx.joystick_action[key] = action;

	return 0;
}

static bool update_action(int key, enum action_type action, enum input_type type)
{
	bool ret = 0;

	switch (type) {
	case IN_KEYBOARD:
		ret = update_action_kb(key, action);
		break;
	case IN_MOUSE:
		ret = update_action_mouse(key, action);
		break;
	case IN_JOYSTICK:
		ret = update_action_joystick(key, action);
		break;
	default:
		cout << "[CONTROLS] Input type not recognized\n";
		return -1;
	}

	return ret;
}

controls_ctx_t* controls_init(void)
{
	if (update_action(sf::Keyboard::Z, ACT_UP, IN_KEYBOARD) ||
	    update_action(sf::Keyboard::Q, ACT_LEFT, IN_KEYBOARD) ||
	    update_action(sf::Keyboard::D, ACT_RIGHT, IN_KEYBOARD) ||
	    update_action(sf::Keyboard::S, ACT_DOWN, IN_KEYBOARD) ||
	    update_action(sf::Keyboard::Space, ACT_JUMP, IN_KEYBOARD))
	{
		goto err;
	}
	return &controls_ctx;

err:
	cout << "[CONTROLS] Could not initialize\n";
	return NULL;
}

void controls_check_input(sf::RenderWindow *window)
{
	static sf::Event event;

	// TODO: maybe loop over poll to empty queue ?
	window->pollEvent(event);

	if (event.type == sf::Event::KeyPressed) {
		switch (controls_ctx.key_action[event.key.code]) {
		case ACT_UP:
			printf("UP requested\n");
			break;
		case ACT_LEFT:
			printf("LEFT requested\n");
			break;
		case ACT_RIGHT:
			printf("RIGHT requested\n");
			break;
		case ACT_DOWN:
			printf("DOWN requested\n");
			break;
		case ACT_JUMP:
			printf("JUMP requested\n");
			break;
		case ACT_NONE:
			printf("no action needed\n");
		default:
			printf("[CONTROLS] Action %d unknown\n",
			       controls_ctx.key_action[event.key.code]);
			break;
		}
	}
}
