#include "mainloop.hpp"
#include "player.hpp"

#define UPDATE_RATE   30 // Hz
#define MS_PER_UPDATE (1000 / UPDATE_RATE)


void update(game_ctx_t *game_ctx)
{
	player::actions(game_ctx->entities, game_ctx->controls);
}

void mainloop(game_ctx_t *game_ctx)
{
	printf("Game update rate = %d (\"%d\")\n", UPDATE_RATE, MS_PER_UPDATE);

	sf::Clock clock;
	int32_t lag = 0, curr_ts, last_ts = clock.getElapsedTime().asMilliseconds();

	for (;;) {
		/* Time handling */
		curr_ts = clock.getElapsedTime().asMilliseconds();
		lag += (curr_ts - last_ts);
		last_ts = curr_ts;

		/* Process input */
		if (game_ctx->renderer->window.hasFocus()) {
			controls_check_input();
		}

		while (lag >= MS_PER_UPDATE) {
			/* Update game state */
			update(game_ctx);
			lag -= MS_PER_UPDATE;

			/* DEBUG */
			printf(">>> %d\n", game_ctx->entities->nb_entities);
			int i;
			for(i=0; i<game_ctx->entities->nb_entities; i++) {
				printf("Ent %d: (%d:%d - %d)\n", i,
				       game_ctx->entities->transforms[i].pos.x,
				       game_ctx->entities->transforms[i].pos.y,
				       game_ctx->entities->transforms[i].rot);
			}
			/* DEBUG */
		}

		/* Render */
		render();
	}
}