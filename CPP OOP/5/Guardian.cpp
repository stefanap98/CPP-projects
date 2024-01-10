#include "Guardian.h"

Guardian::Guardian() : GameCharacter("Guardian",40,25,1,3)
{}

Guardian::Guardian(const Guardian& g) : GameCharacter(g)
{}

Guardian& Guardian::operator=(const Guardian& g)
{
	if (this != &g)
	{
		GameCharacter::operator=(g);
	}
	return *this;
}

void Guardian::print() const
{
	GameCharacter::print();
}