#pragma once

#include "point.h"
#include "interval.h"
#include "line_segment.h"

#include <array>

namespace robopath {

class LineSegment;
class Circle;
class Triangle;

class Rectangle {
public:
	Rectangle() {}
	Rectangle(const Point &topLeft, double width, double height):
		topLeft(topLeft), width(width), height(height) {		
	}
	Rectangle(double tlx, double tly, double width, double height):
		topLeft(tlx, tly), width(width), height(height) {
	}

	Interval getXInterval() const;
	Interval getYInterval() const;

	std::array<Point, 4> getPoints() const;
	std::array<LineSegment, 4> getLines() const;

	static Rectangle atCenter(const Point &center, double width, double height);	
	static Rectangle atCenter(double cx, double cy, double width, double height);	
	static Rectangle atBottomLeft(const Point &bottomLeft, double width, double height);	
	static Rectangle atBottomLeft(double blx, double bly, double width, double height);	
	static Rectangle betweenPoints(const Point &topLeft, const Point &bottomRight);	
	static Rectangle betweenPoints(double tlx, double tly, double brx, double bry);	

	bool collidesWith(const Point &p) const;
	bool collidesWith(const LineSegment &ls) const;
	bool collidesWith(const Circle &c) const;
	bool collidesWith(const Rectangle &r) const;
	bool collidesWith(const Triangle &t) const;

public:
	Point topLeft;	
	double width;
	double height;
};

}
