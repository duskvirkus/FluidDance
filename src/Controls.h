#pragma once

#include "ofMain.h"
#include "ofxGui.h"

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
	
	bool show = true;
	ofxPanel gui;

	ofxFloatSlider scale;

};