#pragma once

#include <iostream>

double prefixAndBracket(std::string &expression);
double multiplicationAndDivision(std::string &expression);
double additionAndSubtraction(std::string &expression);
double expression(std::string &expression);

double multiplicationAndDivision(std::string &expression)
{
    double result = prefixAndBracket(expression);
    
    while(true)
    {

        while(isspace(expression[0]))
            expression.erase(0, 1);

        switch(expression[0])
        {
            case 0:
                return result;

            case '*':
                expression.erase(0, 1);
                result *= prefixAndBracket(expression);
                break;
            
            case '/':
                expression.erase(0, 1);
                result /= prefixAndBracket(expression);
                break;
            
            default:
                return result;
        }
    }
}


double additionAndSubtraction(std::string &expression)
{
    double result = multiplicationAndDivision(expression);
    while(true)
    {
        while(isspace(expression[0]))
            expression.erase(0, 1);
            

        switch(expression[0])
        {
            case 0:
                return result;
            case '+':
                expression.erase(0,1);
                result += multiplicationAndDivision(expression);
                break;
            case '-':
                expression.erase(0, 1);
                result -= multiplicationAndDivision(expression);
                break;
            default:
                return result;
        }
    }
}


double prefixAndBracket(std::string &expression)
{
    while(isspace(expression[0]))
        expression.erase(0, 1);

    char l = expression[0];    
    switch(expression[0])
    {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            expression.erase(0, 1);
            return (l-'0');
        
        case '-':
            expression.erase(0, 1);
            return -prefixAndBracket(expression);
        
        case '+':
            expression.erase(0, 1);
            return prefixAndBracket(expression);
        
        case '(':
        {
            expression.erase(0, 1);
            double result = additionAndSubtraction(expression);
            if(expression[0] ==')')
                expression.erase(0, 1);
                return result;
        }
        default:
            throw std::runtime_error("Bad expression");
    }
}

double expression(std::string &expression)
{
    const double result = additionAndSubtraction(expression);
    
    while(isspace(expression[0]))
        expression.erase(0, 1);
    
    return result;
}