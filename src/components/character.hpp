#ifndef __INCLUDE_CHARACTER_HPP__
#define __INCLUDE_CHARACTER_HPP__

#define CHAR_NAME_MAX_SIZE 15
#define CHAR_LIFE_IMMORTAL -1


enum char_state
{
	NORMAL,
	ASLEEP,
	STUNNED,
	BURNING,
	FROZEN,
	POISONED,
};


typedef struct {
	char name[CHAR_NAME_MAX_SIZE + 1];

	int life;
	int state;
	int stamina;
} comp_character_t;


#endif /* __INCLUDE_CHARACTER_HPP__ */
