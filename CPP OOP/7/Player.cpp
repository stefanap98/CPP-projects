#include "Player.h"
#include <iostream>



Player::Player(std::string _Name, const Point2D& _Point, int _Damage, int _Health):Attacker(_Name , _Point, _Damage, _Health)
{
	this->type = Entity::Type::PLAYER;
}

const bool Player::isAlive()const
{
	return (getHealth() > 0);
}

void Player::attack(Attacker& entity)
{
	if (entity.getType() == Entity::Type::PLAYER || entity.getType() == Entity::Type::MOB)
	{
		this->doAttack(entity);
	}
}

const Entity::Type Player::getType() const
{
	return Entity::Type::PLAYER;
}