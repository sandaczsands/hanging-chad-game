#pragma once
#include <iostream>
#include <vector>

struct info {
        int length;
        std::string word;
        std::string clue;
};   

class Codeword{
    public:
        std::vector<info> codewords = {
                {4, "blue", "color"},
                {5, "apple", "food"},
                {5, "zebra", "animal"},
                {6, "orange", "color"},
                {7, "python", "programming language"},
                {5, "green", "color"},
                {5, "tiger", "animal"},
                {4, "java", "programming language"},
                {5, "black", "color"},
                {8, "sunflower", "plant"},
                {5, "red", "color"},
                {6, "rabbit", "animal"},
                {4, "ruby", "programming language"},
                {5, "white", "color"},
                {9, "strawberry", "fruit"},
                {6, "violet", "color"},
                {5, "shirt", "clothing"},
                {6, "giraffe", "animal"},
                {7, "yellow", "color"},
                {8, "cardigan", "clothing"},
                {6, "monkey", "animal"},
                {5, "scarf", "clothing"},
                {7, "magenta", "color"},
                {8, "trousers", "clothing"},
                {6, "delphi", "programming language"},
                {4, "rust", "programming language"},
                {10, "javascript", "programming language"},
                {9, "chocolate", "food"},
                {9, "spaghetti", "food"},
                {5, "socks", "clothing"}
            };
            std::string codeword;  
            std::string clue;
            std::string answer;
};