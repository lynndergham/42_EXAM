#pragma once
#include <iostream>
#include <map>
#include "ASpell.hpp"

class ASpell;
class SpellBook
{
	private:
		std::map<std::string, ASpell*> spells;
	public:
		SpellBook();
		~SpellBook();

		void learnSpell(ASpell *spell);
		void forgetSpell(std::string const &spellName);
		ASpell *createSpell(std::string const &spellName);
};
