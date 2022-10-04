#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	for (auto i{1}; i <= numberOfShips; ++i) {
		const Point coordinate{
			static_cast<double>(ofRandomWidth()),
			static_cast<double>(ofRandomHeight())
		};

		const Point speed{ ofRandom(3) + 3, ofRandom(3) + 3 };

		ofImage avatar;
		avatar.load("Ships\\ship (" + std::to_string(i % 24) + ").png");

		Ship ship{
			"Ships\\ship (" + std::to_string(i % 24) + ").png",
			coordinate,
			speed
		};

		ships.push_back(ship);
	}
}

//--------------------------------------------------------------
void ofApp::update() {
	for (auto& ship : ships) {
		ship.move();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackgroundGradient(ofColor::blue, ofColor::darkBlue);

	for (const auto& ship : ships) {
		ship.draw();
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
