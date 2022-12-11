#include "vector.h"
#include "point.h"
#include "util.h"

#include <cmath>

namespace robopath {

double Vector::lengthSquared() const {
    return x * x + y * y;
}
        
double Vector::length() const {
    return std::sqrt(lengthSquared());
}

bool Vector::isZeroLength() const {
    return isZero(x) && isZero(y);
}

void Vector::normalize() {
    double len = length();
    x /= len;
    y /= len;
}

Vector Vector::normalized() const {
    Vector vec(x, y);
    vec.normalize();
    return vec;
}

double Vector::cross(const Vector &v) const {
    return Vector::cross(x, y, v.x, v.y);
}  

double Vector::dot(const Vector &v) const {
    return Vector::dot(x, y, v.x, v.y);
}

Vector Vector::multiplied(double coeff) const {
    return Vector(x * coeff, y * coeff);
}

Vector Vector::reversed() const {
    return Vector(-x, -y);
}

// CW orthogonal
Vector Vector::orthogonal() const {
    return Vector(y, -x);
}

double Vector::angleBetween(const Vector &otherVector) const {
    return Vector::angleBetween(x, y, otherVector.x, otherVector.y);            
}

double Vector::angleBetween(double vx, double vy) const {
    return Vector::angleBetween(x, y, vx, vy);
}

double Vector::cross(const Vector &v1, const Vector &v2) {
    return cross(v1.x, v1.y, v2.x, v2.y);
}

// (s1, e1) cross (s2, e2)
double Vector::cross(const Point &s1, const Point &e1, const Point &s2, const Point &e2) {
    return cross(e1.x - s1.x, e1.y - s1.y, e2.x - s2.x, e2.y - s2.y);
}

double Vector::cross(double x1, double y1, double x2, double y2) {
    return (x1 * y2 - x2 * y1);
}        

double Vector::dot(const Vector &v1, const Vector &v2) {
    return dot(v1.x, v1.y, v2.x, v2.y);
}

// (s1, e1) dot (s2, e2)
double Vector::dot(const Point &s1, const Point &e1, const Point &s2, const Point &e2) {
    return dot(e1.x - s1.x, e1.y - s1.y, e2.x - s2.x, e2.y - s2.y);
}

double Vector::dot(double x1, double y1, double x2, double y2) {
    return (x1 * x2 + y1 * y2);
}

double Vector::angleBetween(double x1, double y1, double x2, double y2) {
    double sin = x1 * y2 - y1 * x2;
    double cos = x1 * x2 + y1 * y2;
    return std::atan2(sin, cos);
}

}