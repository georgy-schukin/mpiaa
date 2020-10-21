#pragma once

#include <ostream>

class Point {
public:
	Point() {}
	Point(double xx, double yy) : x(xx), y(yy) {}

	double distance(const Point &p) const;

	bool operator==(const Point &p) const;
	bool operator!=(const Point &p) const;
	bool operator<(const Point &p) const;
	bool operator<=(const Point &p) const;

public:
	double x {0.0};
	double y {0.0};
};

std::ostream& operator<<(std::ostream &os, const Point &p);