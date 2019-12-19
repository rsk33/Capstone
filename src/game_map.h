#ifndef GAME_MAP_H
#define GAME_MAP_H

#include <string>
#include <vector>
#include "SDL.h"

// the class GameMap to store a map read from an input file
class GameMap
{
  public:
    GameMap(const std::string &filename, std::size_t grid_width, std::size_t grid_height);

    bool ObstacleCell(int x, int y) { return _pixels[y][x]; }
    std::vector<SDL_Point> obstacles; 

  private:
    // 2D array: false - free block, true - obstacle
    std::vector<std::vector<bool>> _pixels;
    int _grid_width;
    int _grid_height;

    void PopulateEmpty();
};


#endif