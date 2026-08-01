#pragma once
#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class ASpell;
class Warlock
{
	private:
		std::string name;
		std::string title;
		std::map<std::string, ASpell*> spells;
	public:
		Warlock();
		Warlock(std::string const &name, std::string const &title);
		~Warlock();
		std::string getName() const;
		std::string getTitle() const;
		void setTitle(std::string const &title);
		void introduce() const;

		void learnSpell(ASpell *spell);
		void forgetSpell(std::string const &spellName);
		void launchSpell(std::string const &spellName, ATarget const &target);
};
