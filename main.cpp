//Example for evalexpression.h
#include "arithmetic_expression.hpp"
#include <iostream>
#include <cassert>

void tests()
{
    std::string test1 = "2+10";
    assert(expression(test1) == 12);
    std::cout << "1 test passed." << std::endl;

    std::string test2 = "2*100";
    assert(expression(test2) == 200);
    std::cout << "2 test passed." << std::endl;
    
    std::string test3 = "(2+100)*2";
    assert(expression(test3) == 204);
    std::cout << "3 test passed." << std::endl;

    std::string test4 = "((2+10)*15)/180";
    assert(expression(test4) == 1);
    std::cout << "4 test passed." << std::endl;

}

int main()
{
    tests();
    return 0;
}
