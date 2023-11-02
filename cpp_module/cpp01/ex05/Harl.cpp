#include "Harl.hpp"

Harl::Harl()
{
	this->LEVELS[0].assign("DEBUG");
	this->LEVELS[1].assign("INFO");
	this->LEVELS[2].assign("WARNING");
	this->LEVELS[3].assign("ERROR");
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacom for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	int		i = 0;
	void	(Harl::*f[4])(void);

	f[0] = &Harl::debug;
	f[1] = &Harl::info;
	f[2] = &Harl::warning;
	f[3] = &Harl::error;

	for (; i < 3 && level != this->LEVELS[i]; i++)
		;
	(this->*f[i])();
}

