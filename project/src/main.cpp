#include "main.hpp"

#include <iostream>
#include <unistd.h>

#include "player.hpp"


#define UPDATE_RATE   30 // Hz
#define MS_PER_UPDATE (1000 / UPDATE_RATE)


using namespace std;

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
	sf::Clock clock;
	int32_t lag = 0, curr_ts, last_ts = clock.getElapsedTime().asMilliseconds();

	game_init();

	printf("Game update rate = %d (\"%d\")\n", UPDATE_RATE, MS_PER_UPDATE);
	printf("Players = %s (%d:%d)\n", game_ctx.entities->characters[0].name,
	                                 game_ctx.entities->transforms[0].pos.x,
	                                 game_ctx.entities->transforms[0].pos.y);
	cout << "Game start\n";

	for (;;) {
		/* Time handling */
		curr_ts = clock.getElapsedTime().asMilliseconds();
		lag += (curr_ts - last_ts);
		last_ts = curr_ts;

		/* Process input */
		if (game_ctx.renderer->window.hasFocus()) {
			controls_check_input();
		}

		while (lag >= MS_PER_UPDATE) {
			/* Update game state */
			int i;
			for(i=0; i<game_ctx.controls->active_cnt; i++) {
				player::action(game_ctx.entities,
				               game_ctx.controls->active[i]);
			}

			/* DEBUG */
			printf(">>> %d\n", game_ctx.entities->nb_entities);
			for(i=0; i<game_ctx.entities->nb_entities; i++) {
				printf("Ent %d: (%d:%d - %d)\n", i,
				       game_ctx.entities->transforms[i].pos.x,
				       game_ctx.entities->transforms[i].pos.y,
				       game_ctx.entities->transforms[i].rot);
			}

			lag -= MS_PER_UPDATE;
		}

		/* Render */
		render();
	}

	return 0;
}
