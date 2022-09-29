#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	for (auto i{1}; i <= numberOfShips; ++i) {
		Ship ship;
		ship.avatar.load("Ships\\ship (" + std::to_string(i % 24) + ").png");
		ship.coordinate.x = ofRandom(ofGetWidth() - ship.avatar.getWidth());
		ship.coordinate.y = ofRandom(ofGetHeight() - ship.avatar.getHeight());
		ship.speed.x = ofRandom(3) + 3;
		ship.speed.y = ofRandom(3) + 3;

		ships.push_back(ship);
	}
}

//--------------------------------------------------------------
void ofApp::update() {
	for (auto& ship : ships) {
		ship.coordinate.x += ship.speed.x;
		ship.coordinate.y += ship.speed.y;

		if (ship.coordinate.y > ofGetHeight() - ship.avatar.getHeight() || ship.coordinate.y < 0) {
			ship.speed.y *= -1;
		}

		if (ship.coordinate.x > ofGetWidth() - ship.avatar.getWidth() || ship.coordinate.x < 0) {
			ship.speed.x *= -1;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackgroundGradient(ofColor::blue, ofColor::darkBlue);

	for (const auto& ship : ships) {
		ship.avatar.draw(ship.coordinate.x, ship.coordinate.y);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
