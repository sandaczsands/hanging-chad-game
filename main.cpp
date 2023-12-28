#include <iostream>
#include <vector>
#include <windows.h>
#include <ctime>
#include <chrono>
#include "hangedman.hh"
#include "codewords.hh"

int main(){

    int level = greet();
    Codeword codewordObj; 
    bool easy = tuning(level);
    choosing_word(easy, codewordObj);
    gameLoop(codewordObj);

    return 0;
}