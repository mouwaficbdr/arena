#include <iostream>
#include <string>
#include "constants.hpp"


void escapeLine(int lines)
{
  if (lines <= 0)
    return;

  for (int i = 0; i < lines; i++)
  {
    std::cout << "\n";
  }
}

void messagePlayer(std::string message)
{
  escapeLine(1);
  std::cout << "> " << message;
  escapeLine(1);
}

void cleanScreen()
{
  // \033[2J : Cleans screen
  // \033[H  : Brings the cursor top left
  std::cout << "\033[2J\033[H";
}

void printBanner()
{
  std::cout << R"( ██████╗  ██████╗  ███████╗ ███╗   ██╗  ██████╗ 
 ██╔══██╗ ██╔══██╗ ██╔════╝ ████╗  ██║ ██╔══██╗
 ███████║ ██████╔╝ █████╗   ██╔██╗ ██║ ███████║
 ██╔══██║ ██╔══██╗ ██╔══╝   ██║╚██╗██║ ██╔══██║
 ██║  ██║ ██║  ██║ ███████╗ ██║ ╚████║ ██║  ██║
 ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚══════╝ ╚═╝  ╚═══╝ ╚═╝  ╚═╝

      [ Enter the Arena. Survive or fall. ]
)" << std::endl;
}

std::string queryPlayerName()
{
  std::string playerName;

  do{
    messagePlayer("Welcome to ARENA, brave man/woman. What's your name ?");
    std::cin >> playerName;

    if (playerName.length() > GameConfig::nameMaxLength){
      std::string msg = "> Your glorious name must be " + std::to_string(GameConfig::nameMaxLength) + " characters maximum.";
      messagePlayer(msg);
    }
    else if (playerName.empty())
    {
      std::cout << "> All legends starts with a name. Please pick one.\n";
    }

  }while(playerName.length() > GameConfig::nameMaxLength || playerName.empty());

  return playerName;
}

void displayMenu()
{
  std::cout << "=== MENU ===\n";
  std::cout << "[1] New Game\n";
  std::cout << "[2] Load Game\n";
  std::cout << "[3] Exit\n";
}

int getUserChoice(int min, int max)
{
  int choice;
  std::cin >> choice;

  while (choice < min || choice > max)
  {
    std::cout << "Invalid choice, the ARENA rules are strict.";
    escapeLine(2);
    displayMenu();
    escapeLine(1);
    std::cin >> choice;
  }

  return choice;
}