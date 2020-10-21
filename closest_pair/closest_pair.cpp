#include "closest_pair.h"

#include <stdexcept>

using namespace std;

std::pair<Point, Point> closest_pair(const std::vector<Point> &points) {
	// Return the closest pair of points from given points.
	// Order of points in the result doesn't matter.
	// If there are fewer than 2 points, throw an exception.

	if (points.size() < 2) {
		throw invalid_argument("Not enough points");
	}	

	// Your implementation here.
	
	auto result = std::make_pair(Point(), Point());	
	return result;
}
