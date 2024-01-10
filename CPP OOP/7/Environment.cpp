#include "Environment.h"
#include <float.h>

void Environment::add(Entity* entity)
{
	entities.push_back(entity);
}

const Entity* Environment::getAt(const int index) const
{
	return entities[index];
}

void Environment::removeAt(const int index)
{
	entities.erase(entities.begin() + index);
}

Entity* Environment::getClosestAliveEntity(const Player& player, const Entity::Type type) const
{
	Entity* result = NULL;
	double minDistance = DBL_MAX;
	for (std::vector<Entity*>::const_iterator it = entities.begin(); it != entities.end(); ++it)
	{
		if ((*it)->isAlive() && (*it)->getType() == type && *it != &((Entity&)player))
		{
			if (minDistance > (*it)->getDistanceTo(player))
			{
				result = *it;
				minDistance = (*it)->getDistanceTo(player);
			}
		}
	}
	return result;
}

void Environment::generateEntities()
{
	Point3D point1(1,2,3);
	NPC npc("npc1", point1);
	Entity* ent = &npc;
	add(ent);

	Point3D point2(5, 2, 3);
	Mob mob1("Mob1",point2, 10, 50);
	ent = &mob1;
	add(ent);
	Point3D point3(6, 1, 6);
	Mob mob2("Mob2", point3, 15, 50);
	ent = &mob2;
	add(ent);
	Point3D point4(1, 1, 2);
	Mob mob3("Mob3", point4, 12, 50);
	ent = &mob3;
	add(ent);
}
void Environment::destroyEntities()
{
	entities.clear();
}