#ifndef __CONTROLS_HPP__
#define __CONTROLS_HPP__

#include <cstdint>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "entities.hpp"


#define NB_KB_ACTIONS       sf::Keyboard::KeyCount
#define NB_MOUSE_ACTIONS    6
#define NB_JOYSTICK_ACTIONS 10

enum action_type: uint8_t {
	ACT_NONE,
	ACT_UP,
	ACT_DOWN,
	ACT_LEFT,
	ACT_RIGHT,
	ACT_JUMP,
	ACT_ATTACK,
	ACT_DEFEND,
	ACT_GRAB,
	COUNT_ACTION
};

enum input_type {
	IN_KEYBOARD,
	IN_MOUSE,
	IN_JOYSTICK,
	COUNT_INPUTTYPE
};

typedef struct {
	/* For KeyPressed event type */
	uint8_t key_action[NB_KB_ACTIONS];

	/* For mouse events */
	uint8_t mouse_action[NB_MOUSE_ACTIONS];

	/* For joystick events */
	uint8_t joystick_action[NB_JOYSTICK_ACTIONS];

	// keys_t actions[COUNT_ACTION];
} controls_ctx_t;


controls_ctx_t* controls_init(void);
void controls_check_input(sf::RenderWindow *window, entities_ctx_t *entities);


#endif /* __CONTROLS_HPP__ */
