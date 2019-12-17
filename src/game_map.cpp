#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
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
        for(int y{}; y<grid_height; y++ ){
            std::vector<bool> x_elems;
            for(int x{}; x<grid_width; x++){
                x_elems.push_back(false);
            }
            _pixels.push_back(x_elems);
        }
    }    
}

// helper functions
// function to select a map
std::string SelectMap()
{
    std::string filename = "";
    std::string path = "../maps/";
    std::vector<std::string> maps;

    // read map files available
    for(const auto &entry : std::filesystem::directory_iterator(path)){
        maps.push_back(entry.path());
    }

    // prompt the user and parse a selected map
    if(!maps.empty()){
        
        int id_selected {0};

        std::cout << "Please select a map by its id:\n";

        // print names of the maps cutting path and extension off
        std::size_t path_length = 8;
        std::size_t unused_lenght = 12;
        for (std::size_t i{}; i<maps.size(); i++) {
            std::size_t name_length = (maps[i].size() - unused_lenght);
            std::cout << (i+1) << ". " << maps[i].substr(path_length, name_length) << '\n';
        }

        std::cin >> id_selected;
        // echo selected map
        std::cout << "Map \""
                    << maps[id_selected-1].substr(path_length, (maps[id_selected-1].size() - unused_lenght))
                    << "\" selected\n";

        filename = maps[id_selected-1];
    }
    return filename;
}