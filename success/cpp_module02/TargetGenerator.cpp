#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {}

void TargetGenerator::learnTargetType(ATarget *target)
{
	if (target && targets.find(target->getType()) == targets.end())
	{
		targets[target->getType()] = target->clone();
	}
}

void TargetGenerator::forgetTargetType(std::string const &targetName)
{
	std::map<std::string, ATarget*>::iterator it = targets.find(targetName);
	if (it != targets.end())
	{
		delete it->second;
		targets.erase(it);
	}
}

ATarget *TargetGenerator::createTarget(std::string const &targetName)
{
	std::map<std::string, ATarget*>::iterator it = targets.find(targetName);
	if (it != targets.end())
		return it->second->clone();
	return NULL;
}
