#include "ship.h"
#include "ofAppRunner.h"
#include "ofGraphics.h"

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
	if (state != State::paused) {
		coordinate.x += speed.x;
		coordinate.y += speed.y;
		bounceOnEdge();
	}
}

void Ship::draw() const {
	if (state == State::hovered) {
		ofSetColor(ofColor::green);
	} else if (state == State::paused) {
		ofSetColor(ofColor::red);
	} else {
		ofSetColor(255);
	}

	avatar.draw(coordinate.x, coordinate.y);
}

void Ship::processMouse(double mouseX, double mouseY, bool isMousePressed) {
	const bool isHovered{ isShipHovered(mouseX, mouseY) };

	if (isHovered && isMousePressed) {
		state = State::paused;
	} else if (isHovered) {
		state = State::hovered;
	} else {
		state = State::moving;
	}
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

bool Ship::isShipHovered(double mouseX, double mouseY) const {
	return (mouseX > coordinate.x)
		&& (mouseY > coordinate.y)
		&& (mouseX < coordinate.x + avatar.getWidth())
		&& (mouseY < coordinate.y + avatar.getHeight());
}

std::ostream& operator<<(std::ostream& out, const Ship& ship) {
	std::string state;

	switch(ship.state) {
	case Ship::State::moving:  state = "Moving";  break;
	case Ship::State::hovered: state = "Hovered"; break;
	case Ship::State::paused:  state = "Paused";  break;
	}

	out << "Ship X: " << ship.coordinate.x
		<< " Y: " << ship.coordinate.y
		<< " State: " << state << "\n";

	return out;
}
