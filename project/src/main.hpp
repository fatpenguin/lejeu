#ifndef __INCLUDE_MAIN_HPP__
#define __INCLUDE_MAIN_HPP__

#include "entities.hpp"
#include "user_controls.hpp"
#include "renderer.hpp"


typedef struct {
	/* Entities */
	entities_ctx_t *entities;
	controls_ctx_t *controls;
	renderer_ctx_t *renderer;

} game_ctx_t;

#endif /* __INCLUDE_MAIN_HPP__ */
