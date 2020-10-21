#include "point.h"

#include <cmath>

using namespace std;

double Point::distanceTo(const Point &p) const {
	return sqrt((x - p.x)*(x - p.x) + (y - p.y)*(y - p.y));
}

bool Point::operator==(const Point &p) const {
	return (x == p.x) && (y == p.y);
}

bool Point::operator!=(const Point &p) const {
	return (x != p.x) || (y != p.y);
}

bool Point::operator<(const Point &p) const {
	return (x < p.x) || (x == p.x && y < p.y);
}

bool Point::operator<=(const Point &p) const {
	return (x <= p.x) || (x == p.x && y <= p.y);
}

ostream& operator<<(ostream &os, const Point &p) {
	os << "(" << p.x << ", " << p.y << ")";
	return os;
}
