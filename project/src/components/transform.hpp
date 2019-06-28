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
	/* Position */
	uint32_t x;
	uint32_t y;
	enum rotation rot;

	/* Movement */
	int velocity;
} comp_transform_t;


#endif /* __INCLUDE_TRANSFORM_HPP__ */
