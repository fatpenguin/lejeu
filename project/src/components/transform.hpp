#ifndef __INCLUDE_TRANSFORM_HPP__
#define __INCLUDE_TRANSFORM_HPP__

#include <cstdint>


enum rotation : uint8_t {
	UP,
	RIGHT,
	DOWN,
	LEFT,
};

typedef struct {
	uint32_t x;
	uint32_t y;
} pos_t;

typedef struct {
	/* Position */
	pos_t pos;
	enum rotation rot;

	/* Movement */
	int velocity;
} comp_transform_t;


#endif /* __INCLUDE_TRANSFORM_HPP__ */
