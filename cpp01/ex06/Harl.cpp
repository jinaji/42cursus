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
	std::cout << "[ DEBUG ]\nI love having extra bacom for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!\n" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month.\n" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void	Harl::nothing(void)
{
	std::cout << "[ Probably complaing insignificant problems ]" << std::endl; 
}

int	Harl::getLevel(std::string level)
{
	int	i = 0;

	for (; i < 4 && level != this->LEVELS[i]; i++)
		;
	return (i);
}

void	Harl::complain(std::string level)
{
	int		i = 0;
	void	(Harl::*f[5])(void);

	f[0] = &Harl::debug;
	f[1] = &Harl::info;
	f[2] = &Harl::warning;
	f[3] = &Harl::error;
	f[4] = &Harl::nothing;

	for (; i < 4 && level != this->LEVELS[i]; i++)
		;
	(this->*f[i])();
}
