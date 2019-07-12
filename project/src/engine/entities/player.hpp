#ifndef __INCLUDE_PLAYER_HPP__
#define __INCLUDE_PLAYER_HPP__

#include <cstring>

#include "entities.hpp"
#include "user_controls.hpp"


class EntPlayer : public Entity {
	public:
		EntPlayer (entities_ctx_t *ent_ctx, char *name,
		           comp_transform_t *transform);
};

namespace player {
	void actions(entities_ctx_t *entities, controls_ctx_t *controls);
}

#endif /* __INCLUDE_PLAYER_HPP__ */
