#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	ofSetCircleResolution(120);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateZ(90);

	ofNoFill();
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);

	ofColor color;
	auto noise_seed = glm::vec3(ofRandom(1000), ofRandom(1000), ofRandom(1000));
	
	for (int i = 0; i < 50; i++) {

		ofPushMatrix();

		ofRotateY(ofMap(ofNoise(noise_seed.y, i * 0.005 + ofGetFrameNum() * 0.008), 0, 1, -12, 12));
		ofRotateX(ofMap(ofNoise(noise_seed.x, i * 0.005 + ofGetFrameNum() * 0.008), 0, 1, -12, 12));

		color.setHsb(ofRandom(255), 200, 255);
		ofSetColor(color, 255);
		ofSetLineWidth(ofRandom(1, 3));

		ofDrawCircle(glm::vec2(), ofRandom(220, 280));

		ofPopMatrix();
	}

	ofDisableBlendMode();

	ofSetColor(0);
	ofFill();
	ofDrawSphere(glm::vec3(), 180);
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}