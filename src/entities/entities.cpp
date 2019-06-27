#include "entities.hpp"
#include "player.hpp"


entities_ctx_t entities_ctx = {0};


entities_ctx_t* entities_init(void)
{
	Player player_one(&entities_ctx, "Link");
	return &entities_ctx;
}
