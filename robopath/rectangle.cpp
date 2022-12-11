#include "rectangle.h"
#include "objects.h"

namespace robopath {

Interval Rectangle::getXInterval() const {
    return Interval(topLeft.x, topLeft.x + width);
}

Interval Rectangle::getYInterval() const {
    return Interval(topLeft.y - height, topLeft.y);
}

std::array<Point, 4> Rectangle::getPoints() const {
    return std::array<Point, 4> {
        topLeft,
        Point(topLeft.x + width, topLeft.y),
        Point(topLeft.x + width, topLeft.y - height),
        Point(topLeft.x, topLeft.y - height)
    };
}

std::array<LineSegment, 4> Rectangle::getLines() const {
    const auto points = getPoints();
    return std::array<LineSegment, 4> {
        LineSegment(points[0], points[1]),
        LineSegment(points[1], points[2]),
        LineSegment(points[2], points[3]),
        LineSegment(points[3], points[0])
    };
}

Rectangle Rectangle::atCenter(const Point &center, double width, double height) {
    return atCenter(center.x, center.y, width, height);
}

Rectangle Rectangle::atCenter(double cx, double cy, double width, double height) {
    return Rectangle(cx - width * 0.5, cy - height * 0.5, width, height);
}

Rectangle Rectangle::atBottomLeft(const Point &bottomLeft, double width, double height) {
    return atBottomLeft(bottomLeft.x, bottomLeft.y, width, height);
}

Rectangle Rectangle::atBottomLeft(double blx, double bly, double width, double height) {
    return Rectangle(blx, bly + height, width, height);
}

Rectangle Rectangle::betweenPoints(const Point &topLeft, const Point &bottomRight) {
    return betweenPoints(topLeft.x, topLeft.y, bottomRight.x, bottomRight.y);
}

Rectangle Rectangle::betweenPoints(double tlx, double tly, double brx, double bry) {
    return Rectangle(tlx, tly, brx - tlx, tly - bry);
}

bool Rectangle::collidesWith(const Point &p) const {
    return p.collidesWith(*this);
}

bool Rectangle::collidesWith(const LineSegment &ls) const {
    return ls.collidesWith(*this);
}

bool Rectangle::collidesWith(const Circle &c) const {
    return c.collidesWith(*this);
}

bool Rectangle::collidesWith(const Rectangle &r) const {
    return getXInterval().intersects(r.getXInterval()) 
        && getYInterval().intersects(r.getYInterval());
}

bool Rectangle::collidesWith(const Triangle &t) const {
	return t.collidesWith(*this);
}

}
