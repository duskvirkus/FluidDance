#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGLFWWindow.h"
#include <optional>

//========================================================================
int main(){

	ofGLFWWindowSettings settings;
	settings.setSize(CAMERA_WIDTH / 2, CAMERA_HEIGHT / 2);
	settings.setPosition(glm::vec2(0, 30));
	settings.resizable = false;
	settings.setGLVersion(3, 2);

	shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);

	shared_ptr<ofApp> mainApp(new ofApp);

	ofRunApp(mainWindow, mainApp);
	ofRunMainLoop();

}
