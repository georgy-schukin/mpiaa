#include "point.h"
#include "objects.h"
#include "util.h"

#include <cmath>

namespace robopath {

double Point::distanceTo(const Point &p) const {
	return std::sqrt(distanceToSquared(p));
}

double Point::distanceToSquared(const Point &p) const {
	return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
}

bool Point::collidesWith(const Point &p) const {
	return areEqual(x, p.x) && areEqual(y, p.y);

}

bool Point::collidesWith(const LineSegment &ls) const {
	const auto &A = ls.start;
    const auto &B = ls.end;

    const auto cross = Vector::cross(A, B, A, *this); // AB cross AP

    // Check cross product for zero
    if (!isZero(cross)) {
        return false;
    }

    const auto dot = Vector::dot(A, B, A, *this); // AB dot AP
    if (dot < 0.0) {
        return false;
    }

    const auto length = Vector::dot(A, B, A, B); // AB dot AB
    return (dot <= length);
}

bool Point::collidesWith(const Circle &c) const {
 	const auto distSquared = distanceToSquared(c.center);
    return (distSquared <= c.radius * c.radius);
}

bool Point::collidesWith(const Rectangle &r) const {
	return r.getXInterval().Includes(x) && 
			r.getYInterval().Includes(y);
}

bool Point::collidesWith(const Triangle &t) const {
	const auto points = t.getPoints();
	const auto &A = points[0];
    const auto &B = points[1];
    const auto &C = points[2];

    const auto s1 = Vector::cross(A, B, A, *this); // AB cross AP
    const auto s2 = Vector::cross(B, C, B, *this); // BC cross BP
    const auto s3 = Vector::cross(C, A, C, *this); // CA cross CP

    bool pos = (s1 >= 0.0 && s2 >= 0.0 && s3 >= 0.0);
    bool neg = (s1 <= 0.0 && s2 <= 0.0 && s3 <= 0.0);
    return pos || neg;
}

}
