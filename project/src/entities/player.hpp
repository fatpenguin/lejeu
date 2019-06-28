#ifndef __INCLUDE_PLAYER_HPP__
#define __INCLUDE_PLAYER_HPP__

#include "entities.hpp"
#include "string.h"


class Player : public Entity {
	public:
		Player (entities_ctx_t *ent_ctx, char *name);
};


Player::Player (entities_ctx_t *ent_ctx, char *name) {
	strcpy(ent_ctx->characters[ent_ctx->nb_entities].name, name);

	Entity::id = ++ent_ctx->nb_entities;
}

#endif /* __INCLUDE_PLAYER_HPP__ */
