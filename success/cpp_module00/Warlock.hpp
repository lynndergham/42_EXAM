#pragma once
#include <iostream>

class Warlock
{
	private:
		std::string name;
		std::string title;
	public:
		Warlock();
		Warlock(std::string const &name, std::string const &title);
		~Warlock();
		std::string getName() const;
		std::string getTitle() const;
		void setTitle(std::string const &title);
		void introduce() const;
};
