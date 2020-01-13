#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

#ifdef TARGET_OPENGLES
	cout << "Project unsupported on this system! Press enter to exit." << '\n';
	cin.get();
	exit(1);
#endif
	assert(ofIsGLProgrammableRenderer());

	beginCamera();

	framesBuffer.reserve(FRAMES_MAX + 2);
	frameMasks.reserve(FRAMES_MAX);

	pixelsBuffer.allocate(CAMERA_WIDTH, CAMERA_HEIGHT, OF_PIXELS_RGB);

	for (size_t i = 0; i < FRAMES_MAX; ++i) {
		for (size_t j = 0; j < pixelsBuffer.getWidth(); ++j) {
			for (size_t k = 0; k < pixelsBuffer.getHeight(); ++k) {
				const auto row = k / static_cast<int>(CAMERA_HEIGHT / FRAMES_MAX);
				if (row == i) {
					pixelsBuffer.setColor(j, k, ofColor(255, 255, 255, 255));
				}
				else {
					pixelsBuffer.setColor(j, k, ofColor(0, 0, 0, 0));
				}
			}
		}
		ofTexture texture;
		texture.allocate(pixelsBuffer);
		texture.loadData(pixelsBuffer);
		frameMasks.push_back(texture);
	}

	ofEnableAlphaBlending();
	ofSetBackgroundColor(255, 0, 0);

	gui.setup();
	gui.setPosition(0, 0);
	gui.add(scaleSlider.setup("scale", 1.185, 1, 1.185));

}

//--------------------------------------------------------------
void ofApp::update(){
	updateTitle();

	camera.update();

	if (camera.isFrameNew()) {
		pixelsBuffer = camera.getPixels();
		ofTexture texture;
		texture.allocate(pixelsBuffer);
		texture.loadData(pixelsBuffer);
		framesBuffer.push_back(texture);

		while (framesBuffer.size() > FRAMES_MAX) {
			framesBuffer.erase(framesBuffer.begin());
		}

		for (size_t i = 0; i < framesBuffer.size(); ++i) {
			framesBuffer[i].setAlphaMask(frameMasks[i]);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	const auto width = ofGetWidth() * scaleSlider;
	const auto height = ofGetHeight() * scaleSlider;
	//camera.draw(ofGetWidth() / 2 - width / 2, ofGetHeight() / 2 - height / 2, width, height);

	for (const auto& frame : framesBuffer) {
		frame.draw(ofGetWidth() / 2 - width / 2, ofGetHeight() / 2 - height / 2, width, height);
	}

	//display masks
	//const int maskWidth = ofGetWidth() / frameMasks.size();
	//for (size_t i = 0; i < frameMasks.size(); ++i) {
	//	frameMasks[i].draw(i * maskWidth, 0, maskWidth, maskWidth * 9 / 16);
	//}

	//if (framesBuffer.size()) {
	//	const int maskWidth = ofGetWidth() / framesBuffer.size();
	//	for (size_t i = 0; i < framesBuffer.size(); ++i) {
	//		framesBuffer[i].getAlphaMask()->draw(i * maskWidth, 0, maskWidth, maskWidth * 9 / 16);
	//	}
	//}

	gui.draw();
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
	camera.setDesiredFrameRate(30);
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

////--------------------------------------------------------------
//void ofApp::setupControls() {
//	gui.setup();
//	gui.setPosition(0, 0);
//	gui.add(scaleSlider.setup("scale", 1.185, 1, 1.185));
//}
//
////--------------------------------------------------------------
//void ofApp::updateControls(ofEventArgs& args) {
//	updateTitle();
//}
//
////--------------------------------------------------------------
//void ofApp::drawControls(ofEventArgs& args) {
//	//camera.draw(0, 0, ofGetWidth(), ofGetHeight() / 2);
//
//	gui.draw();
//}
