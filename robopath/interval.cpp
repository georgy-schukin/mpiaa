#include "interval.h"
#include "util.h"

#include <cmath>

namespace robopath {

bool Interval::isEmpty() const {
	return areEqual(start, end);
}

bool Interval::includes(double value) const {
    return Interval::isInInterval(value, start, end);
}

bool Interval::intersects(const Interval &intv) const {
    return Interval::intervalsIntersect(start, end, intv.start, intv.end);
}

Interval Interval::intersection(const Interval &intv) const {
    return Interval::intervalsIntersection(start, end, intv.start, intv.end);
}

// Check that value is in range [start, end].
bool Interval::isInInterval(double value, double start, double end) {
    return (value >= start && value <= end);
}

// Check that ranges [x1, x2] and [y1, y2] intersect.
bool Interval::intervalsIntersect(double x1, double x2, double y1, double y2) {
    return (x1 <= y2 && y1 <= x2);
}

// Get intersection of ranges [x1, x2] and [y1, y2].
Interval Interval::intervalsIntersection(double x1, double x2, double y1, double y2) {
    if (!intervalsIntersect(x1, x2, y1, y2)) {
        return Interval();
    }
    double start = std::max(x1, y1);
    double end = std::min(x2, y2);
    return Interval(start, end);
}

}