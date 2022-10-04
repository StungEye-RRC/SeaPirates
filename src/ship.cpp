#include "ship.h"
#include "ofAppRunner.h"

Ship::Ship(const std::string& avatarFilename, const Point& coordinate, const Point& speed):
	coordinate{ coordinate }, speed{speed} {
	avatar.load(avatarFilename);
}

Ship::Ship(const std::string& avatarFilename, double x, double y, double xSpeed, double ySpeed):
	coordinate{ x, y }, speed{xSpeed, ySpeed} {
	avatar.load(avatarFilename);
}

Ship::Ship(const ofImage& avatar, const Point& coordinate, const Point& speed):
	coordinate{ coordinate }, speed{speed}, avatar{avatar} {
		
}

void Ship::move() {
	coordinate.x += speed.x;
	coordinate.y += speed.y;
	bounceOnEdge();
}

void Ship::draw() const {
	avatar.draw(coordinate.x, coordinate.y);
}

void Ship::bounceOnEdge() {
	if (coordinate.y > ofGetHeight() - avatar.getHeight()) {
		coordinate.y = ofGetHeight() - avatar.getHeight();
		speed.y *= -1;
	}
	else if (coordinate.y < 0) {
		coordinate.y = 0;
		speed.y *= -1;
	}

	if (coordinate.x > ofGetWidth() - avatar.getWidth()) {
		coordinate.x = ofGetWidth() - avatar.getWidth();
		speed.x *= -1;
	}
	else if (coordinate.x < 0) {
		coordinate.x = 0;
		speed.x *= -1;
	}
}
