#include <iostream>
#include "Sudoku.hpp"

int main()
{
    Sudoku * testSudoku = new Sudoku;
    std::cout << testSudoku->GetWord() << std::endl;
    return 0;
}
