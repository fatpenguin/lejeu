#ifndef __INCLUDE_ENTITIES_HPP__
#define __INCLUDE_ENTITIES_HPP__

#include "transform.hpp"
#include "model.hpp"
#include "character.hpp"

#define ENTITIES_MAX_SIZE 50


typedef struct {
	/* Components */
	comp_transform_t transforms[ENTITIES_MAX_SIZE];
	comp_model_t     models[ENTITIES_MAX_SIZE];
	comp_character_t characters[ENTITIES_MAX_SIZE];

	int nb_entities;
} entities_ctx_t;

class Entity {
	public:
		int id;
};


entities_ctx_t* entities_init(void);


#endif /* __INCLUDE_ENTITIES_HPP__ */