#include <iostream>
#include "Calculator.hpp"

int main()
{
    Calculator * InitCalculator = new Calculator;

    std::cout << "Final Num: " << InitCalculator->GetFinalNum() << std::endl;

    return 0;
}
