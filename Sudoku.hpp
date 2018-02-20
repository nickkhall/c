#ifndef Sudoku_hpp
#define Sudoku_hpp

#include <stdio.h>
#include <iostream>

class Sudoku
{
private:
    std::string word;

public:
    Sudoku();
    
    std::string GetWord();
};

#endif /* Sudoku_hpp */
