#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Action
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    JUMP,
    ATTACK,
    DEFEND,
    GRAB,
    COUNT_ACTION
};

struct Player
{
    char *name;
    short int life;
    short int stamina;
    short int posX;
    short int posY;
    short int vecX;
    short int vecY;

    void (*jump)(void);
};

void setPlayerName(Player *player, char *newName);
void moveDelta(Player *player, int deltaX, int deltaY);
void move(Player *player);
void attack(Player player);
void jump(Player player);

#endif
