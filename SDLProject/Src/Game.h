#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class Game
{
public:
  Game();
  ~Game();

  void Init(const char* title, int xPos, int yPos, int width, int height, bool isFullscreen);

  void HandleEvents();
  void Update();
  void Render();
  void Clean();

  bool Running() { return isRunning; }

private:
  int count;
  bool isRunning;
  SDL_Window *window;
  SDL_Renderer *renderer;

};