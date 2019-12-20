#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <limits>
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

      std::cout << "Following maps are available:\n";

      // print names of the maps cutting path and extension off
      // the subset (name length) is dynamically calculated as Name = Entire Length - Path - Extension
      std::size_t path_len = 8;
      std::size_t ext_len = 4;
      for (std::size_t i{}; i<maps.size(); i++) {
          std::size_t name_len = (maps[i].size() - path_len - ext_len);
          std::cout << (i+1) << ". " << maps[i].substr(path_len, name_len) << '\n';
      }

      // get map id number selected by user
      std::cout << "Please select a map by its id:\n";
      int id_selected = get_int_in_range(1, maps.size());

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

// function keeps prompting until int in range is obtained and returns the value
int get_int_in_range(int min_val, int max_val)
{ 
  int value {0};
  while(true){
    std::cin >> value;
      if (value >= min_val && value <= max_val){
        break;
      }
    std::cout << "Wrong input - please enter an integer in the range of [" << min_val << ";" << max_val << "]" << "\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  return value;
}