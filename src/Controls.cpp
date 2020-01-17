#include "Controls.h"

void Controls::setup() {
	gui.setup();
	gui.setName("Controls");
	gui.setPosition(0, 0);

	gui.add(show.set("Show Controls", true));
	gui.add(scale.set("Scale", 1.185, 1, 1.185));

	lc.listDevices();

	lc.setup(0);
	lc.toggle(0, show);
	lc.knob(0, scale);
}

void Controls::update() {

}

void Controls::draw() {
	if (show) {
		gui.draw();
	}
}

float Controls::getScale() {
	return scale;
}