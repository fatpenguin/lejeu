#ifndef __INCLUDE_PLAYER_HPP__
#define __INCLUDE_PLAYER_HPP__

#include "entities.hpp"
#include <cstring>


class Player : public Entity {
	public:
		Player (entities_ctx_t *ent_ctx, char *name, pos_t *pos);
};


Player::Player (entities_ctx_t *ent_ctx, char *name, pos_t *pos) {
	int id = ent_ctx->nb_entities;

	strcpy(ent_ctx->characters[id].name, name);
	memcpy(&(ent_ctx->transforms[id].pos), pos, sizeof(*pos));

	Entity::id = id;
	ent_ctx->nb_entities++;
}

#endif /* __INCLUDE_PLAYER_HPP__ */
