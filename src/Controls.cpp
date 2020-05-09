#include "Controls.h"

//--------------------------------------------------------------
void Controls::setup() {
	gui.setup();
	gui.setName("Controls");
	gui.setPosition(0, 0);

	gui.add(show.set("Show Controls", true));
	gui.add(scale.set("Scale", 1, 1, 1.185));
	gui.add(frameBufferSize.set("Frame Buffer Size", 20, 4, 50));
	gui.add(overdrive_frames.set("Realtime Frames", false));

	lc.listDevices();

	lc.setup(0);
	lc.toggle(0, show);
	lc.toggle(1, overdrive_frames);
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

bool Controls::get_overdrive_frames() const {
	return overdrive_frames;
}