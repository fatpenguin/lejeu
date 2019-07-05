#ifndef __INCLUDE_TRANSFORM_HPP__
#define __INCLUDE_TRANSFORM_HPP__

#include <cstdint>


enum rotation : uint8_t {
	ROT_UP,
	ROT_RIGHT,
	ROT_DOWN,
	ROT_LEFT,
};

typedef struct {
	int32_t x;
	int32_t y;
} pos_t;

typedef struct {
	/* Position */
	pos_t pos;
	enum rotation rot;

	/* Movement */
	int velocity;
} comp_transform_t;


#endif /* __INCLUDE_TRANSFORM_HPP__ */
