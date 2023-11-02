#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

class	Harl
{
private:
	std::string	LEVELS[4];
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

public:
	Harl();
	~Harl();
	void	nothing(void);
	void	(Harl::*f[4])(void);
	void	complain(std::string level);
	int		getLevel(std::string level);
};

enum level
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	NOTHING
};

#endif