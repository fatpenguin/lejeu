#include "player.hpp"

#define MAP_MAX_X 500
#define MAP_MAX_Y 500


EntPlayer::EntPlayer (entities_ctx_t *ent_ctx, char *name, comp_transform_t *transform) {
	int id = ent_ctx->nb_entities;

	strcpy(ent_ctx->characters[id].name, name);
	memcpy(&(ent_ctx->transforms[id]), transform, sizeof(*transform));

	Entity::id = id;
	ent_ctx->nb_entities++;
}

static void move(entities_ctx_t *entities, enum action_type action)
{
	int player_id = entities->player_id;
	comp_transform_t *trans = entities->transforms;
	comp_transform_t *player_trans = &entities->transforms[player_id];
	pos_t new_pos = {};
	int i;

	/* Estimate new pos */
	switch (action) {
		case ACT_UP:
			printf("UP\n");
			player_trans->rot = ROT_UP;
			new_pos.y -= player_trans->velocity;
			break;
		case ACT_DOWN:
			printf("DOWN\n");
			player_trans->rot = ROT_DOWN;
			new_pos.y += player_trans->velocity;
			break;
		case ACT_LEFT:
			printf("LEFT\n");
			player_trans->rot = ROT_LEFT;
			new_pos.x -= player_trans->velocity;
			break;
		case ACT_RIGHT:
			printf("RIGHT\n");
			player_trans->rot = ROT_RIGHT;
			new_pos.x += player_trans->velocity;
			break;
		default:
			return;
	}

	/* Check new pos */
	if (new_pos.x < 0 || new_pos.y < 0 ||
	    new_pos.x >= MAP_MAX_X || new_pos.y >= MAP_MAX_Y)
	{
		printf("OUT\n");
		return;
	}
	for (i=0; i<entities->nb_entities; i++) {
		if (i == player_id) {
			continue;
		}
		if (trans[i].pos.x == new_pos.x && trans[i].pos.y == new_pos.y
		    && entities->models[i].collides)
		{
			printf("COLLISION\n");
			return;
		}
	}

	/* Assign new pos */
	player_trans->pos.x = new_pos.x;
	player_trans->pos.y = new_pos.y;
}

void player::action(entities_ctx_t *entities, enum action_type action)
{
	switch (action) {
		case ACT_UP:
		case ACT_DOWN:
		case ACT_LEFT:
		case ACT_RIGHT:
			move(entities, action);
			break;
		default:
			break;
	}
}
