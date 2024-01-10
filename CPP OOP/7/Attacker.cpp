#include "Attacker.h"
#include <iostream>
#include <algorithm>

Attacker::Attacker(std::string _Name, const Point2D& _Point, int _Damage, int _Health) : Entity(_Name, _Point)
{
	setDamage(_Damage);
	setHealth(_Health);
}

const int Attacker::getDamage()const
{
	return this->damage;
}

const int Attacker::getHealth()const
{
	return this->health;
}

void Attacker::setDamage(const int _Damage)
{
	this->damage = _Damage;
}

void Attacker::setHealth(const int _Health)
{
	this->health = _Health;
}

void Attacker::doAttack(Attacker& entity)
{
	if (entity.isAlive())
	{
		double dist = getDistanceTo(entity);
		if (dist < 5)
		{
			int newHealth = entity.getHealth() - this->getDamage();
			entity.setHealth(std::max(0, newHealth));
		}
		else
		{
			std::cout << "Enemy too far to damage!" << std::endl;
		}
	}
	else
	{
		std::cout << "Entity is dead" << std::endl;
	}
}