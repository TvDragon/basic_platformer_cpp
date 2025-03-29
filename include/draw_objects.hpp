#ifndef DRAW_OBJECTS
#define DRAW_OBJECTS

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>

#include "render_window.hpp"
#include "entity.hpp"

void DrawObjects(RenderWindow window, int a, int num_platforms, int num_boxes,
                  int num_chests, int num_coins, int num_flags, int num_ladders, int num_keys,
                  int num_non_interactables, int num_enemies,
                  Entity* platforms, Entity* boxes, Entity* chests, Entity* coins, Entity* flags,
                  Entity* ladders, Entity* keys, Entity* non_interactable_objects, Entity* enemies, Entity player);

#endif