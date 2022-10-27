#include "Harl.hpp"

Harl::Harl()
{
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
	const std::string	LEVELS[4] = {
		"DEBUG", "INFO", "WARNING", "ERROR"
	};
	for (; i < 4 && level != LEVELS[i]; i++)
		;
	return (i);
}

void	Harl::complain(std::string level)
{
	void	(Harl::*f[5])(void);

	f[0] = &Harl::debug;
	f[1] = &Harl::info;
	f[2] = &Harl::warning;
	f[3] = &Harl::error;
	f[4] = &Harl::nothing;
	if (level == "DEBUG")
		(this->*f[0])();
	else if (level == "INFO")
		(this->*f[1])();
	else if (level == "WARNING")
		(this->*f[2])();
	else if (level == "ERROR")
		(this->*f[3])();
	else if (level == "NOTHING")
		(this->*f[4])();
}

