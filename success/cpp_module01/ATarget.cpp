#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(std::string const &type)
{
	this->type = type;
}

ATarget::~ATarget() {}

std::string ATarget::getType() const
{
	return type;
}

void ATarget::getHitBySpell(ASpell const &spell) const
{
	std::cout << type << " has been " << spell.getEffects() << "!\n";
}
