#include "entities.hpp"

#include <cstring>

#include "player.hpp"


using namespace std;

entities_ctx_t entities_ctx = {};


entities_ctx_t* entities_init(void)
{
	pos_t player_pos = {
		.x = 50,
		.y = 50,
	};

	Player player_one(&entities_ctx, (char *)"Link", &player_pos);

	return &entities_ctx;
}
