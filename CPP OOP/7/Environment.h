#pragma once
#include "Entity.h"
#include "NPC.h"
#include "Player.h"
#include "MOB.h"
#include <vector>
#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

class Environment
{
public:
	void add(Entity*);
	const Entity* getAt(const int) const;
	void removeAt(const int);
	Entity* getClosestAliveEntity(const Player&,const Entity::Type) const;

	void generateEntities();
	void destroyEntities();
private:
	std::vector<Entity*> entities;
};


#endif // !ENVIRONMENT_H
