#include "Warrior.h"

Warrior::Warrior() : GameCharacter("Warrior", 20, 5, 4, 1)
{}

Warrior::Warrior(const Warrior& g) : GameCharacter(g)
{}

Warrior& Warrior::operator=(const Warrior& g)
{
	if (this != &g)
	{
		GameCharacter::operator=(g);
	}
	return *this;
}

void Warrior::print() const
{
	GameCharacter::print();
}