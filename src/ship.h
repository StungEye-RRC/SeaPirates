#pragma once

#include "ofImage.h"
#include "point.h"

// Refactored from struct (public members)
// to a class with private members.
class Ship {
private:
	Point coordinate;
	Point speed;
	ofImage avatar;
public:
	Ship(const std::string& avatarFilename, const Point& coordinate, const Point& speed);
	Ship(const std::string& avatarFilename, double x, double y, double xSpeed, double ySpeed);
	Ship(const ofImage& avatar, const Point& coordinate, const Point& speed);

	void move();
	void draw() const;
private:
	void bounceOnEdge();
};