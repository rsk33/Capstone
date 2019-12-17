#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
#include "game_map.h"

GameMap::GameMap(const std::string &filename, std::size_t grid_width, std::size_t grid_height)
{
    // maps available
    if (filename != ""){
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
    //no maps
    else {

        std::cout << "No maps\n";

        for(int y{}; y<grid_height; y++ ){
            std::vector<bool> x_elems;
            for(int x{}; x<grid_width; x++){
                x_elems.push_back(false);
            }
            _pixels.push_back(x_elems);

        }
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

namespace fs = std::filesystem;

// helper functions
std::string select_map()
{

    std::string filename = "";
    // read maps
    std::string path = "../maps/";

    std::vector<std::string> maps;


    for(const auto &entry : std::filesystem::directory_iterator(path)){
        // std::cout << entry.path() << std::endl;
        maps.push_back(entry.path());
    }

    if(!maps.empty()){
        
        int id_selected {0};

        std::cout << "please select map\n";

        for (int i{}; i<maps.size(); i++) {
            int si = ((maps[i].size()) - 12);
            std::cout << i+1 << " " << (maps[i]).substr(8, si) << '\n';
        }

        std::cin >> id_selected;

        std::cout << "selected map # " << id_selected << " " << maps[id_selected-1] << '\n';

        filename = maps[id_selected-1];

    }



    // ask user to choose

    // return selected name
    return filename;
}