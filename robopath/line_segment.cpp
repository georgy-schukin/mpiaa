#include "line_segment.h"
#include "objects.h"
#include "util.h"

#include <utility>

namespace robopath {

double LineSegment::length() const {
	return start.distanceTo(end);
}	

Point LineSegment::closestPoint(const Point &p) const {
	 double distance = Vector::dot(start, p, start, end) / Vector::dot(start, end, start, end); // AP.AB / AB.AB
    if (distance < 0.0) {
        return start;
    } else if (distance > 1.0) {
        return end;
    } else {    	
        const double x = start.x + (end.x - start.x) * distance;
        const double y = start.y + (end.y - start.y) * distance;
        return Point(x, y);        
    }
}

bool LineSegment::collidesWith(const Point &p) const {
	return p.collidesWith(*this);
}

bool LineSegment::collidesWith(const LineSegment &ls) const {
	const auto &A = start;
    const auto &B = end;
    const auto &C = ls.start;
    const auto &D = ls.end;

    const auto denom = Vector::cross(A, B, C, D); // AB cross CD
    const auto an = Vector::cross(A, C, A, B); // AC cross AB
    // Test for collinear
    if (isZero(denom)) {
        if (!isZero(an)) {
            return false; // parallel non-intersecting lines
        }
        const auto dotAB = Vector::dot(A, B, A, B); // AB dot AB
        auto t0 = Vector::dot(A, C, A, B) / dotAB; // AC dot AB / AB dot AB
        auto t1 = t0 + Vector::dot(C, D, A, B) / dotAB; // t0 + CD dot AB / AB dot AB
        if (t1 < t0) {
        	std::swap(t0, t1);
        }
        return Interval::intervalsIntersect(t0, t1, 0.0, 1.0);
    }

    const auto a = an / denom;
    if (!Interval::isInInterval(a, 0.0, 1.0)) {
        return false;
    }
    const auto b = Vector::cross(A, C, C, D) / denom; // AC cross CD / denom
    return Interval::isInInterval(b, 0.0, 1.0);
}

bool LineSegment::collidesWith(const Circle &c) const {
   	const auto closest = closestPoint(c.center);
    return closest.collidesWith(c);
}

bool LineSegment::collidesWith(const Rectangle &r) const {
	// Check that one or two line point lie inside the rectangle
	if (start.collidesWith(r) || end.collidesWith(r)) {
        return true;
    }
    // Check line-line intersections
    for (const auto &line: r.getLines()) {
        if (collidesWith(line)) {
            return true;
        }
    }
    return false;
}

bool LineSegment::collidesWith(const Triangle &t) const {
	// Check that one or two line point lie inside the triangle
    if (start.collidesWith(t) || end.collidesWith(t)) {
        return true;
    }
    // Check line-line intersections
    for (const auto &line: t.getLines()) {
        if (collidesWith(line)) {
            return true;
        }
    }
    return false;	
}

}