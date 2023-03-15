#ifndef SPELLBOOK_HPP
# define SPEELBOOK_HPP

# include <string>
# include <vector>

class SpellBook {
private:
    std::vector<ASpell*> _spell;

public:
    void learnSpell(std::string name);
    void forgetSpell(std::string name);
    void createSpell(std::string name);
};

void learnSpell(std::string name)
{
    std::vector<ASpell*>::iterator it = _spell.begin();

    for (size_t i = 0; i < _spell.size(); i++, it++)
    {
        if (it.getName() == name)
        {
            _spell.push_back((*it).clone());
            return ;
        }
    }
}

void forgetSpell(std::string name)
{
    std::vector<ASpell*>::iterator it = _spell.begin();

    for (std::vector<ASpell*>::iterator it = _spell.begin(); it != _spell.end(); it++)
    {
        if (it.getName() == name)
        {
            delete(*it);
            _spell.erase(it);
            return ;
        }
    }
}

#endif