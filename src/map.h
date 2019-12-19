#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include "SDL.h"
#include "object.h"

// the class Map to store a map read from an input file
class Map : public Object {
  public:
    Map(const std::string &filename, std::size_t grid_width, std::size_t grid_height);

    bool Cell(std::size_t x, std::size_t y) const override { return _pixels[y][x]; }

  private:
    // 2D array: false - free block, true - obstacle
    std::vector<std::vector<bool>> _pixels;
    void PopulateEmpty();
};


#endif