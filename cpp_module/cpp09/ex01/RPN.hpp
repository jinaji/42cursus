#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <iostream>
# include <string>

# define PLUS 1
# define MINUS 2
# define MUL 3
# define DIV 4

class RPN
{
    private:
    RPN(const RPN& obj);
    RPN& operator=(const RPN& obj);

    public:
    std::stack<int> _stack;

    RPN();
    ~RPN();

    int     isOperator(char c);
    void    calculate(char *av);
    void    createStack(char *av);

    public:
	class incorrectFormError : public std::exception
	{
		public:
		const char* what() const throw()
		{
			return ("Error");
		}
	};
};

#endif