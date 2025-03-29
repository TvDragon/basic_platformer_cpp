#ifndef UTILS
#define UTILS

#include <SDL2/SDL.h>

namespace utils {
  inline float HireTimeInSeconds() {{
    float t = SDL_GetTicks();
    t *= 0.001f;

    return t;
  }}
}

#endif