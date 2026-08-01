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
		spellBook.learnSpell(spell);
	}
}

void Warlock::forgetSpell(std::string const &spellName)
{
	spellBook.forgetSpell(spellName);
}

void Warlock::launchSpell(std::string const &spellName, ATarget const &target)
{
	ASpell *spell = spellBook.createSpell(spellName);
	if (spell)
	{
		spell->launch(target);
		delete spell;
	}
}
