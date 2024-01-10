#pragma once
#include "Point2D.h"
#ifndef POINT3D_H
#define POINT3D_H

class Point3D : public Point2D
{
public:
	Point3D(double = 0, double = 0,double = 0);
	Point3D(const Point3D&);
	const double getZ() const;
	void setZ(double);
	virtual double getDistanceTo(const Point2D&) const;
	double getDistanceTo(const Point3D&) const;
	virtual const int getDim() const;
private:
	double z;
};

#endif // !POINT3D_H