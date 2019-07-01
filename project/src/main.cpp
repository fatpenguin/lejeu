#include "main.hpp"

#include <iostream>
#include <unistd.h>
#include <chrono>

#define UPDATE_RATE   30 // Hz
#define MS_PER_UPDATE (1000 / UPDATE_RATE)


using namespace std;
using ms = chrono::milliseconds;
using get_time = chrono::steady_clock;

game_ctx_t game_ctx = {};

static int game_init(void)
{
	cout << "Initialization\n";

	game_ctx.entities = entities_init();
	game_ctx.controls = controls_init();
	game_ctx.renderer = renderer_init();

	return 0;
}

int main(void)
{
	auto last_ts = chrono::duration_cast<ms>(get_time::now().time_since_epoch()).count();
	int lag = 0;

	game_init();

	printf("Game update rate = %d (\"%d\")\n", UPDATE_RATE, MS_PER_UPDATE);
	printf("Players = %s (%d:%d)\n", game_ctx.entities->characters[0].name,
	                                 game_ctx.entities->transforms[0].pos.x,
	                                 game_ctx.entities->transforms[0].pos.y);
	cout << "Game start\n";

	for (;;) {
		/* Time handling */
		auto curr_ts = chrono::duration_cast<ms>(get_time::now().time_since_epoch()).count();
		lag += (curr_ts - last_ts);
		last_ts = curr_ts;

		/* Process input */
		controls_check_input(&game_ctx.renderer->window);

		while (lag >= MS_PER_UPDATE) {
			/* Update game state */

			lag -= MS_PER_UPDATE;
		}

		/* Render */
		render();
	}

	return 0;
}
