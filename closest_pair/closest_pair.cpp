#include "closest_pair.h"

#include <stdexcept>

using namespace std;

std::pair<Point, Point> closest_pair(const std::vector<Point> &points) {
	if (points.size() <= 1) {
		throw invalid_argument("Not enough points");
	}	

	// Your implementation here.
	
	auto closest = std::make_pair(Point(), Point());
	return closest;
}
