#ifndef __RENDERER_HPP__
#define __RENDERER_HPP__

#include <SFML/Graphics.hpp>


typedef struct {
	sf::RenderWindow window;
} renderer_ctx_t;


renderer_ctx_t* renderer_init(void);


#endif /* __RENDERER_HPP__ */
