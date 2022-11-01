#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
private:
	
public:
	Ice();
	Ice(const Ice& obj);
	const Ice& operator=(const Ice& obj);
	~Ice();

	public:
	AMateria* clone() const;
};

#endif