#include "player.hpp"

void setPlayerName(Player *player, char *newName)
{
    player->name = (char *)malloc(strlen(newName));
    strcpy(player->name, newName);
}

void moveDelta(Player *player, int deltaX, int deltaY)
{
    player->posX += deltaX;
    player->posY += deltaY;
}

void move(Player *player)
{
    player->posX += player->vecX;
    player->posY += player->vecY;
}

void attack(Player player)
{
    printf("%s is attacking\n", player.name);
}

void jump(Player player)
// void jump(void)
{
    printf("%s is jumping\n", player.name);
}
