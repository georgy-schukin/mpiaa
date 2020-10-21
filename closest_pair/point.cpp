#include "point.h"

#include <cmath>

using namespace std;

namespace {
	static const double EPS = 1e-8;

	bool equal(double a, double b) {
		return abs(a - b) < EPS;
	}	
}

double Point::distance(const Point &p) const {
	return sqrt((x - p.x)*(x - p.x) + (y - p.y)*(y - p.y));
}

bool Point::operator==(const Point &p) const {
	return equal(x, p.x) && equal(y, p.y);
}

bool Point::operator!=(const Point &p) const {
	return !equal(x, p.x) || !equal(y, p.y);
}

bool Point::operator<(const Point &p) const {
	return (x < p.x) || (equal(x, p.x) && y < p.y);
}

bool Point::operator<=(const Point &p) const {
	return (x < p.x) || (equal(x, p.x) && ((y < p.y) || equal(y, p.y)));
}

ostream& operator<<(ostream &os, const Point &p) {
	os << "(" << p.x << ", " << p.y << ")";
	return os;
}
