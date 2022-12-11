#pragma once

#include "point.h"

namespace robopath {

class LineSegment;
class Rectangle;
class Triangle;	

class Circle {
public:
	Circle() {}
	Circle(const Point &center, double radius): 
		center(center), radius(radius) {			
	}
	Circle(double x, double y, double radius):
		center(x, y), radius(radius) {			
	}

	bool collidesWith(const Point &p) const;
	bool collidesWith(const LineSegment &ls) const;
	bool collidesWith(const Circle &c) const;
	bool collidesWith(const Rectangle &r) const;
	bool collidesWith(const Triangle &t) const;	
	
public:
	Point center;
	double radius;
};

}
