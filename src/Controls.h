#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxLaunchControllers.h"

class Controls {

public:

	Controls() = default;
	Controls(const Controls& other) = delete;
	~Controls() = default;
	
	void setup();
	void update();
	void draw();

	float getScale();

private:
	
	ofxLaunchControl lc;

	ofxPanel gui;

	ofParameter<bool> show;
	ofParameter<float> scale;

};