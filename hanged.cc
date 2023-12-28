#include <iostream>
#include <windows.h> 
#include <ctime>
#include <chrono>
#include <vector>
#include <algorithm>
#include "hangedman.hh"
#include "codewords.hh"

int greet(){
    std::cout <<"<><><><><><><><><><><><><><>"<< std::endl;
    std::cout <<"Hanging Man the Game"<< std::endl;
    std::cout <<"<><><><><><><><><><><><><><>"<< std::endl << std::endl;

    std::cout <<"Greetings! To begin choose your level of difficulty: "<< std::endl << std::endl;
    int level;
    std::cout <<"Level 1, word with five letters or below, clue given from start,  5 allowed misses."<< std::endl;
    std::cout <<"Level 2, word with six letters or above, clue given on fifth miss,  5 allowed misses."<< std::endl;
    std::cout <<"Level 3, word with six letters or above, clue given on fifth miss,  5 allowed misses."<< std::endl << std::endl;
    std::cout <<"Your chosen level of difficulty: ";
    std::cin >> level;
    return level;
}

bool tuning(int level){
    bool easy;
    switch(level){
        case 1:
            easy = true;
            
            break;
        case 2:
            easy = false;
            
            break;
        case 3:
            easy = false;
      
            break;
    }
    return easy;
}

void choosing_word(bool easy, Codeword &codewordObj){
    srand(time(0));
    int choice;
    
    while(1){
      choice = std::rand()%20;
      codewordObj.codeword = codewordObj.codewords[choice].word;
      codewordObj.clue = codewordObj.codewords[choice].clue;

      if (easy){
            if (codewordObj.codewords[choice].length <= 5){
                break;
            } else {
                continue;
            }
        } else {
            if (codewordObj.codewords[choice].length >= 6){
                break;
            } else {
                continue;
            }
        }
    }
    if (easy){
        std::cout << std::endl;
        std::cout << "Here is your clue: " << std::endl;
        std::cout << codewordObj.clue << std::endl;
        std::cout << std::endl;
    }
         
    codewordObj.answer = "";
    for (int i = 0; i < codewordObj.codeword.length(); i++){
        codewordObj.answer += "_";
    }
}

void display_misses(int misses){
    switch(misses){
        case 0:
            std::cout<<"  +---+"<<std::endl;
            std::cout<<"  |   |"<<std::endl;
            std::cout<<"      |"<<std::endl;
            std::cout<<"      |"<<std::endl;
            std::cout<<"      |"<<std::endl;
            std::cout<<"      |"<<std::endl;
            std::cout<<"======="<<std::endl;
            break;
        case 1:
            std::cout<<"  +---+"<<std::endl;
            std::cout<<"  |   |"<<std::endl;
            std::cout<<"  O   |"<<std::endl;
            std::cout<<"      |"<<std::endl;
            std::cout<<"      |"<<std::endl;
            std::cout<<"      |"<<std::endl;
            std::cout<<"======="<<std::endl;
            break;
        case 2:
            std::cout<<"  +---+"<<std::endl;
            std::cout<<"  |   |"<<std::endl;
            std::cout<<"  O   |"<<std::endl;
            std::cout<<"  |   |"<<std::endl;
            std::cout<<"      |"<<std::endl;
            std::cout<<"      |"<<std::endl;
            std::cout<<"======="<<std::endl;
            break;
        case 3:
            std::cout<<"  +---+"<<std::endl;
            std::cout<<"  |   |"<<std::endl;
            std::cout<<"  O   |"<<std::endl;
            std::cout<<" /|   |"<<std::endl;
            std::cout<<"      |"<<std::endl;
            std::cout<<"      |"<<std::endl;
            std::cout<<"======="<<std::endl;
            break;
        case 4:
            std::cout<<"  +---+"<<std::endl;
            std::cout<<"  |   |"<<std::endl;
            std::cout<<"  O   |"<<std::endl;
            std::cout<<" /|\\  |"<<std::endl;
            std::cout<<"      |"<<std::endl;
            std::cout<<"      |"<<std::endl;
            std::cout<<"======="<<std::endl;
            break;
        case 5:
            std::cout<<"  +---+"<<std::endl;
            std::cout<<"  |   |"<<std::endl;
            std::cout<<"  O   |"<<std::endl;
            std::cout<<" /|\\  |"<<std::endl;
            std::cout<<" /    |"<<std::endl;
            std::cout<<"      |"<<std::endl;
            std::cout<<"======="<<std::endl;
            break;
        case 6:
        std::cout<<"  +---+"<<std::endl;
        std::cout<<"  |   |"<<std::endl;
        std::cout<<"  O   |"<<std::endl;
        std::cout<<" /|\\  |"<<std::endl;
        std::cout<<" / \\  |"<<std::endl;
        std::cout<<"      |"<<std::endl;
        std::cout<<"======="<<std::endl;
            break;
    }
}

void display_status(std::vector<char> incorrect, std::string answer){
    std::cout<< "<><><><><><><><><><><><><><>" << std::endl;
    std::cout<<"Incorrect guesses: ";
    for(int i = 0; i < incorrect.size(); i++){
        std::cout<< incorrect[i]<< " ";
    }
    std::cout<< std::endl <<"Codeword:"<<std::endl;
    for(int i = 0; i < answer.size(); i++){
        std::cout << answer[i];
    }
    std::cout<< std::endl;
    std::cout<< std::endl;
    
}

void gameLoop(Codeword &codewordObj) {
    int misses = 0;
    std::vector<char> incorrect;
    bool guess = false;
    char letter;

    while (misses < 6 && codewordObj.answer != codewordObj.codeword) {
        if (misses == 5) {
            std::cout << std::endl;
            std::cout << "Last chance! Clue for your word is: " << std::endl;
            std::cout << codewordObj.clue << std::endl;
            std::cout << std::endl;
        }
        display_misses(misses);
        display_status(incorrect, codewordObj.answer);
        std::cout << "<><><><><><><><><><><><><><>" << std::endl;
        std::cout << "Enter your guess: ";
        std::cin >> letter;
        std::cout << "<><><><><><><><><><><><><><>" << std::endl;

        for (int i = 0; i < codewordObj.codeword.length(); i++) {
            if (letter == codewordObj.codeword[i]) {
                codewordObj.answer[i] = letter;
                guess = true;
            }
        }
        if (guess) {
            std::cout << std::endl << "Correct!" << std::endl;
        } else if( std::count(incorrect.begin(), incorrect.end(), letter) != 0){
            std::cout << std::endl << "You've already tried this letter, try picking something else!" << std::endl;
        } else {
            std::cout << std::endl << "Incorrect!" << std::endl;
            incorrect.push_back(letter);
            misses++;
            if (misses != 6) {
                std::cout << "Watch out! You have only " << 6 - misses << " guesses left!" << std::endl;
                std::cout << "<><><><><><><><><><><><><><>" << std::endl;
            } else {
                display_misses(6);
            }
        }
        guess = false;
    }
    end(codewordObj.answer, codewordObj.codeword);
}

void end(std::string answer, std::string codeword){
    if(answer == codeword){
        std::cout << "The codeword was: " << codeword << std::endl;
        std::cout << "You've won! Great job!" << std::endl << std::endl;
    } else {
        std::cout << "Oh no! It's too late..." << std::endl;
        std::cout << "The correct codeword was: " << codeword  << std::endl << std::endl;
    }
}


