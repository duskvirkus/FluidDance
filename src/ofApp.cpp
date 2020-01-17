#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

#ifdef TARGET_OPENGLES
	cout << "Project unsupported on this system! Press enter to exit." << '\n';
	cin.get();
	exit(1);
#endif
	assert(ofIsGLProgrammableRenderer());

#ifdef _DEBUG
	ofSetLogLevel(ofLogLevel::OF_LOG_VERBOSE);
	ofLogToFile("logfile.log", true);
#endif

	ofEnableAlphaBlending();

	beginCamera();

	plane.set(ofGetWidth(), ofGetHeight(), ofGetWidth() / 20, ofGetHeight() / 20, OF_PRIMITIVE_TRIANGLES);
	
	shader.load("fluid");

	ofSetBackgroundColor(255, 0, 0);

	controls.setup();

	frames.reserve(controls.getFrameBufferSize() * 4);

	//frameMasks.reserve(FRAMES_MAX);

	//pixelsBuffer.allocate(CAMERA_WIDTH, CAMERA_HEIGHT, OF_PIXELS_RGB);

	//for (size_t i = 0; i < FRAMES_MAX; ++i) {
	//	for (size_t j = 0; j < pixelsBuffer.getWidth(); ++j) {
	//		for (size_t k = 0; k < pixelsBuffer.getHeight(); ++k) {
	//			const auto row = k / static_cast<int>(CAMERA_HEIGHT / FRAMES_MAX);
	//			if (row == i) {
	//				pixelsBuffer.setColor(j, k, ofColor(255, 255, 255, 255));
	//			}
	//			else {
	//				pixelsBuffer.setColor(j, k, ofColor(0, 0, 0, 0));
	//			}
	//		}
	//	}
	//	ofTexture texture;
	//	texture.allocate(pixelsBuffer);
	//	texture.loadData(pixelsBuffer);
	//	frameMasks.push_back(texture);
	//}

	

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
		frames.push_back(texture);

		while (frames.size() > controls.getFrameBufferSize()) {
			frames.erase(frames.begin());
		}

		//for (size_t i = 0; i < framesBuffer.size(); ++i) {
		//	framesBuffer[i].setAlphaMask(frameMasks[i]);
		//}
	}

	ofSetFrameRate(30);

	controls.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	//const auto width = ofGetWidth() * scaleSlider;
	//const auto height = ofGetHeight() * scaleSlider;
	////camera.draw(ofGetWidth() / 2 - width / 2, ofGetHeight() / 2 - height / 2, width, height);

	//for (const auto& frame : frames) {
	//	frame.draw(ofGetWidth() / 2 - width / 2, ofGetHeight() / 2 - height / 2, width, height);
	//}

	const int sectionSize = controls.getFrameBufferSize() / 2;
	const glm::vec2 window(ofGetWidth(), ofGetHeight());

	if (frames.size() > 0) {
		for (size_t i = 0; i < frames.size(); ++i) {
			const float offset = ofMap(i, 0, frames.size(), -0.5, 0.5) + ((1.0f / sectionSize) / 2.0f);

			plane.mapTexCoordsFromTexture(frames[i]);

			frames[i].bind();

			shader.begin();

			shader.setUniform2f("u_window", window);
			shader.setUniform1f("u_section", static_cast<float>(sectionSize));
			shader.setUniform1f("u_offset", offset);

			ofPushMatrix();
			ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
			const float scale = controls.getScale();
			ofScale(glm::vec3(scale, -scale, scale));
			plane.draw();
			ofPopMatrix();

			shader.end();

			frames[i].unbind();
		}
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

	controls.draw();
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
