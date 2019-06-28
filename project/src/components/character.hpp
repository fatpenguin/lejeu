#ifndef __INCLUDE_CHARACTER_HPP__
#define __INCLUDE_CHARACTER_HPP__

#include <cstdint>


#define CHAR_NAME_MAX_SIZE 15
#define CHAR_LIFE_IMMORTAL -1


enum char_state : uint8_t {
	NORMAL,
	ASLEEP,
	STUNNED,
	BURNING,
	FROZEN,
	POISONED,
};


typedef struct {
	char name[CHAR_NAME_MAX_SIZE + 1];

	uint16_t life;
	uint16_t stamina;
	enum char_state state;
} comp_character_t;


#endif /* __INCLUDE_CHARACTER_HPP__ */
