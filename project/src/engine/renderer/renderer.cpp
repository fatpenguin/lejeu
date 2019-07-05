#include "renderer.hpp"
#include <iostream>


using namespace std;

renderer_ctx_t renderer_ctx = {};

renderer_ctx_t* renderer_init(void)
{
	renderer_ctx.window.create(sf::VideoMode(800, 600), "My window");
	renderer_ctx.window.setFramerateLimit(60);

	return &renderer_ctx;
}

int render(void)
{
	return 0;
}
