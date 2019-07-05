#include "user_controls.hpp"
#include <iostream>


using namespace std;
using sfkb = sf::Keyboard;

controls_ctx_t controls_ctx = {};

static bool update_action(enum action_type action, int key,
                          enum input_type type)
{
	if (action >= COUNT_ACTION) {
		return -1;
	}

	if (key >= sfkb::KeyCount) {
		return -1;
	}

	if (type >= COUNT_INPUTTYPE) {
		return -1;
	}

	controls_ctx.actions[action].type = type;
	controls_ctx.actions[action].key = key;

	return 0;
}

controls_ctx_t* controls_init(void)
{
	if (update_action(ACT_UP, sfkb::Z, IN_KEYBOARD) ||
	    update_action(ACT_LEFT, sfkb::Q, IN_KEYBOARD) ||
	    update_action(ACT_RIGHT, sfkb::D, IN_KEYBOARD) ||
	    update_action(ACT_DOWN, sfkb::S, IN_KEYBOARD) ||
	    update_action(ACT_JUMP, sfkb::Space, IN_KEYBOARD))
	{
		goto err;
	}
	return &controls_ctx;

err:
	cout << "[CONTROLS] Could not initialize\n";
	return NULL;
}

void controls_check_input(void)
{
	user_control_action_t *acts = controls_ctx.actions;

	controls_ctx.active_cnt = 0;
	for(int i=0; i<COUNT_ACTION; i++) {
		if (acts[i].type == IN_KEYBOARD &&
		    sfkb::isKeyPressed((sfkb::Key)acts[i].key))
		{
			controls_ctx.active[controls_ctx.active_cnt] = (enum action_type)i;
		}
	}
}
