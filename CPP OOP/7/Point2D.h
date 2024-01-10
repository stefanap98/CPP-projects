#pragma once
#ifndef POINT2D_H
#define POINT2D_H

class Point2D
{
public:
	Point2D(double = 0, double = 0);
	Point2D(const Point2D&);
	const double getX() const;
	const double getY() const;
	void setX(double);
	void setY(double);
	virtual double getDistanceTo(const Point2D&) const;
	virtual const int getDim() const;
private:
	double x, y;
};

#endif // !POINT2D_H
