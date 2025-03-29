#include "../include/object_interaction.hpp"

using namespace std;

bool InteractionLadder(Entity player, Entity object) {
  float player_x = player.GetX();
  float player_y = player.GetY();
  float player_width = player.GetX() + player.GetCurrentFrame().w;
  float player_height = player.GetY() + player.GetCurrentFrame().h;

  float object_x = object.GetX();
  float object_y = object.GetY();
  float object_width = object.GetX() + object.GetCurrentFrame().w;
  float object_height = object.GetY() + object.GetCurrentFrame().h;

  // Left side interaction
  if ((player_width >= object_x && player_width <= object_width) &&
        (player_height < object_height && player_height > object_y)) {
      return true;
  } else if ((player_width >= object_x && player_width <= object_width) &&
      (player_y < object_height && player_y > object_y)) {
      return true;
  }

  // Right side interaction
  if ((player_x >= object_x && player_x <= object_width) &&
        (player_y <= object_height && player_y >= object_y)) {
      return true;
  } else if ((player_x >= object_x && player_x <= object_width) &&
        (player_height < object_height && player_height > object_y)) {
      return true;
  }

  return false;
}

bool Interaction(Entity player, Entity object) {
  float player_x = player.GetX();
  float player_y = player.GetY();
  float player_width = player.GetX() + player.GetCurrentFrame().w;
  float player_height = player.GetY() + player.GetCurrentFrame().h;

  float object_x = object.GetX();
  float object_y = object.GetY();
  float object_width = object.GetX() + object.GetCurrentFrame().w;
  float object_height = object.GetY() + object.GetCurrentFrame().h;

  if (object_x < 0 || object_y < 0)
    return false;

  // Left side interaction
  if ((player_width >= object_x && player_width <= object_width) &&
        (player_height <= object_height && player_height >= object_y)) {
      return true;
  } else if ((player_width >= object_x && player_width <= object_width) &&
      (player_y < object_height && player_y > object_y)) {
      return true;
  }

  // Right side interaction
  if ((player_x >= object_x && player_x <= object_width) &&
        (player_y <= object_height && player_y >= object_y)) {
      return true;
  } else if ((player_x >= object_x && player_x <= object_width) &&
        (player_height <= object_height && player_height >= object_y)) {
      return true;
  }

  return false;
}

bool EnemyInteractionLeft(Entity player, Entity enemy) {
  float player_x = player.GetX();
  float player_y = player.GetY();
  float player_width = player.GetX() + player.GetCurrentFrame().w;
  float player_height = player.GetY() + player.GetCurrentFrame().h;


  float enemy_x = enemy.GetX() + 5;
  float enemy_y = enemy.GetY();
  float enemy_width = enemy.GetX() + enemy.GetCurrentFrame().w - 5;
  float enemy_height = enemy.GetY() + enemy.GetCurrentFrame().h;

  if (enemy_x < 0 || enemy_y < 0)
    return false;

  // Left side interaction
  if ((player_x >= enemy_x && player_x <= enemy_width) &&
        (player_y <= enemy_height && player_y >= enemy_y)) {
      return true;
  } else if ((player_x >= enemy_x && player_x <= enemy_width) &&
        (player_height <= enemy_height && player_height >= enemy_y)) {
      return true;
  }

  return false;
}

bool EnemyInteractionRight(Entity player, Entity enemy) {
  float player_x = player.GetX();
  float player_y = player.GetY();
  float player_width = player.GetX() + player.GetCurrentFrame().w;
  float player_height = player.GetY() + player.GetCurrentFrame().h;


  float enemy_x = enemy.GetX() + 5;
  float enemy_y = enemy.GetY();
  float enemy_width = enemy.GetX() + enemy.GetCurrentFrame().w - 5;
  float enemy_height = enemy.GetY() + enemy.GetCurrentFrame().h;

  if (enemy_x < 0 || enemy_y < 0)
    return false;

  // Right side interaction
  if ((player_width >= enemy_x && player_width <= enemy_width) &&
        (player_height <= enemy_height && player_height >= enemy_y)) {
      return true;
  } else if ((player_width >= enemy_x && player_width <= enemy_width) &&
      (player_y < enemy_height && player_y > enemy_y)) {
      return true;
  }

  return false;
}

void Attack(Entity player, Entity* boxes, int *num_boxes, Entity* enemies, int *num_enemies) {

  bool interact = false;
  int i = 0;

  for (; i < *num_boxes; i++) {
    interact = Interaction(player, boxes[i]);
    if (interact == true) {
      *(boxes + i) = Entity(-500, -500, NULL, 1);
    }
  }

  interact = false;
  
  for (i = 0; i < *num_enemies; i++) {
    interact = Interaction(player, enemies[i]);
    if (interact == true) {
      enemies[i].SetHealth(enemies[i].GetHealth() - 1);
      if (enemies[i].GetHealth() <= 0) {
        *(enemies + i) = Entity(-500, -500, 0, 0, NULL);
      }
    }
  }
}

Entity AttackedLeft(Entity player, Entity* enemies, int num_enemies) {
  bool interact = false;
  
  for (int i = 0; i < num_enemies; i++) {
    interact = EnemyInteractionLeft(player, enemies[i]);
    if (interact == true) {
      player.SetHealth(player.GetHealth() - 1);
    }
  }

  return player;
}

Entity AttackedRight(Entity player, Entity* enemies, int num_enemies) {
  bool interact = false;
  
  for (int i = 0; i < num_enemies; i++) {
    interact = EnemyInteractionRight(player, enemies[i]);
    if (interact == true) {
      player.SetHealth(player.GetHealth() - 1);
    }
  }

  return player;
}

Entity GetObjects(Entity player, Entity* coins, Entity* keys, int *num_coins, int *num_keys) {

  bool interact = false;
  int i = 0;

  for (; i < *num_coins; i++) {
    interact = Interaction(player, coins[i]);
    if (interact == true) {
      *(coins + i) = Entity(-500, -500, NULL, 1);
      player.SetCoins(player.GetCoins() + 1);
    }
  }

  for (i = 0; i < *num_keys; i++) {
    interact = Interaction(player, keys[i]);
    if (interact == true) {
      *(keys + i) = Entity(-500, -500, NULL, 1);
      player.SetKeys(player.GetKeys() + 1);
    }
  }

  return player;
}

Entity OpenChest(Entity player, Entity* chests, int *num_chests) {

  bool interact = false;

  if (player.GetKeys() > 0) {
    for (int i = 0; i < *num_chests; i++) {
      interact = Interaction(player, chests[i]);
      if (interact == true) {
        *(chests + i) = Entity(-500, -500, NULL, 1);
        player.SetKeys(player.GetKeys() - 1);
        player.SetCoins(player.GetCoins() + 5);
      }
    }
  }

  return player;
}

Entity ClimbLadder(Entity player, Entity* ladders, int num_ladders) {

  bool interact = false;

  for (int i = 0; i < num_ladders; i++) {
    interact = InteractionLadder(player, ladders[i]);

    if (interact == true) {
      player.SetClimbing(true);
      player.SetStanding(false);
      break;
    }
  }

  return player;
}