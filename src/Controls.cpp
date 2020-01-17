#include "Controls.h"

void Controls::setup() {
	gui.setup();
	gui.setName("Press H to Toggle");
	gui.setPosition(0, 0);

	gui.add(scale.setup("scale", 1.185, 1, 1.185));
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