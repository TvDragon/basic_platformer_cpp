#include "../include/entity.hpp"

Entity::Entity() {

}

Entity::Entity(float x, float y, SDL_Texture* ptr_tex, int num)
  :x(x), y(y), ptr_tex(ptr_tex) // Set to values given in parameter
{
  current_frame.x = 0;
  current_frame.y = 0;
  if (num == 0) { // platforms, chests, stones, ridges
    current_frame.w = 32;
    current_frame.h = 32;
  } else if (num == 1) { // boxes, bushes
    current_frame.w = 16;
    current_frame.h = 16;
  } else if (num == 2) {  // grass
    current_frame.w = 8;
    current_frame.h = 8;
  } else if (num == 3) {  // trees, willows
    current_frame.w = 64;
    current_frame.h = 96;
  } else if (num == 4) {  // ladder
    current_frame.w = 32;
    current_frame.h = 64;
  }
}

Entity::Entity(float x, float y, float speed, int health, SDL_Texture* ptr_tex) // enemy
  :x(x), y(y), speed(speed), ptr_tex(ptr_tex), health(health)
{
  current_frame.x = 0;
  current_frame.y = 0;
  current_frame.w = 32;
  current_frame.h = 32;
}

Entity::Entity(float x, float y, float speed, int health, int keys_collected, int coins_collected, int num_attack, bool looking, bool is_stand, bool is_jump, bool is_climbing, SDL_Texture* ptr_tex)
  :x(x), y(y), speed(speed), health(health), keys_collected(keys_collected), coins_collected(coins_collected), num_attack(num_attack), looking(looking), is_stand(is_stand), is_jump(is_jump), is_climbing(is_climbing), ptr_tex(ptr_tex) // Set to values given in parameter
{
  current_frame.x = 0;
  current_frame.y = 0;
  current_frame.w = 32;
  current_frame.h = 32;
}

void Entity::SetX(float x) {
  this->x = x;
}

void Entity::SetY(float y) {
  this->y = y;
}

void Entity::SetHealth(int health) {
  if (health < 0) {
    health = 0;
  }
  this->health = health;
}

void Entity::SetLooking(bool looking) {
  this->looking = looking;
}

void Entity::SetStanding(bool is_stand) {
  this->is_stand = is_stand;
}

void Entity::SetJump(bool is_jump) {
  this->is_jump = is_jump;
}

void Entity::SetClimbing(bool is_climbing) {
  this->is_climbing = is_climbing;
}

void Entity::SetAttack(int num_attack) {
  this->num_attack = num_attack;
}

void Entity::SetCoins(int coins_collected) {
  this->coins_collected = coins_collected;
}

void Entity::SetKeys(int keys_collected) {
  this->keys_collected = keys_collected;
}

void Entity::SetSDLTexture(SDL_Texture* ptr_tex) {
  this->ptr_tex = ptr_tex;
}

float Entity::GetX() {
  return x;
}

float Entity::GetY() {
  return y;
}

int Entity::GetHealth() {
  return health;
}

float Entity::GetSpeed() {
  return speed;
}

bool Entity::GetLooking() {
  return looking;
}

bool Entity::GetStanding() {
  return is_stand;
}

bool Entity::GetJump() {
  return is_jump;
}

bool Entity::GetClimbing() {
  return is_climbing;
}

int Entity::GetAttack() {
  return num_attack;
}

int Entity::GetCoins() {
  return coins_collected;
}

int Entity::GetKeys() {
  return keys_collected;
}

SDL_Texture* Entity::GetTex() {
  return ptr_tex;
}

SDL_Rect Entity::GetCurrentFrame() {
  return current_frame;
}