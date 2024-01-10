#pragma once
#include "Point3D.h"
#ifndef ENTITY_H
#define ENTITY_H
#include <string>

class Entity
{
public:
	enum Type
	{
		PLAYER,
		NPC,
		MOB
	};
	virtual const bool isAlive() const;
	void setName(std::string);
	Entity(std::string, const Point2D&);
	Entity(std::string, const Point3D&);

	double  getDistanceTo2D(const Entity&) const; 
	double  getDistanceTo(const Entity&) const; 

	void moveTo(const Point2D*);
	void moveTo(const Entity&);
	
	const std::string getName() const;
	const Point2D* getLocation() const;
	virtual const Entity::Type getType() const = 0;

	~Entity();

protected:
	int id;
	std::string name;
	Point2D *location;

	Entity::Type type;

	static int maxId;
	static int getNewId();
};


#endif // !ENTITY_H
