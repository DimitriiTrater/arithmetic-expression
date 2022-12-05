//Example for evalexpression.h
#include "arithmetic_expression.hpp"
#include <iostream>

int main()
{
    std::string ex = "(2+2)*5";
    std::cout<<expression(ex)<<std::endl;
    return 0;
}
