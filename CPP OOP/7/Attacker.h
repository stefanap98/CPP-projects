#pragma once
#include "Entity.h"
#ifndef ATTACKER_H
#define ATTACKER_H

class Attacker : public Entity
{
protected:
	int health;
	int damage;

	void doAttack(Attacker&);

public:
	Attacker(std::string, const Point2D&, int _Damage, int _Health);

	virtual void attack(Attacker&) = 0;

	const int getHealth() const;
	void setHealth(const int);
	const int getDamage() const;
	void setDamage(const int);

	virtual const Entity::Type getType() const = 0;
};

#endif // !ATTACKER_H
