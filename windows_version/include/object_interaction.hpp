#ifndef OBJECT_INTERACTION
#define OBJECT_INTERACTION

#include "entity.hpp"
#include <iostream>
#include <string>

bool InteractionLadder(Entity player, Entity object);

bool Interaction(Entity player, Entity* objects);

bool EnemyInteractionLeft(Entity player, Entity* enemies);

bool EnemyInteractionRight(Entity player, Entity* enemies);

void Attack(Entity player, Entity* boxes, int *num_boxes, Entity* enemies, int *num_enemies);

Entity AttackedLeft(Entity player, Entity* enemies, int num_enemies);

Entity AttackedRight(Entity player, Entity* enemies, int num_enemies);

Entity GetObjects(Entity player, Entity* coins, Entity* keys, int *num_coins, int *num_keys);

Entity OpenChest(Entity player, Entity* chests, int *num_chests);

Entity ClimbLadder(Entity player, Entity* ladders, int num_ladders);

#endif