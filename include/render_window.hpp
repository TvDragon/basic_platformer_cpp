#ifndef RENDER_WINDOW
#define RENDER_WINDOW

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include "entity.hpp"
#include <stdio.h>

#define SCREEN_WIDTH (1024)
#define SCREEN_HEIGHT (640)

class RenderWindow {
public:
  RenderWindow(const char* ptr_title, int width, int height); // Constructor

  SDL_Texture* LoadTexture(const char* ptr_file_path);  // Load image

  int GetRefreshRate(); // Refresh rate for window

  void CleanUp(); // Destroy window

  void Clear(); // Clear window

  void RenderText(Entity player);

  void Render(Entity& ptr_entity);

  void DrawHP(Entity enemy);

  void DrawHitbox(Entity object);

  void SetBackgroundColour();

  void GameOver(Entity player);

  void Display(); // Display window

private:
  SDL_Window* window;
  SDL_Renderer* renderer;
};

#endif