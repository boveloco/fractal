#include "Fractal.h"

Fractal::Fractal()
{
	
}

Fractal::~Fractal()
{

}

inline void Fractal::findTriangles(ofVec3f a, ofVec3f b, ofVec3f c) {

	Triangle t0;
	Triangle t1;
	Triangle t2;
	Triangle t3;

	t0.a = (b + a) * 0.5;
	t0.b = (c + b) * 0.5;
	t0.c = (a + c) * 0.5;
	
	t1.a = a;
	t1.b = t0.a;
	t1.c = t0.c;
	
	t2.a = t0.a;
	t2.b = b;
	t2.c = t0.b;

	t3.a = t0.c;
	t3.b = t0.b;
	t3.c = c;

	this->triangles.push_back(t1);
	this->triangles.push_back(t2);
	this->triangles.push_back(t3);

}

inline void Fractal::findTriangles(Triangle t) {

	Triangle t0;
	Triangle t1;
	Triangle t2;
	Triangle t3;

	t0.a = (t.b + t.a) * 0.5;
	t0.b = (t.c + t.b) * 0.5;
	t0.c = (t.a + t.c) * 0.5;
	

	t1.a = t.a;
	t1.b = t0.a;
	t1.c = t0.c;
	/*
		COLOR CODE
	*/
	if (t1.a.x < ofGetWindowWidth() / 2 && t1.a.y > ofGetWindowHeight() / 2)
		t1.color = ofVec3f(0, ofRandom(255), 0);
	else if (t1.a.x < ofGetWindowWidth() / 2 && t1.a.y < ofGetWindowHeight() / 2)
		t1.color = ofVec3f(ofRandom(255), 0, 0);
	else if (t1.a.y < ofGetWindowHeight() / 2)
		t1.color = ofVec3f(0, 0, ofRandom(255));
	/*
		End Color code
	*/


	t2.a = t0.a;
	t2.b = t.b;
	t2.c = t0.b;
	/*
	COLOR CODE
	*/
	if (t2.a.x < ofGetWindowWidth() / 2 && t2.a.y > ofGetWindowHeight() / 2)
		t2.color = ofVec3f(0, ofRandom(255), 0);
	else if (t2.a.x > ofGetWindowWidth() / 2 && t2.a.y > ofGetWindowHeight() / 2)
		t2.color = ofVec3f(ofRandom(255), 0, 0);
	else if (t2.a.y < ofGetWindowHeight() / 2)
		t2.color = ofVec3f(0, 0, ofRandom(255));
	/*
	End Color code
	*/

	
	t3.a = t0.c;
	t3.b = t0.b;
	t3.c = t.c;

	/*
	COLOR CODE
	*/
	if (t3.a.x < ofGetWindowWidth() / 2 && t3.a.y > ofGetWindowHeight() / 2)
		t3.color = ofVec3f(0, ofRandom(255), 0);
	else if (t3.a.x > ofGetWindowWidth() / 2 && t3.a.y > ofGetWindowHeight() / 2)
		t3.color = ofVec3f(ofRandom(255), 0, 0);
	else if (t3.a.y < ofGetWindowHeight() / 2)
		t3.color = ofVec3f(0, 0, ofRandom(255));
	/*
	End Color code
	*/

	this->triangles.push_back(t1);
	this->triangles.push_back(t2);
	this->triangles.push_back(t3);

}

void Fractal::setup() {

	t.a = ofVec3f(0, ofGetWindowHeight());
	t.b = ofVec3f(ofGetWindowWidth() *0.5, 0);
	t.c = ofVec3f(ofGetWindowWidth(), ofGetWindowHeight());
	t.color = ofVec3f(0, 0, 0);

	triangles.push_back(this->t);

}

void Fractal::draw()
{
	for each (Triangle t in triangles)
	{
		ofSetColor(t.color.x, t.color.y, t.color.z);

		ofDrawLine(t.c, t.a);
		ofDrawLine(t.b, t.c);
		ofDrawLine(t.a, t.b);
	}

}

void Fractal::update()
{
	if (time >= timeToAction) {
		
		if (tcount < 1000000) {
			
			findTriangles(triangles[tcount]);
			tcount++;
		}
		time = 0;
	}
	time++;
}
