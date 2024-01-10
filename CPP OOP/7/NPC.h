#pragma once
#include "Entity.h"
#ifndef NPC_H
#define NPC_H

class NPC : public Entity
{
public:
	NPC(std::string , const Point2D& );
	const bool isAlive() const;
	virtual const Entity::Type getType() const;
};

#endif // !NPC_H
