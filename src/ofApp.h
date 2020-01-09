#pragma once

#include "ofMain.h"

constexpr char* PROJECT_NAME = "Fluid Dance";
constexpr char* CREATOR = "Violet Graham";
constexpr int CAMERA_WIDTH = 1920;
constexpr int CAMERA_HEIGHT = 1080;


class ofApp : public ofBaseApp{

	public:

		ofVideoGrabber camera;

		void setup();
		void update();
		void draw();

		void updateTitle();

		void beginCamera();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
