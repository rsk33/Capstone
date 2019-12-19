#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include "utility.h"
#include "map.h"

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
      // the subset (name length) is dynamically calculated as Name = Entire Length - Path - Extension
      std::size_t path_len = 8;
      std::size_t ext_len = 4;
      for (std::size_t i{}; i<maps.size(); i++) {
          std::size_t name_len = (maps[i].size() - path_len - ext_len);
          std::cout << (i+1) << ". " << maps[i].substr(path_len, name_len) << '\n';
      }

      std::cin >> id_selected;
      // echo selected map
      std::cout << "Map \""
                  << maps[id_selected-1].substr(path_len, (maps[id_selected-1].size() - path_len - ext_len))
                  << "\" selected\n";

      filename = maps[id_selected-1];
  }
  else{
    std::cout << "No Files for maps found\n";
  }

  return filename;
}