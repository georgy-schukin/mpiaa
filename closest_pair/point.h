#pragma once

#include <ostream>

class Point {
public:
	Point() {}
	Point(int xx, int yy) : x(xx), y(yy) {}

	double distanceTo(const Point &p) const;

	bool operator==(const Point &p) const;
	bool operator!=(const Point &p) const;
	bool operator<(const Point &p) const;
	bool operator<=(const Point &p) const;

public:
	int x {0};
	int y {0};
};

std::ostream& operator<<(std::ostream &os, const Point &p);