#include <iostream>

double prefixAndBracket(const char* &expression)
{
    while(isspace(*expression))
        ++expression;

        
    switch(*expression)
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
        return strtod(expression,(char**)&expression);
    case '-':
        return -prefixAndBracket(++expression);
    case '+':
        return prefixAndBracket(++expression);
    case '(':
    {
        double res=additionAndSubtraction(++expression);
        if(*expression++==')')
            return res;
    }
    default:
        throw std::runtime_error("Bad expression");
    }
}

double multiplicationAndDivision(const char *&expression)
{
    double res=prefixAndBracket(expression);
    while(true)
    {
        while(isspace(*expression))
            ++expression;
        switch(*expression)
        {
        case 0:
            return res;
        case '*':
            res*=prefixAndBracket(++expression);
            break;
        case '/':
            res/=prefixAndBracket(++expression);
            break;
        default:
            return res;
        }
    }
}

double additionAndSubtraction(const char *&expression)
{
    double res=multiplicationAndDivision(expression);
    while(true)
    {
        while(isspace(*expression))
            ++expression;
        switch(*expression)
        {
        case 0:
            return res;
        case '+':
            res+=multiplicationAndDivision(++expression);
            break;
        case '-':
            res-=multiplicationAndDivision(++expression);
            break;
        default:
            return res;
        }
    }
}

inline double expression(const char *expression)
{
    const double res=additionAndSubtraction(expression);
    while(isspace(*expression))
        ++expression;
    if(*expression)
        throw std::runtime_error("Bad expression");
    return res;
}
