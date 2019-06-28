#include "entities.hpp"

#include <cstring>

#include "player.hpp"


using namespace std;

entities_ctx_t entities_ctx = {};


entities_ctx_t* entities_init(void)
{
	Player player_one(&entities_ctx, (char *)"Link");
	return &entities_ctx;
}
