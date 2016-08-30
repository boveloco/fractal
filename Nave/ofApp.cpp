#include "ofApp.h"
bool click = false;
int ct = 0;
int framesToMove = 60 * 2;
ofPoint p = ofPoint(0, 0);
ofPoint sizeToMove;
ofPoint wtMove;

void mouseLerp(ofPoint end){
	if (end.x < p.x)
		sizeToMove.x = -p.x + (end.x - p.x);
	else
		sizeToMove.x = p.x + (end.x - p.x);


	if (end.y < p.y) 
		sizeToMove.y = -p.y + (end.y - p.y);
	else
		sizeToMove.y = p.y + (end.y - p.y);

	p.x += (sizeToMove.x / framesToMove);
	p.y += (sizeToMove.y / framesToMove);
}

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){
	
	if (click) {
		if (ct < framesToMove) {
			mouseLerp(wtMove);
			ct++;
		}
		else 
		{
			ct = 0;
			sizeToMove = ofPoint(0, 0);
			click = !click;
		}
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofDrawCircle(p, 50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	click = true;
	wtMove.x = ofGetMouseX();
	wtMove.y = ofGetMouseY();
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}