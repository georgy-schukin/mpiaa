#include "circle.h"
#include "objects.h"

namespace robopath {

bool Circle::collidesWith(const Point &p) const {
	return p.collidesWith(*this);
}

bool Circle::collidesWith(const LineSegment &ls) const {
	return ls.collidesWith(*this);
}

bool Circle::collidesWith(const Circle &c) const {
 	double distSquared = center.distanceToSquared(c.center);
    double sumRadius = radius + c.radius;
    return distSquared <= sumRadius * sumRadius;
}

bool Circle::collidesWith(const Rectangle &r) const {
	if (center.collidesWith(r)) {
        return true;
    }
    // Check line-circle intersections
    for (const auto &line: r.getLines()) {
        if (collidesWith(line)) {
            return true;
        }
    }
    return false;
}

bool Circle::collidesWith(const Triangle &t) const {
 	// Circle center is in the triangle
    if (center.collidesWith(t)) {
        return true;
    }
    // Triangle's point is in the circle
    for (const auto &point: t.getPoints()) {
        if (collidesWith(point)) {
            return true;
        }
    }
    // Triangle's side crosses the circle
    for (const auto &line: t.getLines()) {
        if (collidesWith(line)) {
            return true;
        }
    }
    return false;	
}

}
