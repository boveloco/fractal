#include "ofMain.h"
#include "Fractal.h"

//========================================================================
int main( ){
	ofSetupOpenGL(1280,800,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:

	ofBackground(255, 0, 0);
	ofRunApp(new Fractal());

}
