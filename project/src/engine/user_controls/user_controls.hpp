#ifndef __CONTROLS_HPP__
#define __CONTROLS_HPP__

#include <cstdint>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "entities.hpp"


// #define NB_KB_ACTIONS       sf::Keyboard::KeyCount
// #define NB_MOUSE_ACTIONS    6
// #define NB_JOYSTICK_ACTIONS 10

enum action_type: uint8_t {
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

enum input_type: uint8_t {
	IN_KEYBOARD,
	IN_MOUSE,
	IN_JOYSTICK,
	COUNT_INPUTTYPE
};

typedef struct {
	enum input_type type;
	uint8_t key;
} user_control_action_t;

typedef struct {
	/* List of possible player actions */
	user_control_action_t actions[COUNT_ACTION];
	enum action_type active[COUNT_ACTION];
	uint8_t active_cnt;
} controls_ctx_t;


controls_ctx_t* controls_init(void);
void controls_check_input(void);


#endif /* __CONTROLS_HPP__ */
