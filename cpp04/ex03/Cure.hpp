#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
private:
	
public:
	Cure();
	Cure(const Cure& obj);
	const Cure& operator=(const Cure& obj);
	~Cure();

	public:
	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif