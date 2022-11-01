#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria	*slot[4];
	int			index;
public:
	MateriaSource();
	MateriaSource(const MateriaSource& obj);
	const MateriaSource& operator=(const MateriaSource& obj);
	~MateriaSource();
public:
	void learnMateria(AMateria* obj);
	AMateria* createMateria(std::string const &type);
};

#endif