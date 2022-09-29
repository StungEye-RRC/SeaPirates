#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ssGlutton.avatar.load("Ships\\ship (3).png");
	ssGlutton.coordinate.x = ofRandomWidth() - ssGlutton.avatar.getWidth();
	ssGlutton.coordinate.y = ofRandomHeight() - ssGlutton.avatar.getHeight();
	ssGlutton.speed.x = ofRandom(4) + 1;
	ssGlutton.speed.y = ofRandom(4) + 1;
}

//--------------------------------------------------------------
void ofApp::update() {
	ssGlutton.coordinate.x += ssGlutton.speed.x;
	ssGlutton.coordinate.y += ssGlutton.speed.y;

	if (ssGlutton.coordinate.y > ofGetHeight() - ssGlutton.avatar.getHeight() || ssGlutton.coordinate.y < 0) {
		ssGlutton.speed.y *= -1;
	}

	if (ssGlutton.coordinate.x > ofGetWidth() - ssGlutton.avatar.getWidth() || ssGlutton.coordinate.x < 0) {
		ssGlutton.speed.x *= -1;
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	ssGlutton.avatar.draw(ssGlutton.coordinate.x, ssGlutton.coordinate.y);
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
