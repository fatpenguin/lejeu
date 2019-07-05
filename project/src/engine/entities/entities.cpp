#include "entities.hpp"

#include <cstring>

#include "player.hpp"


using namespace std;

entities_ctx_t entities_ctx = {};


entities_ctx_t* entities_init(void)
{
	comp_transform_t transform = {
		.pos = {
			.x = 200,
			.y = 150,
		},
		.rot = ROT_UP,
		.velocity = 10,
	};

	EntPlayer player_one(&entities_ctx, (char *)"Link", &transform);
	entities_ctx.player_id = player_one.id;

	return &entities_ctx;
}
