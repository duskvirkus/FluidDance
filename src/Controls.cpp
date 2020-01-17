#include "Controls.h"

//--------------------------------------------------------------
void Controls::setup() {
	gui.setup();
	gui.setName("Controls");
	gui.setPosition(0, 0);

	gui.add(show.set("Show Controls", true));
	gui.add(scale.set("Scale", 1.185, 1, 1.185));
	gui.add(frameBufferSize.set("Frame Buffer Size", 4, 10, 50));

	lc.listDevices();

	lc.setup(0);
	lc.toggle(0, show);
	lc.knob(0, scale);
	lc.knob(1, frameBufferSize);
}

//--------------------------------------------------------------
void Controls::update() {
	frameBufferSize &= ~1; // set to even
}

//--------------------------------------------------------------
void Controls::draw() {
	if (show) {
		gui.draw();
	}
}

//--------------------------------------------------------------
float Controls::getScale() {
	return scale;
}

//--------------------------------------------------------------
int Controls::getFrameBufferSize() {
	return frameBufferSize;
}