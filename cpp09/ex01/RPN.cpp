#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

int RPN::isOperator(char c)
{
    if (c == '+')
        return PLUS;
    else if (c == '-')
        return MINUS;
    else if (c == '*')
        return MUL;
    else if (c == '/')
        return DIV;
    else
        return 0;
}

void RPN::calculate(char *av)
{
    std::string input = static_cast<std::string>(av);

    for (size_t i = 0; i < input.size(); i++)
    {
        if (isdigit(input[i]) == true)
            _stack.push(input[i] - 48);
        else if (input[i] == ' ')
            continue ;
        else
        {
            int __oper = isOperator(input[i]);
            if (__oper == 0)
                throw (incorrectFormError());
            int num2 = _stack.top();
            _stack.pop();
            int num1 = _stack.top();
            _stack.pop();
            switch (__oper)
            {
                case PLUS :
                {
                    _stack.push(num1 + num2);
                    break;                
                }     
                case MINUS :
                {
                    _stack.push(num1 - num2);
                    break;
                }     
                case MUL :
                {
                    _stack.push(num1 * num2);
                    break;
                }     
                case DIV :
                {
                    _stack.push(num1 / num2);
                    break;
                }     
            }
        }
    }
}
