#pragma once

namespace robopath {

class LineSegment;
class Circle;
class Rectangle;
class Triangle;

class Point {
public:
	Point() {}
	Point(double x, double y):
		x(x), y(y) {			
	}	

	double distanceTo(const Point &p) const;
	double distanceToSquared(const Point &p) const;

	bool collidesWith(const Point &p) const;
	bool collidesWith(const LineSegment &ls) const;
	bool collidesWith(const Circle &c) const;
	bool collidesWith(const Rectangle &r) const;
	bool collidesWith(const Triangle &t) const;

public:
	double x = 0.0, y = 0.0;
};

}
