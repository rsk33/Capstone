#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "game_map.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  // prompt user to select a map


  // load a map
  // GameMap game_map("./maps/corner.txt", kGridWidth, kGridHeight);
  // game_map.show();

  // std::cout << "map element[y=3][x=3] " << game_map.pixel(3,4) << std::endl;
  // std::cout << "map element[y=9][x=9] " << game_map.pixel(9,9) << std::endl;

  std::string filename = select_map();

  std:: cout << "Selected Map: " << filename << '\n';

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight, filename);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}