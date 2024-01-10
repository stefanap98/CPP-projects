#include "Point2D.h"
#include <math.h>
#include <iostream>

Point2D::Point2D(double _X, double _Y)
{
	setX(_X);
	setY(_Y);
}

Point2D::Point2D(const Point2D& P)
{
	setX(P.x);
	setY(P.y);
}

const double Point2D::getX() const
{
	return this->x;
}

const double Point2D::getY() const
{
	return this->y;
}

void Point2D::setX(double _X)
{
	this->x = _X;
}

void Point2D::setY(double _Y)
{
	this->y = _Y;
}

double Point2D::getDistanceTo(const Point2D& P) const
{
	//std::cout << "{2d - 2d}" << std::endl;
	return sqrt(pow(this->getX() - P.getX(), 2) 
		+ pow(this->getY() - P.getY(), 2));
}

const int Point2D::getDim() const
{
	return 2;
}
