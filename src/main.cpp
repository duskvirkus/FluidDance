#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGLFWWindow.h"
#include <optional>

ofGLFWWindowSettings createSettings(const glm::vec2& size, const glm::vec2& position, bool resizable, const optional<shared_ptr<ofAppBaseWindow>>& shareContext) {
	ofGLFWWindowSettings settings;
	settings.setSize(size.x, size.y);
	settings.setPosition(position);
	settings.resizable = resizable;
	if (shareContext.has_value()) {
		settings.shareContextWith = shareContext.value();
	}
	return settings;
}

//========================================================================
int main(){
	
	shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(createSettings(
		glm::vec2(CAMERA_WIDTH / 1, CAMERA_HEIGHT / 1),
		glm::vec2(50, 50),
		false,
		nullopt
	));

	shared_ptr<ofAppBaseWindow> controlsWindow = ofCreateWindow(createSettings(
		glm::vec2(CAMERA_WIDTH / 4, CAMERA_HEIGHT / 2),
		glm::vec2(100 + CAMERA_WIDTH / 2, 50),
		true,
		mainWindow
	));

	shared_ptr<ofApp> mainApp(new ofApp);
	mainApp->setupControls();
	ofAddListener(controlsWindow->events().update, mainApp.get(), &ofApp::updateControls);
	ofAddListener(controlsWindow->events().draw, mainApp.get(), &ofApp::drawControls);

	ofRunApp(mainWindow, mainApp);
	ofRunMainLoop();

}
