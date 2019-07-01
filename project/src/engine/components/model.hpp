#ifndef __INCLUDE_MODEL_HPP__
#define __INCLUDE_MODEL_HPP__

#include <cstdint>


typedef struct {
	int **sprite;
	uint16_t size_x;
	uint16_t size_y;

	uint8_t color;

	uint8_t collides;
} comp_model_t;


#endif /* __INCLUDE_MODEL_HPP__ */
