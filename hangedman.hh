#pragma once
#include <iostream>
#include <vector>
#include <chrono>

class Codeword;

/*
int greet();
void display_misses(int misses);
void tuning(int level, bool easy);
void choosing_word(bool easy, std::string clue, std::string codeword, std::string answer);
void display_status(std::vector<char> incorrect, std::string answer);
void end(std::string answer, std::string codeword);
*/

int greet();
void display_misses(int misses);
bool tuning(int level);
void choosing_word(bool easy, Codeword &codewordObj);
void display_status(std::vector<char> incorrect, std::string answer);
void gameLoop(Codeword &codewordObj);
void end(std::string answer, std::string codeword);