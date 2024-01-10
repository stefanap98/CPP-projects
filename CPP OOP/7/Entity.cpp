#include "Entity.h"
#include <iostream>


const bool Entity::isAlive() const
{
	return true;
}

void Entity::setName(std::string _Name)
{
	this->name = _Name;
}

Entity::Entity(std::string _Name, const Point2D& Point)
{
	this->id = getNewId();
	setName(_Name);
	this->location = new Point2D(Point);
}

Entity::Entity(std::string _Name, const Point3D& Point)
{
	this->id = getNewId();
	setName(_Name);
	this->location = new Point3D(Point);
}

int Entity::maxId = 0;

int Entity::getNewId()
{
	return maxId++;
}

const std::string Entity::getName() const
{
	return this->name;
}

const Point2D* Entity::getLocation() const
{
	return this->location;
}


double Entity::getDistanceTo2D(const Entity& Entity) const
{
	return location->getDistanceTo(*(Entity.getLocation()));
}

double Entity::getDistanceTo(const Entity& entity) const
{
	//Point3D const* p = dynamic_cast<Point3D const*>(entity.getLocation());
	//Point3D const* pt = dynamic_cast<Point3D const*>(this->getLocation());
	//
	//if (p != NULL && pt != NULL)
	//{
	//	return pt->getDistanceTo(*p);
	//}
	//return this->getDistanceTo2D(entity);

	if (this->getLocation()->getDim() == 3 && entity.getLocation()->getDim() == 3)
	{
		Point3D* p1 = (Point3D*)this->getLocation();
		Point3D* p2 = (Point3D*)entity.getLocation();
		return p1->getDistanceTo(*p2);
	}
	return this->getDistanceTo2D(entity);
}

void Entity::moveTo(const Point2D* point)
{
	if (point->getDim() == 3 && this->getLocation()->getDim() == 3)
	{
		Point3D* pointCopy = new Point3D(*(Point3D*)point);
		this->location = pointCopy;
	}
	else
	{
		Point2D* pointCopy = new Point2D(*point);
		this->location = pointCopy;
	}
}

void Entity::moveTo(const Entity& entity)
{
	moveTo(entity.getLocation());
}

Entity::~Entity()
{
	delete location;
}