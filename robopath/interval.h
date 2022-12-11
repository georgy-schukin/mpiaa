#pragma once

namespace robopath {

class Interval {
public:
	Interval() {}
	Interval(double start, double end):
		start(start), end(end) {			
	}

	bool isEmpty() const;

	bool includes(double value) const;
	bool intersects(const Interval &intv) const;
	Interval intersection(const Interval &intv) const;

	// Check that value is in range [start, end].
	static bool isInInterval(double value, double start, double end);

	// Check that ranges [x1, x2] and [y1, y2] intersect.
	static bool intervalsIntersect(double x1, double x2, double y1, double y2);

	// Get intersection of ranges [x1, x2] and [y1, y2].
	static Interval intervalsIntersection(double x1, double x2, double y1, double y2);

public:
	double start = 0.0, end = 0.0;	
};

}