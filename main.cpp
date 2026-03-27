#include <iostream>
#include "src/utils.hpp"
#include <string>

struct PlayerInfo{
  std::string name;
  int level;
  int maxHP;
};

int main()
{
  PlayerInfo hero;

  hero.name = queryPlayerName();
  hero.level = 1;
  hero.maxHP = 10;
  
  cleanScreen();
  // escapeLine(2);
  printBanner();
  escapeLine(1);
  std::cout << "Greetings, " << hero.name <<", what are the plans today ?";
  escapeLine(2);
  displayMenu();
  getUserChoice(1, 4);
  return 0;
}