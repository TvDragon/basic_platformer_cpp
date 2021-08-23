#include "../include/check_collision.hpp"
#include "../include/render_window.hpp"

#include <iostream>

using namespace std;

bool CheckCollideFalling(bool* collide, Entity player, Entity* platforms, int num_platforms, int* a) {

  float player_x = player.GetX();
  float player_y = player.GetY();
  float player_width = player.GetCurrentFrame().w;
  float player_height = player.GetCurrentFrame().h;

  if (player_y + player_height + (player.GetSpeed()/2) > SCREEN_HEIGHT) {
    *a = -1;
    *collide = true;
    return *collide;
  }

  for (int i = 0; i < num_platforms; i++) {
    if ((player_x + player_width - 6 > platforms[i].GetX() && player_x + 6 < platforms[i].GetX() + platforms[i].GetCurrentFrame().w) &&
        (player_y + player_height + player.GetSpeed()*2 > platforms[i].GetY() && player_y < platforms[i].GetY() + platforms[i].GetCurrentFrame().h)) {
          *a = i;
          *collide = true;
          return *collide;
    }
  }

  return false;
}

bool CheckCollideBottom(bool* collide, Entity player, Entity* platforms, int num_platforms, int* a) {

  // cout << player.GetY() + player.GetCurrentFrame().h + (player.GetSpeed()/2) << endl;
  if (player.GetY() + player.GetCurrentFrame().h + (player.GetSpeed()/2) > SCREEN_HEIGHT) {
    *a = -1;
    *collide = true;
    return *collide;
  }

  for (int i = 0; i < num_platforms; i++) {
    if ((player.GetX() + player.GetCurrentFrame().w - 2 > platforms[i].GetX() && player.GetX() + 2 < platforms[i].GetX() + platforms[i].GetCurrentFrame().w) &&
        (player.GetY() + player.GetCurrentFrame().h + (player.GetSpeed()/2) > platforms[i].GetY() && player.GetY() < platforms[i].GetY() + platforms[i].GetCurrentFrame().h)) {
          *a = i;
          *collide = true;
          return *collide;
    }
  }

  return false;
}

bool CheckCollideTop(bool* collide, Entity player, Entity* platforms, int num_platforms, int* a) {

  if (player.GetY() - (player.GetSpeed()/2) < 0) {
    *a = -1;
    *collide = true;
    return *collide;
  }
  
  for (int i = 0; i < num_platforms; i++) {
    if ((player.GetX() + player.GetCurrentFrame().w - 2 > platforms[i].GetX() && player.GetX() + 2 < platforms[i].GetX() + platforms[i].GetCurrentFrame().w) &&
        (player.GetY() - (player.GetSpeed()/2) < platforms[i].GetY() + platforms[i].GetCurrentFrame().h && player.GetY() + player.GetCurrentFrame().h - 2 > platforms[i].GetY())) {
          *a = i;
          *collide = true;
          return *collide;
    }
  }

  return false;
}

bool CheckCollideLeft(bool* collide, Entity player, Entity* platforms, int num_platforms, int* a) {

  if (player.GetX() - (player.GetSpeed()/2) < 0) {
    *a = -1;
    *collide = true;
    return *collide;
  }
  
  for (int i = 0; i < num_platforms; i++) {
    if ((player.GetX() - (player.GetSpeed()/2) < platforms[i].GetX() + platforms[i].GetCurrentFrame().w && player.GetX() > platforms[i].GetX()) && 
        (player.GetY() + 3 < platforms[i].GetY() + platforms[i].GetCurrentFrame().h && player.GetY() + player.GetCurrentFrame().h - 3 > platforms[i].GetY())) {
          *a = i;
          *collide = true;
          return *collide;
    }
  }

  return false;
}

bool CheckCollideRight(bool* collide, Entity player, Entity* platforms, int num_platforms, int* a) {

  if (player.GetX() + player.GetCurrentFrame().w + (player.GetSpeed()/2) > SCREEN_WIDTH) {
    *a = -1;
    *collide = true;
    return *collide;
  }
  
  for (int i = 0; i < num_platforms; i++) {
    if ((player.GetX() + player.GetCurrentFrame().w + (player.GetSpeed()/2) > platforms[i].GetX() && player.GetX() + 2 < platforms[i].GetX() + platforms[i].GetCurrentFrame().w) &&
        ((player.GetY() + player.GetCurrentFrame().h - 3 > platforms[i].GetY() && player.GetY() + 3 < platforms[i].GetY() + platforms[i].GetCurrentFrame().h))) {
          *a = i;
          *collide = true;
          return *collide;
    }
  }

  return false;
}