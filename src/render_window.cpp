#include "../include/render_window.hpp"
#include "../include/entity.hpp"
#include <stdio.h>
#include <string>

#include <iostream>
using namespace std;

// Create class RenderWindow
RenderWindow::RenderWindow(const char* ptr_title, int width, int height)
  :window(NULL), renderer(NULL) // Set NULL pointer to window and renderer initially
{
  window = SDL_CreateWindow(ptr_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
              width, height, SDL_WINDOW_SHOWN);

  if (window == NULL)
    printf("Window failed to init. Error %s\n", SDL_GetError());

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  // the window, index graphics, use graphics faster if exist
}

SDL_Texture* RenderWindow::LoadTexture(const char* ptr_file_path) {
  SDL_Texture* ptr_texture = NULL;

  ptr_texture = IMG_LoadTexture(renderer, ptr_file_path);

  if (ptr_texture == NULL)
    printf("Failed to load texture. Error: %s\n", SDL_GetError());

  return ptr_texture;
}

int RenderWindow::GetRefreshRate() {
  int display_index = SDL_GetWindowDisplayIndex(window);  // Figures out which screen our window is on

  SDL_DisplayMode mode;

  SDL_GetDisplayMode(display_index, 0, &mode);

  return mode.refresh_rate;
}

void RenderWindow::CleanUp() {
  SDL_DestroyWindow(window);  // Destroy game window
}

void RenderWindow::Clear() {
  SDL_RenderClear(renderer);
}

void RenderWindow::RenderText(Entity player) {

  char keys[18];
  char coins[19];
  char hp[11];
  sprintf(keys, "Keys Collected: %d", player.GetKeys());
  sprintf(coins, "Coins Collected: %d", player.GetCoins());
  sprintf(hp, "Health: %d", player.GetHealth());

  // Type Text On Screen
  TTF_Font* font = TTF_OpenFont("fonts/MoonFlowerBold-MVppp.ttf", 14);  // Font type ttf in folder
  SDL_Color text_colour = {255, 255, 255};

  // as TTF_RenderText_Solid could only be used on
  // SDL_Surface then you have to create the surface first
  SDL_Surface* surface_message_key = TTF_RenderText_Solid(font, keys, text_colour);
  SDL_Surface* surface_message_coin = TTF_RenderText_Solid(font, coins, text_colour);
  SDL_Surface* surface_message_health = TTF_RenderText_Solid(font, hp, text_colour);
  // now you can convert it into a texture
  SDL_Texture* message_one = SDL_CreateTextureFromSurface(renderer, surface_message_key);
  SDL_Texture* message_two = SDL_CreateTextureFromSurface(renderer, surface_message_coin);
  SDL_Texture* message_three = SDL_CreateTextureFromSurface(renderer, surface_message_health);

  SDL_Rect message_rect_one; //create a rect
  message_rect_one.x = 5;  //controls the rect's x coordinate 
  message_rect_one.y = 5; // controls the rect's y coordinte
  message_rect_one.w = 120; // controls the width of the rect
  message_rect_one.h = 30; // controls the height of the rect

  SDL_Rect message_rect_two; //create a rect
  message_rect_two.x = 5; 
  message_rect_two.y = 35;
  message_rect_two.w = 120;
  message_rect_two.h = 30;

  SDL_Rect message_rect_three;
  message_rect_three.x = 5;
  message_rect_three.y = 65;
  message_rect_three.w = 120;
  message_rect_three.h = 30;

  // renderer, message, crop size (ignore), rect with coordinate
  SDL_RenderCopy(renderer, message_one, NULL, &message_rect_one);
  SDL_RenderCopy(renderer, message_two, NULL, &message_rect_two);
  SDL_RenderCopy(renderer, message_three, NULL, &message_rect_three);
  SDL_FreeSurface(surface_message_key);
  SDL_FreeSurface(surface_message_coin);
  SDL_FreeSurface(surface_message_health);
  SDL_DestroyTexture(message_one);
  SDL_DestroyTexture(message_two);
  SDL_DestroyTexture(message_three);
  TTF_CloseFont(font);
}

void RenderWindow::GameOver(Entity player) {
  
  char gameover[10] = "GAME OVER";

  // Type Text On Screen
  TTF_Font* font = TTF_OpenFont("fonts/MoonFlowerBold-MVppp.ttf", 30);  // Font type ttf in folder
  SDL_Color text_colour = {255, 255, 255};

  // as TTF_RenderText_Solid could only be used on
  // SDL_Surface then you have to create the surface first
  SDL_Surface* surface_message_gameover = TTF_RenderText_Solid(font, gameover, text_colour);
  // now you can convert it into a texture
  SDL_Texture* message_one = SDL_CreateTextureFromSurface(renderer, surface_message_gameover);

  SDL_Rect message_rect_one; //create a rect
  message_rect_one.x = SCREEN_WIDTH / 2 - 240;  //controls the rect's x coordinate 
  message_rect_one.y = SCREEN_HEIGHT / 2 - 120; // controls the rect's y coordinte
  message_rect_one.w = 480; // controls the width of the rect
  message_rect_one.h = 120; // controls the height of the rect

  // renderer, message, crop size (ignore), rect with coordinate
  SDL_RenderCopy(renderer, message_one, NULL, &message_rect_one);

  SDL_FreeSurface(surface_message_gameover);

  SDL_DestroyTexture(message_one);

  TTF_CloseFont(font);
}

void RenderWindow::Render(Entity& ptr_entity) {

  SDL_Rect src; // Actual size of texture
  src.x = ptr_entity.GetCurrentFrame().x;
  src.y = ptr_entity.GetCurrentFrame().y;
  src.w = ptr_entity.GetCurrentFrame().w;
  src.h = ptr_entity.GetCurrentFrame().h;

  SDL_Rect dst; // Where we wish to place it at
  dst.x = ptr_entity.GetX();  // x pos
  dst.y = ptr_entity.GetY();  // y pos
  dst.w = ptr_entity.GetCurrentFrame().w; // width size
  dst.h = ptr_entity.GetCurrentFrame().h; // height size

  SDL_RenderCopy(renderer, ptr_entity.GetTex(), &src, &dst);  // renderer, path fiel for texture, size of texture, where to place texture
}

void RenderWindow::DrawHP(Entity enemy) {
  SDL_Rect fill_rect = {int(enemy.GetX()), int(enemy.GetY()) - 10, 30, 10}; // x, y, width, height
  SDL_SetRenderDrawColor(renderer, 0xff, 0x00, 0x00, 0xff); // Change renderer colour to red
  SDL_RenderFillRect(renderer, &fill_rect);

  fill_rect = {int(enemy.GetX()), int(enemy.GetY()) - 10, enemy.GetHealth() * 6, 10};
  SDL_SetRenderDrawColor(renderer, 0x00, 0xff, 0x00, 0xff); // Change renderer colour to green
  SDL_RenderFillRect(renderer, &fill_rect);
}

void RenderWindow::DrawHitbox(Entity object) {
  SDL_Rect outline_rect = {int(object.GetX()) + 5, int(object.GetY()), int(object.GetCurrentFrame().w) - 5, int(object.GetCurrentFrame().h)};
  SDL_SetRenderDrawColor(renderer, 0xff, 0x00, 0x00, 0xff);
  SDL_RenderDrawRect(renderer, &outline_rect);
}

void RenderWindow::SetBackgroundColour() {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set renderer colour back to black
}

void RenderWindow::Display() {
  SDL_RenderPresent(renderer);
}