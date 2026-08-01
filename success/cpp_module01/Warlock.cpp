#include "Warlock.hpp"

Warlock::Warlock() {}

Warlock::Warlock(std::string const &name, std::string const &title)
{
	this->name = name;
	this->title = title;
	std::cout << name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
	std::cout << name << ": My job here is done!\n";
}

std::string Warlock::getName() const
{
	return name;
}

std::string Warlock::getTitle() const
{
	return title;
}

void Warlock::setTitle(std::string const &title)
{
	this->title = title;
}

void Warlock::introduce() const
{
	std::cout << name << ": I am " << name << ", " << title << "!\n";
}

void Warlock::learnSpell(ASpell *spell)
{
	if (spell)
	{
		spells[spell->getName()] = spell->clone();
	}
}

void Warlock::forgetSpell(std::string const &spellName)
{
	std::map<std::string, ASpell*>::iterator it = spells.find(spellName);
	if (it != spells.end())
	{
		delete it->second;
		spells.erase(it);
	}
}

void Warlock::launchSpell(std::string const &spellName, ATarget const &target)
{
	std::map<std::string, ASpell*>::iterator it = spells.find(spellName);
	if (it != spells.end())
	{
		it->second->launch(target);
	}
}
