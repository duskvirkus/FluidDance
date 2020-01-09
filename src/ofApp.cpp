#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	beginCamera();
}

//--------------------------------------------------------------
void ofApp::update(){
	updateTitle();

	camera.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	camera.draw(0, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::updateTitle() {
	stringstream titleStream;
	titleStream << PROJECT_NAME << " - " << CREATOR << " - FPS: " << static_cast<int>(ofGetFrameRate());
	ofSetWindowTitle(titleStream.str());
}

//--------------------------------------------------------------
void ofApp::beginCamera() {
	auto devices = camera.listDevices();
	for (const auto& device : devices) {
		if (device.bAvailable) {
			ofLogNotice() << device.id << ':' << device.deviceName;
		}
		else {
			ofLogNotice() << device.id << ':' << device.deviceName << " - UNAVAILABLE!";
		}
	}

	camera.setDeviceID(0);
	camera.setDesiredFrameRate(60);
	camera.setup(CAMERA_WIDTH, CAMERA_HEIGHT);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
