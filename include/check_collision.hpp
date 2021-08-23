#ifndef CHECK_COLLISION
#define CHECK_COLLISION

#include "entity.hpp"

bool CheckCollideFalling(bool* falling, Entity player, Entity* platforms, int num_platforms, int* a);

bool CheckCollideBottom(bool* collide, Entity player, Entity* platforms, int num_platforms, int* a);

bool CheckCollideTop(bool* collide, Entity player, Entity* platforms, int num_platforms, int* a);

bool CheckCollideLeft(bool* collide, Entity player, Entity* platforms, int num_platforms, int* a);

bool CheckCollideRight(bool* collide, Entity player, Entity* platforms, int num_platforms, int* a);

#endif