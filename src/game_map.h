#ifndef GAME_MAP_H
#define GAME_MAP_H

#include <string>
#include <vector>
#include "SDL.h"

class GameMap
{
  public:
    GameMap(const std::string &filename, std::size_t grid_width, std::size_t grid_height);

    void show();
    bool pixel(int x, int y) { return _pixels[y][x]; }  // retun an element: false - free block, true - obstacle
    std::vector<SDL_Point> obstacles;

  private:
    // 2D array: false - free block, true - obstacle
    std::vector<std::vector<bool>> _pixels;
};

#endif