#include "Point3D.h"
#include <math.h>
#include <iostream>

Point3D::Point3D(double _X, double _Y, double _Z) : Point2D(_X,_Y)
{
	setZ(_Z);
}

Point3D::Point3D(const Point3D& P) : Point2D(P)
{
	setZ(P.z);
}

const double Point3D::getZ() const
{
	return this->z;
}

void Point3D::setZ(double _Z)
{
	this->z = _Z;
}

double Point3D::getDistanceTo(const Point2D& P) const
{
	//std::cout << "{3d - 2d}" << std::endl;
	return Point2D::getDistanceTo(P);
}

double Point3D::getDistanceTo(const Point3D& P) const
{
	//std::cout << "{3d - 3d}" << std::endl;
	return sqrt(pow(this->getX() - P.getX(), 2) +
		pow(this->getY() - P.getY(), 2) +
		pow(this->getZ() - P.getZ(), 2) );
}

const int Point3D::getDim() const
{
	return 3;
}