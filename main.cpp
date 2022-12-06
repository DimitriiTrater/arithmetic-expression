//Example for evalexpression.h
#include "arithmetic_expression.hpp"
#include <iostream>

int main()
{
    std::string ex = "((2+10)*15)/180(234)";
    std::cout<<expression(ex)<<std::endl;
    return 0;
}
