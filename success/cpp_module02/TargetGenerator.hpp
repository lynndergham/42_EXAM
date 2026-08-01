#pragma once
#include <iostream>
#include <map>
#include "ATarget.hpp"

class ATarget;
class TargetGenerator
{
	private:
		std::map<std::string, ATarget*> targets;
	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget *target);
		void forgetTargetType(std::string const &targetName);
		ATarget *createTarget(std::string const &targetName);
};
