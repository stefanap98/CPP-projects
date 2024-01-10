#include "MOB.h"
#include <iostream>


Mob::Mob(std::string _Name, const Point2D& _Point, int _Damage, int _Health) :Attacker(_Name, _Point, _Damage,_Health)
{
	this->type = Entity::Type::MOB;
	setDamage(_Damage);
	setHealth(_Health);
}

const bool Mob::isAlive()const
{
	return (getHealth() > 0);
}

void Mob::attack(Attacker& entity)
{
	if (entity.getType() == Entity::Type::PLAYER)
	{
		this->doAttack(entity);
	}
}

const Entity::Type Mob::getType() const
{
	return Entity::Type::MOB;
}