#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"

#include <string>
#include <direct.h>

#define GetCurrentDir _getcwd

GameObject* player;
GameObject* enemy;

Game::Game()
{

}
Game::~Game()
{

}

void Game::Init(const char* title, int xPos, int yPos, int width, int height, bool isFullscreen)
{
  int flags = 0;
  if (isFullscreen)
  {
    flags = SDL_WINDOW_FULLSCREEN;
  }

  if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    std::cout << "Subsystems initialized" << std::endl;

    window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
    if (window)
    {
      std::cout << "Window created" << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer)
    {
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
      std::cout << "Renderer created" << std::endl;
    }

    // Game is running
    isRunning = true;
  }
  else
  {
    isRunning = false;
  }

  //char buff[FILENAME_MAX];
  //GetCurrentDir(buff, FILENAME_MAX);

  player = new GameObject("assets/player.png", renderer, 0, 0);
  enemy = new GameObject("assets/enemy.png", renderer, 50, 50);
}

void Game::HandleEvents()
{
  SDL_Event event;
  SDL_PollEvent(&event);

  switch (event.type)
  {
  case SDL_QUIT:
    isRunning = false;
    break;

  default:
    break;
  }
}

void Game::Update()
{
  player->Update();
  enemy->Update();
}

void Game::Render()
{
  SDL_RenderClear(renderer);

  // This is where we would add stuff to render
  player->Render();
  enemy->Render();

  SDL_RenderPresent(renderer);
}

void Game::Clean()
{
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  std::cout << "Game cleaned" << std::endl;
}