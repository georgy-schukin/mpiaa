#define CATCH_CONFIG_MAIN

#include "../catch.hpp"

#include "objects.h"

using namespace robopath;

TEST_CASE( "Point-point collision", "[coll]" ) {
    Point p1(0, 0);
    Point p2(1, 1);
    Point p3(0.5, -2.8);

    CHECK(p1.collidesWith(p1));
    CHECK(p2.collidesWith(p2));
    CHECK(p3.collidesWith(p3));
    CHECK_FALSE(p1.collidesWith(p2));
    CHECK_FALSE(p1.collidesWith(p3));
    CHECK_FALSE(p2.collidesWith(p3));
}

TEST_CASE( "Point-line collision", "[coll]" ) {
    Point p1(0, 0);
    Point p2(10, 10);
    Point p3(5.1, 5.1);
    Point p4(5.0, 5.1);
    Point p5(11, 11);
    Point p6(-5, -5);

    LineSegment l1(p1, p2);

    CHECK(l1.collidesWith(p3));
    CHECK(p3.collidesWith(l1)); // reverse
    CHECK(l1.collidesWith(p1));
    CHECK(l1.collidesWith(p2));
    CHECK_FALSE(l1.collidesWith(p4));
    CHECK_FALSE(l1.collidesWith(p5));
    CHECK_FALSE(l1.collidesWith(p6));
    CHECK_FALSE(p6.collidesWith(l1)); // reverse
}

TEST_CASE( "Point-circle collision", "[coll]" ) {
    Point p1(2.5, 2.5);
    Point p2(5.1, 5.5);

    Circle c1(p1, 2.5);
    Circle c2(p1, 5.0);

    CHECK(c1.collidesWith(p1));
    CHECK(c1.collidesWith(Point(2.5, 5.0)));
    CHECK(c1.collidesWith(Point(3.0, 3.7)));
    CHECK_FALSE(c1.collidesWith(p2));
    CHECK(c2.collidesWith(p2));
    CHECK(p2.collidesWith(c2)); // reverse
}

TEST_CASE( "Point-triangle collision", "[coll]" ) {
    Point p1(1.0, 1.0);
    Point p2(5.5, 1.0);
    Point p3(3.5, 4.7);
    Point p4(1.0, 3.6);

    Triangle t1(p1, p2, p3);
    Triangle t2(p1, p3, p4);

    CHECK(t1.collidesWith(p1));
    CHECK(t1.collidesWith(p2));
    CHECK(t1.collidesWith(p3));
    CHECK(t1.collidesWith(Point(2.7, 1.0))); // on edge
    CHECK_FALSE(t1.collidesWith(Point(-1.0, 8.0)));
    CHECK_FALSE(t1.collidesWith(Point(5.51, 1.0)));
    CHECK(t1.collidesWith(Point(2.5, 3.2)));
    CHECK(t2.collidesWith(Point(1.0, 2.5)));
    CHECK(t2.collidesWith(Point(1.5, 2.5)));
    CHECK(Point(1.5, 2.5).collidesWith(t2)); // reverse
}

TEST_CASE( "Point-rectangle collision", "[coll]" ) {
    Rectangle rect = Rectangle::betweenPoints(1, 10, 8, 2);
    CHECK(rect.collidesWith(Point(1, 10)));
    CHECK(rect.collidesWith(Point(2, 6.9)));
    CHECK(rect.collidesWith(Point(2.7, 10)));
    CHECK_FALSE(rect.collidesWith(Point(0.5, 4)));
    CHECK_FALSE(rect.collidesWith(Point(8.05, 10)));
}

TEST_CASE( "Line-line collision", "[coll]" ) {
    LineSegment l1(1.0, 1.0, 1.0, 5.5); // vert             
    LineSegment l2(1.0, 1.0, 5.0, 1.0); // hor
    LineSegment l3(0.1, 0.2, 5.0, 3.7);            

    CHECK_FALSE(l1.collidesWith(LineSegment(2.0, 2.0, 2.0, 5.5))); // parallel lines
    CHECK(l1.collidesWith(LineSegment(1.0, 0.1, 1.0, 2.5))); // collinear overlap
    CHECK_FALSE(l1.collidesWith(LineSegment(-0.5, 1.0, 0.5, 1.0))); // collinear non overlap
    CHECK(l1.collidesWith(l2));

    CHECK_FALSE(l2.collidesWith(LineSegment(2.5, 2.0, 2.5, 2.0))); // parallel lines
    CHECK(l2.collidesWith(LineSegment(-0.6, 1.0, 3.7, 1.0))); // collinear overlap
    CHECK_FALSE(l2.collidesWith(LineSegment(-0.8, 1.0, 0.99, 1.0))); // collinear non overlap

    CHECK(l3.collidesWith(l2));
    CHECK(l3.collidesWith(LineSegment(-2.0, 5.2, 5.0, -0.4)));
    CHECK(l3.collidesWith(LineSegment(1.1, 3.7, 4.2, 0.1)));            
    CHECK_FALSE(l3.collidesWith(LineSegment(-2.0, 2.0, 2.0, -2.0)));
}

TEST_CASE( "Line-circle collision", "[coll]" ) {
    Circle c1(2.5, 1.5, 5.0);            

    CHECK(c1.collidesWith(LineSegment(0.0, 1.5, 8.0, 2.0)));
    CHECK(c1.collidesWith(LineSegment(1.0, 1.5, 2.3, 1.7)));
    CHECK(c1.collidesWith(LineSegment(2.4, 1.6, 4.0, 1.7)));
    CHECK(c1.collidesWith(LineSegment(-5.0, 4.2, 7.6, -0.5)));
    CHECK_FALSE(c1.collidesWith(LineSegment(-10.0, 8.2, 8.5, 10.0)));
}

TEST_CASE( "Line-triangle collision", "[coll]" ) {
    Triangle t1(0.2, 0.3, 5.0, 1.3, 3.0, 4.6);

    CHECK(t1.collidesWith(LineSegment(0.2, 0.3, 0.2, 5.0)));
    CHECK(t1.collidesWith(LineSegment(0.1, 1.0, 3.2, 2.0)));
    CHECK(t1.collidesWith(LineSegment(2.1, 1.0, 3.2, 2.1)));
    CHECK(t1.collidesWith(LineSegment(1.0, 3.2, 4.2, -1.0)));
    CHECK(t1.collidesWith(LineSegment(0.2, 0.3, 5.0, 1.3)));
    CHECK(t1.collidesWith(LineSegment(0.0, 4.1, 5.0, 4.1)));
    CHECK_FALSE(t1.collidesWith(LineSegment(-1.2, 1.3, 1.0, 4.3)));
}

TEST_CASE( "Line-rectangle collision", "[coll]" ) {
    Rectangle rect = Rectangle::betweenPoints(1, 10, 8, 2);
    CHECK(rect.collidesWith(LineSegment(-4, 6.5, 5, 3.7)));
    CHECK(rect.collidesWith(LineSegment(1, 10, -4, 7)));
    CHECK(rect.collidesWith(LineSegment(3, 2.5, 5, 7.5)));
    CHECK_FALSE(rect.collidesWith(LineSegment(0, 4, 0.5, 9)));
    CHECK_FALSE(rect.collidesWith(LineSegment(-2, 9, 2, 12)));
}

TEST_CASE( "Circle-circle collision", "[coll]" ) {
    Circle c1(2.5, 2.5, 2.5);
    Circle c2(2.5, 0.0, 2.5);
    Circle c3(5.0, 5.5, 1.7);
    Circle c4(7.0, 7.5, 2.0);
    Circle c5(0.1, 0.5, 2.2);

    CHECK(c1.collidesWith(c2));
    CHECK(c1.collidesWith(c3));
    CHECK_FALSE(c1.collidesWith(c4));
    CHECK(c3.collidesWith(c4));
    CHECK_FALSE(c3.collidesWith(c5));
}

TEST_CASE( "Circle-triangle collision", "[coll]" ) {
    Triangle t1(0.2, 0.3, 5.0, 1.3, 3.0, 4.6);
    Triangle t2(0.2, 0.2, 5.0, 0.2, 3.0, 4.6);

    CHECK(t1.collidesWith(Circle(3.1, 2.2, 0.5)));
    CHECK(t1.collidesWith(Circle(0.2, 0.3, 2.0)));
    CHECK(t1.collidesWith(Circle(3.1, 2.2, 10.5)));
    CHECK(t1.collidesWith(Circle(4.1, 1.2, 2.5)));
    CHECK_FALSE(t1.collidesWith(Circle(0.0, 0.0, 0.2)));
    CHECK_FALSE(t1.collidesWith(Circle(1.0, 4.1, 1.1)));

    CHECK(t2.collidesWith(Circle(0.0, 0.0, 0.29)));
    CHECK(t2.collidesWith(Circle(3.0, 0.1, 0.1)));
    CHECK_FALSE(t2.collidesWith(Circle(3.0, 0.1, 0.09)));
}

TEST_CASE( "Circle-rectangle collision", "[coll]" ) {
    Rectangle rect = Rectangle::betweenPoints(1, 10, 8, 2);
    CHECK(rect.collidesWith(Circle(2, 7, 0.1)));
    CHECK(rect.collidesWith(Circle(5, 5, 15)));
    CHECK(rect.collidesWith(Circle(0.5, 7, 0.9)));
    CHECK(rect.collidesWith(Circle(0, 6, 1)));
    CHECK_FALSE(rect.collidesWith(Circle(1, 12, 1)));
    CHECK_FALSE(rect.collidesWith(Circle(9, 4, 0.5)));
}

TEST_CASE( "Triangle-triangle collision", "[coll]" ) {
    Triangle t1(0.2, 0.3, 5.0, 1.3, 3.0, 4.6);

    CHECK(t1.collidesWith(Triangle(2.1, 1.3, 4.0, 1.4, 3.0, 3.1)));
    CHECK(t1.collidesWith(Triangle(0.2, 0.3, 0.2, 5.0, 0.0, 7.1)));
    CHECK(t1.collidesWith(Triangle(1.1, 3.3, 3.0, -1.4, 4.0, -0.5)));
    CHECK(t1.collidesWith(Triangle(0.2, 0.3, 5.0, 1.3, 5.0, 0.1)));
    CHECK(t1.collidesWith(Triangle(3.2, 0.3, 5.0, 3.3, 7.0, -1.1)));
    CHECK_FALSE(t1.collidesWith(Triangle(1.2, 3.3, 2.0, 4.3, 0.1, 7.1)));
}

TEST_CASE( "Triangle-rectangle collision", "[coll]" ) {
    Rectangle rect = Rectangle::betweenPoints(1, 10, 8, 2);
    CHECK(rect.collidesWith(Triangle(2, 5, 3, 7.5, 4, 2.9)));
    CHECK(rect.collidesWith(Triangle(4.9, 2.5, -6, 1, 0, 8)));
    CHECK(rect.collidesWith(Triangle(-5, -50, -20, 40, 50, 20)));
    CHECK_FALSE(rect.collidesWith(Triangle(-2, 9, 2, 12, -4, 12)));            
}

TEST_CASE( "Rectangle-rectangle collision", "[coll]" ) {
    Rectangle rect1 = Rectangle::betweenPoints(1, 10, 8, 2);
    Rectangle rect2 = Rectangle::betweenPoints(2, 6, 5, 2.5);
    Rectangle rect3 = Rectangle::betweenPoints(-3, 5, 0, 1);
    Rectangle rect4 = Rectangle::betweenPoints(0, 6, 4, -2);
    CHECK(rect1.collidesWith(rect2));
    CHECK_FALSE(rect1.collidesWith(rect3));
    CHECK(rect1.collidesWith(rect4));
    CHECK_FALSE(rect2.collidesWith(rect3));            
}
