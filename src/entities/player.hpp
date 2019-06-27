#ifndef __INCLUDE_PLAYER_HPP__
#define __INCLUDE_PLAYER_HPP__

#include "entities.hpp"
#include "string.h"


class Player : public Entity {
	comp_transform_t *transform;
	comp_model_t     *model;
	comp_character_t *character;
	public:
		Player (entities_ctx_t *ent_ctx, char *name);
};


Player::Player (entities_ctx_t *ent_ctx, char *name) {
	transform = &(ent_ctx->transforms[ent_ctx->nb_entities]);
	model = &(ent_ctx->models[ent_ctx->nb_entities]);
	character = &(ent_ctx->characters[ent_ctx->nb_entities]);

	strcpy(character->name, name);

	Entity::id = ++ent_ctx->nb_entities;
}

#endif /* __INCLUDE_PLAYER_HPP__ */
