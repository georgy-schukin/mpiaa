#include "util.h"

#include <cmath>

namespace robopath {

const double EPS = 1e-8;

bool areEqual(double a, double b) {
	return std::abs(a - b) < EPS;
}

bool isZero(double a) {
	return std::abs(a) < EPS;
}

}
