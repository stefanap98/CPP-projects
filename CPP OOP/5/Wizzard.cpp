#include "Wizzard.h"

Wizzard::Wizzard() : GameCharacter("Wizzard", 30, 30, 2, 2)
{}

Wizzard::Wizzard(const Wizzard& g) : GameCharacter(g)
{}

Wizzard& Wizzard::operator=(const Wizzard& g)
{
	if (this != &g)
	{
		GameCharacter::operator=(g);
	}
	return *this;
}

void Wizzard::print() const
{
	GameCharacter::print();
}