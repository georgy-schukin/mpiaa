#include "triangle.h"
#include "objects.h"

namespace robopath {

std::array<LineSegment, 3> Triangle::getLines() const {
	return std::array<LineSegment, 3> {
		LineSegment(points[0], points[1]),
		LineSegment(points[1], points[2]),
		LineSegment(points[2], points[0])
	};
}	

bool Triangle::collidesWith(const Point &p) const {
	return p.collidesWith(*this);
}

bool Triangle::collidesWith(const LineSegment &ls) const {
	return ls.collidesWith(*this);
}

bool Triangle::collidesWith(const Circle &c) const {
	return c.collidesWith(*this);
}

bool Triangle::collidesWith(const Rectangle &r) const {
	for (const auto &point: getPoints()) {
        if (point.collidesWith(r)) {
            return true;
        }
    }
    for (const auto &line: getLines()) {
        if (line.Intersects(r)) {
            return true;
        }
    }
    // Check for rect inside triangle case
    for (const auto &point: r.getPoints()) {
        if (collidesWith(point)) {
            return true;
        }
    }
    return false;
}

bool Triangle::collidesWith(const Triangle &t) const {
	 for (const auto &point: getPoints()) {
        if (point.collidesWith(t)) {
            return true;
        }
    }
    for (const auto &point: t.getPoints()) {
        if (collidesWith(point)) {
            return true;
        }
    }
    for (const auto &line: getLines()) {
        if (line.collidesWith(t)) {
            return true;
        }
    }
    return false;
}

}