#include <iostream>
#include <fstream>
#include <vector>
#include "game_map.h"

GameMap::GameMap(const std::string &filename, std::size_t grid_width, std::size_t grid_height)
{
    // read a file
    std::ifstream ifs {filename};
    if (ifs){
    std::cout << "map file " << filename << " reading success" << std::endl;

    std::string line;
    int line_count{0};
    while(std::getline(ifs, line)){

        std::vector<bool> x_elems;

        std::size_t x_grid = line.size();
        // check proper size of the map
        if (x_grid != grid_width){
        std::cout << "map file wrong grid\n";
        }

        for(int i{0}; i<line.size(); i++){

            if(line[i] == '0'){
                x_elems.push_back(false);
            }
            else if(line[i] == '1'){
                x_elems.push_back(true);
                SDL_Point point{i,line_count};
                obstacles.push_back(point);

            }
            else{
                std::cout << "map file error\n";
            }      
        }
        _pixels.push_back(x_elems);
        line_count++;
    }
    // check proper size of the map
    if (line_count != grid_height){
        std::cout << "map file wrong grid\n";
        }
    }
    else{
    std::cout << "map file " << filename << " reading error" << std::endl;
    }
}

// print map
void GameMap::show()
{
    for(auto y : _pixels){
    for(auto x : y){
        std::cout << x;
    }
    std::cout << '\n';
    } 
}

// method to check if cell is occupied by obstacle
bool GameMap::ObstacleCell(int x, int y)
{
  if (_pixels[y][x] == 1)
    return true;
  else
    return false;
}