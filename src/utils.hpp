#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <string>

void escapeLine(int lines);

void cleanScreen();

std::string queryPlayerName();

void printBanner();

void displayMenu();

int getUserChoice(int min, int max);

void messagePlayer(std::string message);

#endif