#ifndef __INCLUDE_MAINLOOP_HPP__
#define __INCLUDE_MAINLOOP_HPP__

#include "entities.hpp"
#include "user_controls.hpp"
#include "renderer.hpp"


typedef struct {
	/* Entities */
	entities_ctx_t *entities;
	controls_ctx_t *controls;
	renderer_ctx_t *renderer;

} game_ctx_t;

void mainloop(game_ctx_t *game_ctx);

#endif /* __INCLUDE_MAINLOOP_HPP__ */
