#include <iostream>
#include <fstream>
#include <vector>
#include "game_map.h"

GameMap::GameMap(const std::string &filename, std::size_t grid_width, std::size_t grid_height)
{
    // maps available
    if (filename != ""){
        // parse a file
        std::ifstream ifs {filename};
        if (ifs){

            std::string line;
            int line_count{0};
            while(std::getline(ifs, line)){

                std::vector<bool> x_elems;
                std::size_t x_grid = line.size();

                // check proper size of the map
                if (x_grid != grid_width){
                    std::cout << "Map file - wrong grid\n";
                    // populate a map with false
                    PopulateEmpty();
                    break;                    
                }
                for(int i{0}; i<x_grid; i++){

                    if(line[i] == '0'){
                        x_elems.push_back(false);
                    }
                    else if(line[i] == '1'){
                        x_elems.push_back(true);
                        // populate obstacles container
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
    //no maps
    else {
        std::cout << "No maps available\n";

        // populate a map with false
        PopulateEmpty();
    }
}

// funcction creates a clear map
void GameMap::PopulateEmpty()
{
    // populate a map with false
    for(int y{}; y<_grid_height; y++ ){
        std::vector<bool> x_elems;
        for(int x{}; x<_grid_width; x++){
            x_elems.push_back(false);
        }
        _pixels.push_back(x_elems);
    }
}
