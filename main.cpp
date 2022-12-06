//Example for evalexpression.h
#include "arithmetic_expression.hpp"
#include <iostream>
#include <cassert>

void tests()
{
    std::string test1 = "2+10";
    assert(expression(test1) == 12);
    std::string test2 = "2*100";
    assert(expression(test2) == 200);
    std::string test3 = "(2+100)*2";
    assert(expression(test3) == 204);
    std::cout << "All tests passed." << std::endl;

}

int main()
{
    //std::string ex = "((2+10)*15)/180(234)";
    //std::cout<<expression(ex)<<std::endl;
    tests();
    return 0;
}
