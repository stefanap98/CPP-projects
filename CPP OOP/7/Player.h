#pragma once
#include "Attacker.h"
#ifndef PLAYER_H
#define PLAYER_H

class Player : public Attacker
{
public:
	Player(std::string, const Point2D&,int = 0,int = 0);
	virtual const bool isAlive() const;
	virtual void attack(Attacker&);
	virtual const Entity::Type getType() const;
};


#endif // !PLAYER_H
