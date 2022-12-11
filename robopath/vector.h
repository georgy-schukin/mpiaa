#pragma once

namespace robopath {

class Point;

class Vector {
public:
	Vector() {}
	Vector(double x, double y): 
		x(x), y(y) {			
	}

	double lengthSquared() const;         
	double length() const; 
	bool isZeroLength() const;

	void normalize();
	Vector normalized() const;

	double cross(const Vector &v) const;
	double dot(const Vector &v) const;

	Vector multiplied(double coeff) const;
	Vector reversed() const; 
	Vector orthogonal() const; 

	double angleBetween(const Vector &otherVector) const;	
	double angleBetween(double vx, double vy) const;

	static double cross(const Vector &v1, const Vector &v2);
	static double cross(const Point &s1, const Point &e1, const Point &s2, const Point &e2);
	static double cross(double x1, double y1, double x2, double y2);

	static double dot(const Vector &v1, const Vector &v2);
	static double dot(const Point &s1, const Point &e1, const Point &s2, const Point &e2);
	static double dot(double x1, double y1, double x2, double y2);

	static double angleBetween(double x1, double y1, double x2, double y2);

public:
	double x = 0.0, y = 0.0;
};	

}