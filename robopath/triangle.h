#include "point.h"
#include "line_segment.h"

#include <array>

namespace robopath {

class Circle;
class Rectangle;

class Triangle {
public:
	Triangle() {}
	Triangle(const Point &p1, const Point &p2, const Point &p3):
		points({p1, p2, p3}) {			
	}
	Triangle(double p1x, double p1y, double p2x, double p2y, double p3x, double p3y):
		points({Point(p1x, p1y), Point(p2x, p2y), Point(p3x, p3y)}) {			
	}

	const std::array<Point, 3>& getPoints() const {
		return points;
	}
	std::array<LineSegment, 3> getLines() const;

	bool collidesWith(const Point &p) const;
	bool collidesWith(const LineSegment &ls) const;
	bool collidesWith(const Circle &c) const;
	bool collidesWith(const Rectangle &r) const;
	bool collidesWith(const Triangle &t) const;	

public:
	std::array<Point, 3> points;		
};

}
