#include "../include/render_window.hpp"
#include "../include/entity.hpp"
#include "../include/utils.hpp"
#include "../include/check_collision.hpp"
#include "../include/object_interaction.hpp"
#include "../include/draw_objects.hpp"

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>

using namespace std;

int GetTextureIndex(char character, int index) {

  int ascii_value = int(character);
  if (ascii_value < 58 && ascii_value > 48) {
    index = ascii_value - 49;
  } else if (ascii_value > 64 && ascii_value < 82) {
    index = ascii_value - 56;
  } else if(ascii_value > 82 && ascii_value < 91) {
    index = ascii_value - 57;
  } else if (ascii_value == 82) {
    index = -2;
  } else {
    index = -1;
  }
  return index;
}

int main(int argc, char** argv) {

  if (TTF_Init() < 0)
    printf("TTF could not initialise! TTF_Error :%s\n", TTF_GetError());

  // Returns 0 on success else non-zero
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    printf("SDL could not initialise! SDL_Error: %s\n", SDL_GetError());
  
  if (!(IMG_Init(IMG_INIT_PNG)))
    printf("IMG_init has failed. ERROR: %s\n", SDL_GetError());

  RenderWindow window("RPG Platformer", SCREEN_WIDTH, SCREEN_HEIGHT);

  SDL_Texture* imgs[34] = {window.LoadTexture("C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/forest/tiles/Tile_02.png"),
                            window.LoadTexture("C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/windows_version/res/forest/tiles/Tile_07.png"),
                            window.LoadTexture("C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/forest/tiles/Tile_08.png"),
                            window.LoadTexture("C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/forest/tiles/Tile_09.png"),
                            window.LoadTexture("C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/forest/tiles/Tile_31.png"),
                            window.LoadTexture("C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/forest/tiles/Tile_32.png"),
                            window.LoadTexture("C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/forest/tiles/Tile_33.png"),
                            window.LoadTexture("C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/forest/tiles/Tile_34.png"),
                            window.LoadTexture("C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/forest/tiles/Tile_39.png"),
                            window.LoadTexture("C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/forest/animated_objects/chest/chest-1.png"),
                            window.LoadTexture("C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/forest/animated_objects/coin/coin-1.png"),
                            window.LoadTexture("C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/forest/animated_objects/flag/flag-1.png"),
                            window.LoadTexture("C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/forest/animated_objects/key/key-1.png"),
                            window.LoadTexture("C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/forest//objects/Boxes/1.png"),
                            window.LoadTexture("C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/forest//objects/Boxes/3.png"),
                            window.LoadTexture("C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/forest//objects/Boxes/4.png"),
                            window.LoadTexture("C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/forest//objects/Bushes/1.png"),
                            window.LoadTexture("C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/forest//objects/Bushes/3.png"),
                            window.LoadTexture("C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/forest//objects/Bushes/5.png"),
                            window.LoadTexture("C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/forest//objects/Bushes/8.png"),
                            window.LoadTexture("C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/forest//objects/Grass/1.png"),
                            window.LoadTexture("C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/forest//objects/Grass/2.png"),
                            window.LoadTexture("C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/forest//objects/Grass/6.png"),
                            window.LoadTexture("C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/forest//objects/Ladders/3.png"),
                            window.LoadTexture("C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/forest//objects/Ladders/5.png"),
                            window.LoadTexture("C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/forest//objects/Ridges/1.png"),
                            window.LoadTexture("C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/forest//objects/Stones/1.png"),
                            window.LoadTexture("C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/forest//objects/Stones/4.png"),
                            window.LoadTexture("C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/forest//objects/Stones/5.png"),
                            window.LoadTexture("C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/forest//objects/Trees/1.png"),
                            window.LoadTexture("C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/forest//objects/Trees/2.png"),
                            window.LoadTexture("C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/forest//objects/Willows/1.png"),
                            window.LoadTexture("C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/forest//objects/Willows/2.png"),
                            window.LoadTexture("C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/idle_right/idle_1.png")};

  // Store left and right idle file paths
  /* CHANGE THE BELOW INTO STRING FORMATING */
  string idles[8] = {"C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/idle_right/idle_1.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/idle_right/idle_2.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/idle_right/idle_3.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/idle_right/idle_4.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/idle_left/idle_1_left.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/idle_left/idle_2_left.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/idle_left/idle_3_left.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/idle_left/idle_4_left.png"};
  string runs[12] = {"C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/run_right/run_1.png",
                    "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/run_right/run_2.png",
                    "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/run_right/run_3.png",
                    "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/run_right/run_4.png",
                    "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/run_right/run_5.png",
                    "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/run_right/run_6.png",
                    "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/run_left/run_1_left.png",
                    "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/run_left/run_2_left.png",
                    "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/run_left/run_3_left.png",
                    "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/run_left/run_4_left.png",
                    "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/run_left/run_5_left.png",
                    "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/run_left/run_6_left.png"};
  string jumps[24] = {"C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/jump_right/jump_1.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/jump_right/jump_2.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/jump_right/jump_3.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/jump_right/jump_4.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/jump_right/jump_5.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/jump_right/jump_6.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/jump_right/jump_7.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/jump_right/jump_8.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/jump_right/jump_9.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/jump_right/jump_10.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/jump_right/jump_11.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/jump_right/jump_12.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/jump_left/jump_1_left.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/jump_left/jump_2_left.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/jump_left/jump_3_left.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/jump_left/jump_4_left.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/jump_left/jump_5_left.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/jump_left/jump_6_left.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/jump_left/jump_7_left.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/jump_left/jump_8_left.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/jump_left/jump_9_left.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/jump_left/jump_10_left.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/jump_left/jump_11_left.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/jump_left/jump_12_left.png"};
  string attacks_one[14] = {"C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/attack_1_right/attack_1_1.png",
                            "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/attack_1_right/attack_1_2.png",
                            "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/attack_1_right/attack_1_3.png",
                            "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/attack_1_right/attack_1_4.png",
                            "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/attack_1_right/attack_1_5.png",
                            "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/attack_1_right/attack_1_6.png",
                            "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/attack_1_right/attack_1_7.png",
                            "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/attack_1_left/attack_1_1_left.png",
                            "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/attack_1_left/attack_1_2_left.png",
                            "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/attack_1_left/attack_1_3_left.png",
                            "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/attack_1_left/attack_1_4_left.png",
                            "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/attack_1_left/attack_1_5_left.png",
                            "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/attack_1_left/attack_1_6_left.png",
                            "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/attack_1_left/attack_1_7_left.png"};
  string attacks_two[8] = {"C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/attack_2_right/attack_2_1.png",
                            "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/attack_2_right/attack_2_2.png",
                            "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/attack_2_right/attack_2_3.png",
                            "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/attack_2_right/attack_2_4.png",
                            "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/attack_2_left/attack_2_1_left.png",
                            "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/attack_2_left/attack_2_2_left.png",
                            "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/attack_2_left/attack_2_3_left.png",
                            "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/attack_2_left/attack_2_4_left.png"};
  string attacks_three[12] = {"C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/attack_3_right/attack_3_1.png",
                              "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/attack_3_right/attack_3_2.png",
                              "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/attack_3_right/attack_3_3.png",
                              "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/attack_3_right/attack_3_4.png",
                              "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/attack_3_right/attack_3_5.png",
                              "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/attack_3_right/attack_3_6.png",
                              "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/attack_3_left/attack_3_1_left.png",
                              "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/attack_3_left/attack_3_2_left.png",
                              "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/attack_3_left/attack_3_3_left.png",
                              "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/attack_3_left/attack_3_4_left.png",
                              "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/attack_3_left/attack_3_5_left.png",
                              "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/player_images/attack_3_left/attack_3_6_left.png",};

  string enemy_images[22] = {"C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/enemy_images/L1E.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/enemy_images/L2E.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/enemy_images/L3E.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/enemy_images/L4E.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/enemy_images/L5E.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/enemy_images/L6E.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/enemy_images/L7E.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/enemy_images/L8E.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/enemy_images/L9E.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/enemy_images/L10E.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/enemy_images/L11E.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/enemy_images/R1E.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/enemy_images/R2E.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/enemy_images/R3E.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/enemy_images/R4E.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/enemy_images/R5E.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/enemy_images/R6E.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/enemy_images/R7E.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/enemy_images/R8E.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/enemy_images/R9E.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/enemy_images/R10E.png",
                      "C:/Users/TvDra/Desktop/projects/basic_platformer_cpp/windows_version/res/enemy_images/R11E.png"};

  SDL_Texture* idle = window.LoadTexture(idles[0].c_str()); // Convert std::string to const char*
  SDL_Texture* run = window.LoadTexture(runs[0].c_str());
  SDL_Texture* jump = window.LoadTexture(jumps[0].c_str());
  SDL_Texture* attack = window.LoadTexture(attacks_one[0].c_str());

  SDL_Texture* enemy = window.LoadTexture(enemy_images[0].c_str());

  // x-coor, y-coor, speed, health, keys, coins, attack_mode, direction looking, standing, not jumping, not climbing, image
  Entity player(96, 576, 10, 5, 0, 0, 0, true, true, false, false, idle);

  Entity platforms[152];
  Entity boxes[4];
  Entity chests[3];
  Entity coins[6];
  Entity flags[2];
  Entity ladders[13];
  Entity keys[3];
  Entity non_interactable_objects[24];
  Entity enemies[4];

  string filename = "map.txt";
  fstream f;
  f.open(filename, ios::in);	// open file to read

  if (f.is_open()) {	// checking if file is open
    string line;
    int index = 0;
    int plats_idx = 0;
    int boxes_idx = 0;
    int chests_idx = 0;
    int coins_idx = 0;
    int flags_idx = 0;
    int ladders_idx = 0;
    int keys_idx = 0;
    int non_inter_idx = 0;
    int enemies_idx = 0;
    float i = 0;
    while (getline(f, line)) {	// read data object and put into string
      for (float j = 0; j < line.length(); j++) {
        index = GetTextureIndex(line[j], index);
        if (index == -1) {
          // NULL
        } else if (index == -2) {
          // enemies
          enemies[enemies_idx] = Entity(j*32, i*32, 6, 5, enemy);
          enemies_idx += 1;
        } else if (index < 9) {
          // platforms
          platforms[plats_idx] = Entity(j*32, i*32, imgs[index], 0);
          plats_idx += 1;
        } else if (index == 9) {
          // chests
          chests[chests_idx] = Entity(j*32, i*32, imgs[index], 0);
          chests_idx += 1;
        } else if (index == 10) {
          // coin
          coins[coins_idx] = Entity(j*32, i*32, imgs[index], 0);
          coins_idx += 1;
        } else if (index == 11) {
          // flag
          flags[flags_idx] = Entity(j*32, i*32, imgs[index], 0);
          flags_idx += 1;
        } else if (index == 12) {
          // keys
          keys[keys_idx] = Entity(j*32, i*32, imgs[index], 0);
          keys_idx += 1;
        } else if (index == 13 || index == 14 || index == 15) {
          // boxes
          boxes[boxes_idx] = Entity(j*32, i*32+16, imgs[index], 1);
          boxes_idx += 1;
        } else if (index == 23 || index == 24) {
            // ladders
            ladders[ladders_idx] = Entity(j*32, (i-1)*32, imgs[index], 4);
            ladders_idx += 1;
        } else {
          // all other non-interactable objects
          if (index < 20 && index > 15) {
            // bushes
            non_interactable_objects[non_inter_idx] = Entity(j*32, i*32+16, imgs[index], 1);
          } else if (index > 19 && index < 23) {
            // grass
            non_interactable_objects[non_inter_idx] = Entity(j*32, i*32+24, imgs[index], 2);
          } else if (index == 25) {
            // ridges
            non_interactable_objects[non_inter_idx] = Entity(j*32, i*32, imgs[index], 0);
          } else if (index > 25 && index < 29) {
            // stones
            non_interactable_objects[non_inter_idx] = Entity(j*32, i*32, imgs[index], 0);
          } else if (index == 29 || index == 30) {
            // trees
            non_interactable_objects[non_inter_idx] = Entity(j*32, i*32, imgs[index], 3);
          } else if (index == 31 || index == 32) {
            // willows
            non_interactable_objects[non_inter_idx] = Entity(j*32, i*32, imgs[index], 3);
          }
          non_inter_idx += 1;
        }
      }
      i += 1;
    }

    f.close();
  }

  int a = 0;
  int num_platforms = sizeof(platforms) / sizeof(platforms[0]);  // Find how many platforms exist
  int num_boxes = sizeof(boxes) / sizeof(boxes[0]);
  int num_coins = sizeof(coins) / sizeof(coins[0]);
  int num_keys = sizeof(keys) / sizeof(keys[0]);
  int num_chests = sizeof(chests) / sizeof(chests[0]);
  int num_flags = sizeof(flags) / sizeof(flags[0]);
  int num_ladders = sizeof(ladders) / sizeof(ladders[0]);
  int num_non_interactables = sizeof(non_interactable_objects) / sizeof(non_interactable_objects[0]);
  int num_enemies = sizeof(enemies) / sizeof(enemies[0]);

  bool game_running = true;
  bool collide = false;
  bool player_running = false;
  bool game_over = false;

  SDL_Event event;  // Take events from keyboard

  // Rotation between images
  int i = 0;  // Running
  int j = 6;
  int k = 0;  // idle
  int l = 4;
  int m = 0;  // jumping
  int n = 12;
  int p = 0;  // attack 1
  int q = 7;
  int r = 0;  // attack 2
  int s = 4;
  int t = 0;  // attack 3
  int u = 6;
  int v_ticks = 0;  // enemy
  int ticks = 0;  // used for jumping
  int invulnerable = 0;

  while (game_running) {  // Game Loop

    if (i > 5)  // Reset back to beginning of images
      i = 0;
    if (j > 11)
      j = 6;
    if (k > 3)
      k = 0;
    if (l > 7)
      l = 4;
    if (m > 11) {
      m = 0;
      player.SetJump(false);
    }
    if (n > 23) {
      n = 12;
      player.SetJump(false);
    }
    if (ticks > 11) {
      ticks = 0;
      m = 0;
      n = 12;
      player.SetJump(false);
      player.SetStanding(true);
      // cout << endl;
    }
    if (p > 6) {
      p = 0;
      player.SetAttack(0);
      player.SetStanding(true);
      Attack(player, boxes, &num_boxes, enemies, &num_enemies);
    }
    if (q > 13) {
      q = 7;
      player.SetAttack(0);
      player.SetStanding(true);
      Attack(player, boxes, &num_boxes, enemies, &num_enemies);
    }
    if (r > 3) {
      r = 0;
      player.SetAttack(0);
      player.SetStanding(true);
      Attack(player, boxes, &num_boxes, enemies, &num_enemies);
    }
    if (s > 7) {
      s = 4;
      player.SetAttack(0);
      player.SetStanding(true);
      Attack(player, boxes, &num_boxes, enemies, &num_enemies);
    }
    if (t > 5) {
      t = 0;
      player.SetAttack(0);
      player.SetStanding(true);
      Attack(player, boxes, &num_boxes, enemies, &num_enemies);
    }
    if (u > 11) {
      u = 6;
      player.SetAttack(0);
      player.SetStanding(true);
      Attack(player, boxes, &num_boxes, enemies, &num_enemies);
    }

    if (player.GetStanding()) {
      if (player.GetLooking()) {  // Looking right
        idle = window.LoadTexture(idles[k].c_str());
        k += 1;
      } else {  // Looking left
        idle = window.LoadTexture(idles[l].c_str());
        l += 1;
      }
      player.SetSDLTexture(idle);
      SDL_Delay(150);
    }

    if (player.GetJump()) {
      collide = false;
      if (player.GetLooking()) {
        jump = window.LoadTexture(jumps[m].c_str());
        m += 1;
      } else if (!player.GetLooking()) {
        jump = window.LoadTexture(jumps[n].c_str());
        n += 1;
      }

      if (ticks < 6) {  // Jumping up
        collide = CheckCollideTop(&collide, player, platforms, num_platforms, &a);
        if (collide) {
          if (a == -1) {
            player.SetY(0);
          } else {
            player.SetY(platforms[a].GetY() + platforms[a].GetCurrentFrame().h);
          }
        } else {
          player.SetY(player.GetY() - player.GetSpeed()/2);
        }
      } else {  // Falling down
        collide = CheckCollideBottom(&collide, player, platforms, num_platforms, &a);
        if (collide) {
          if (a == -1) {
            player.SetY(SCREEN_HEIGHT - player.GetCurrentFrame().h);
          } else {
            player.SetY(platforms[a].GetY() - platforms[a].GetCurrentFrame().h);
          }
        } else {
          player.SetY(player.GetY() + player.GetSpeed()/2);
        }
      }
      ticks += 1;
      player.SetSDLTexture(jump);
      SDL_Delay(100);
    }

    if (!player.GetJump()) {  // When attacking
      if (player.GetLooking()) {
        if (player.GetAttack() == 1) {
          attack = window.LoadTexture(attacks_one[p].c_str());
          p += 1;
          player.SetSDLTexture(attack);
          SDL_Delay(100);
        } else if (player.GetAttack() == 2) {
          attack = window.LoadTexture(attacks_two[r].c_str());
          r += 1;
          player.SetSDLTexture(attack);
          SDL_Delay(100);
        } else if (player.GetAttack() == 3) {
          attack = window.LoadTexture(attacks_three[t].c_str());
          t += 1;
          player.SetSDLTexture(attack);
          SDL_Delay(115);
        }
      } else {
        if (player.GetAttack() == 1) {
          attack = window.LoadTexture(attacks_one[q].c_str());
          q += 1;
          player.SetSDLTexture(attack);
          SDL_Delay(100);
        } else if (player.GetAttack() == 2) {
          attack = window.LoadTexture(attacks_two[s].c_str());
          s += 1;
          player.SetSDLTexture(attack);
          SDL_Delay(100);
        } else if (player.GetAttack() == 3) {
          attack = window.LoadTexture(attacks_three[u].c_str());
          u += 1;
          player.SetSDLTexture(attack);
          SDL_Delay(115);
        }
      }
    }

    // Object interaction
    player = GetObjects(player, coins, keys, &num_coins, &num_keys);
    player = OpenChest(player, chests, &num_chests);

    if (player.GetClimbing()) {
      collide = CheckCollideTop(&collide, player, platforms, num_platforms, &a);
      if (!collide) {
        player.SetY(player.GetY() - player.GetSpeed());
      } else {
        if (a == -1) {
          player.SetY(0);
        } else {
          player.SetY(platforms[a].GetY() - platforms[a].GetCurrentFrame().h);
          player.SetStanding(true);
          player.SetClimbing(false);
        }
      }
    }

    if (!player.GetJump() && !player.GetClimbing()) {  // Check if player is falling
      collide = CheckCollideFalling(&collide, player, platforms, num_platforms, &a);
      if (collide) {
        if (a == -1) {
          player.SetY(SCREEN_HEIGHT - player.GetCurrentFrame().h);
        } else {
          player.SetY(platforms[a].GetY() - platforms[a].GetCurrentFrame().h);
        }
      } else {
        player.SetY(player.GetY() + player.GetSpeed()*2);
      }
    }


    const Uint8* keystates = SDL_GetKeyboardState(NULL);
    if (keystates[SDL_SCANCODE_Q])
      game_running = false;
    if (keystates[SDL_SCANCODE_Z]) {  // attack one
      player.SetAttack(1);
      player.SetStanding(false);
    }
    if (keystates[SDL_SCANCODE_X]) {  // attack two
      player.SetAttack(2);
      player.SetStanding(false);
    }
    if (keystates[SDL_SCANCODE_C]) { // attack three
      player.SetAttack(3);
      player.SetStanding(false);
    }
    if (keystates[SDL_SCANCODE_UP])
      player = ClimbLadder(player, ladders, num_ladders);
    if (keystates[SDL_SCANCODE_DOWN]) {
      collide = CheckCollideBottom(&collide, player, platforms, num_platforms, &a);
      if (!collide) {
        player.SetY(player.GetY() + player.GetSpeed());
      } else {
        if (a == -1) {
          player.SetY(SCREEN_HEIGHT - player.GetCurrentFrame().h);
        } else {
          player.SetY(platforms[a].GetY() - platforms[a].GetCurrentFrame().h);
        }
      }
    }
    if (keystates[SDL_SCANCODE_SPACE]) {
      player.SetJump(true);
          player.SetStanding(false);
    }
    if (keystates[SDL_SCANCODE_LEFT]) {
      player.SetLooking(false); // Looking left
      player_running = true;
      if (ticks < 11 && ticks > 0) {
        player.SetJump(true);
      }
      if (!player.GetJump()) {  // only run this id player jumps
        run = window.LoadTexture(runs[j].c_str());
        player.SetSDLTexture(run);
      }
      collide = CheckCollideLeft(&collide, player, platforms, num_platforms, &a);
      if (!collide) {
        player.SetX(player.GetX() - player.GetSpeed());
      } else {
        if (a == -1) {
          player.SetX(0);
        } else {
          if (!player.GetJump())
          player.SetX(platforms[a].GetX() + platforms[a].GetCurrentFrame().w);
        }
      }
      player.SetStanding(false);
      j += 1;
    }
    if (keystates[SDL_SCANCODE_RIGHT]) {
      player.SetLooking(true); // Looking right
      player_running = true;
      if (ticks < 11 && ticks > 0) {
        player.SetJump(true);
      }
      if (!player.GetJump()) {
        run = window.LoadTexture(runs[i].c_str());  // To get different running animation
        player.SetSDLTexture(run);
      }
      collide = CheckCollideRight(&collide, player, platforms, num_platforms, &a);
      if (!collide) { 
        player.SetX(player.GetX() + player.GetSpeed());
      } else {
        if (a == -1) {
          player.SetX(SCREEN_WIDTH - player.GetCurrentFrame().w);
        } else {
          if (!player.GetJump())
            player.SetX(platforms[a].GetX() - platforms[a].GetCurrentFrame().w);
        }
      }
      player.SetStanding(false);  // Not standing
      i += 1;
    }
    while (SDL_PollEvent(&event)) {
      collide = false;
      a = 0;
      if (event.type == SDL_QUIT) {
        game_running = false;
      } else if (event.type == SDL_KEYDOWN) {
        // Keyboard API for key pressed
        switch (event.key.keysym.scancode) {
        default:
          break;
        k = 0;
        l = 4;
        }
      } else {
        if (player.GetAttack() == 0 && !player.GetJump()) {
          player.SetStanding(true); // nothing is pressed
          player_running = false;
        }
      }
    }

    DrawObjects(window, a, num_platforms, num_boxes, num_chests, num_coins, num_flags,
          num_ladders, num_keys, num_non_interactables, num_enemies, platforms,
          boxes, chests, coins, flags, ladders, keys, non_interactable_objects, enemies, player);

    SDL_Delay(50);

    if (player.GetHealth() <= 0) {
      game_running = false;
      game_over = true;
    }
    
    v_ticks += 1;
    if (v_ticks > 21)
      v_ticks = 0;

    if (v_ticks == 8 || v_ticks == 9) {
      if (invulnerable == 0 || invulnerable == 3) {
        player = AttackedRight(player, enemies, num_enemies);
      }
      invulnerable += 1;
    } else if (v_ticks == 19 || v_ticks == 20) {
      if (invulnerable == 0 || invulnerable == 3) {
        player = AttackedLeft(player, enemies, num_enemies);
      }
      invulnerable += 1;
    }

    if (invulnerable > 3)
      invulnerable = 0;

    enemy = window.LoadTexture(enemy_images[v_ticks].c_str());

    // Move enemies
    for (a = 0; a < num_enemies; a++) {
      enemies[a].SetSDLTexture(enemy);
      if (v_ticks > -1 && v_ticks < 11) {
        enemies[a].SetX(enemies[a].GetX() - enemies[a].GetSpeed());
      } else if (v_ticks > 10 && v_ticks < 22) {
        enemies[a].SetX(enemies[a].GetX() + enemies[a].GetSpeed());
      }
    }
  
  }

  if (game_over) {
    // Write Game Over
    window.Clear();

    window.GameOver(player);

    window.Display();

    SDL_Delay(2000);
  }

  window.CleanUp();
  TTF_Quit();
  SDL_Quit();

  return 0;
}