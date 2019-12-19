#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include "SDL.h"


class Object {
    public:
        Object(std::size_t grid_width, std::size_t grid_height)
        : _grid_width{grid_width}, _grid_height{grid_height} {}

        virtual bool Cell(std::size_t x, std::size_t y) const = 0;
        std::vector<SDL_Point> body;

    protected:
        std::size_t _grid_width;
        std::size_t _grid_height;
};


#endif