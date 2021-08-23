#ifndef ENTITY
#define ENTITY

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
class Entity {
public:
  Entity(); // Empty constructor
  Entity(float x, float y, SDL_Texture* ptr_tex, int num);  // Static objects
  Entity(float x, float y, float speed, int health, SDL_Texture* ptr_tex);  // Enemy
  Entity(float x, float y, float speed, int health, int keys_collected, int coins_collected, int num_attack, bool looking, bool is_stand, bool is_jump, bool is_climbing, SDL_Texture* ptr_tex); // Moving Objects

  void SetX(float x);

  void SetY(float y);

  void SetHealth(int health);

  void SetLooking(bool looking);

  void SetStanding(bool is_stand);

  void SetJump(bool is_jump);

  void SetClimbing(bool is_climbing);

  void SetAttack(int num_attack);

  void SetCoins(int coins_collected);

  void SetKeys(int keys_collected);

  void SetSDLTexture(SDL_Texture* ptr_tex);

  float GetX();

  float GetY();

  int GetHealth();

  float GetSpeed();

  bool GetLooking();

  bool GetStanding();

  bool GetJump();

  bool GetClimbing();

  int GetAttack();

  int GetCoins();

  int GetKeys();

  SDL_Texture* GetTex();

  SDL_Rect GetCurrentFrame();

private:
  int health, keys_collected, num, num_attack, coins_collected;
  float x, y, speed;
  bool looking, is_stand, is_jump, is_climbing;
  SDL_Rect current_frame;
  SDL_Texture* ptr_tex;
};

#endif