#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"
#include "object.h"

class Snake : public Object {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Snake(std::size_t grid_width, std::size_t grid_height)
      : Object{grid_width, grid_height},
        head_x(grid_width / 2),
        head_y(grid_height / 2) {}

  void Update();

  void GrowBody();
  bool Cell(std::size_t x, std::size_t y) const override;

  Direction direction = Direction::kUp;

  float speed{0.1f};
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;

 private:
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false};
};

#endif