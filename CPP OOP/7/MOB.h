#pragma once
#include "Attacker.h"
#ifndef MOB_H
#define MOB_H

class Mob : public Attacker
{
public:
	Mob(std::string, const Point2D&, int = 0, int = 0);
	virtual const bool isAlive() const;
	virtual void attack(Attacker&);
	virtual const Entity::Type getType() const;
};


#endif // !MOB_H
