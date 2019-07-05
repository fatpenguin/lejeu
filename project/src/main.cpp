#include <iostream>
#include <unistd.h>

#include "mainloop.hpp"


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
	game_init();

	printf("Players = %s (%d:%d)\n", game_ctx.entities->characters[0].name,
	                                 game_ctx.entities->transforms[0].pos.x,
	                                 game_ctx.entities->transforms[0].pos.y);
	cout << "Game start\n";

	mainloop(&game_ctx);

	return 0;
}
