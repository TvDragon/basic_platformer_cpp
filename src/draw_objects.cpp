#include "../include/draw_objects.hpp"

void DrawObjects(RenderWindow window, int a, int num_platforms, int num_boxes,
                  int num_chests, int num_coins, int num_flags, int num_ladders, int num_keys,
                  int num_non_interactables, int num_enemies,
                  Entity* platforms, Entity* boxes, Entity* chests, Entity* coins, Entity* flags,
                  Entity* ladders, Entity* keys, Entity* non_interactable_objects, Entity* enemies, Entity player) {
  
  window.Clear();
  
  for (a = 0; a < num_platforms; a++) {
    window.Render(platforms[a]);
  }

  for (a = 0; a < num_boxes; a++) {
    window.Render(boxes[a]);
  }

  for (a = 0; a < num_chests; a++) {
    window.Render(chests[a]);
  }

  for (a = 0; a < num_coins; a++) {
    window.Render(coins[a]);
  }

  for (a = 0; a < num_flags; a++) {
    window.Render(flags[a]);
  }

  for (a = 0; a < num_ladders; a++) {
    window.Render(ladders[a]);
  }

  for (a = 0; a < num_keys; a++) {
    window.Render(keys[a]);
  }

  for (a = 0; a < num_non_interactables; a++) {
    window.Render(non_interactable_objects[a]);
  }

  for (a = 0; a < num_enemies; a++) { 
    window.Render(enemies[a]);
    window.DrawHP(enemies[a]);
  }

  // for (a = 0; a < num_enemies; a++) {
  //   window.DrawHitbox(enemies[a]);
  // }

  // window.DrawHitbox(player);

  window.Render(player);
  
  window.RenderText(player);

  window.SetBackgroundColour();

  window.Display();
}