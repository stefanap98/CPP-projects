#include "NPC.h"

NPC::NPC(std::string _Name, const Point2D& _Point) : Entity(_Name, _Point)
{
	this->type = Entity::Type::NPC;
}

const bool NPC::isAlive() const
{
	return true;
}

const Entity::Type NPC::getType() const
{
	return Entity::Type::NPC;
}