#include <iostream>
#include "world.h"
void World::printlvl(int personX, int personY) {
  for(int y = 0; y < BOARDSIZE; y++) {
    for(int x = 0; x < BOARDSIZE; x++) {
      if(x == personX && y == personY) {
        std::cout << " X ";
        continue;
      }
      switch(this->map[y][x]){
        case 0:
          std::cout << "   ";
          break;
        case 1: // wall
        case 6: // hidden path
        case 7: // hidden coffee
        case 8: // hidden money
        case 9: // hidden shit
          std::cout << "###";
          break;
        case 2: // door
          std::cout << "[ ]";
          break;
        case 3: // coffee
          std::cout << " C ";
          break;
        case 4: // money
          std::cout << " $ ";
          break;
        case 5: // shit
          std::cout << " s ";
          break;
        default:
          std::cout << this->map[x][y];
          break; 
      }
    }
    std::cout << std::endl;
  }
}
int World::evalPos(int x, int y) {
  return this->map[y][x];
}

int World::changeWorld(int lvl) {
  switch(lvl) {
    case 0:
      for(int x = 0; x < BOARDSIZE; x++) {
        for(int y = 0; y < BOARDSIZE; y++) {
          this->map[y][x] = this->lvlone[y][x];
        }
      }
      this->currentLvl = 0;
      return 0;
    case 1:
      for(int x = 0; x < BOARDSIZE; x++) {
        for(int y = 0; y < BOARDSIZE; y++) {
          this->map[y][x] = this->lvltwo[y][x];
        }
      }
      this->currentLvl = 1;
      return 1;
    case 2:
      for(int x = 0; x < BOARDSIZE; x++) {
        for(int y = 0; y < BOARDSIZE; y++) {
          this->map[y][x] = this->lvlthree[y][x];
        }
      }
      this->currentLvl = 2;
      return 1;
    default:
      return -1;
  }
}
int World::getCurrentLvl() {
  return this->currentLvl;
}

World::World() {
  for(int x = 0; x < BOARDSIZE; x++) {
    for(int y = 0; y < BOARDSIZE; y++) {
      this->map[y][x] = this->lvlone[y][x];
    }
  }
  this->currentLvl = 0;
}