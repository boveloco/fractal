#ifndef __FRACTALD__
#define __FRACTALD__

#include <vector>
#include "ofMain.h"

class Fractal : public ofBaseApp
{
public:
	float timeToAction = 0;

	struct Triangle
	{
		ofVec3f a;
		ofVec3f b;
		ofVec3f c;
		ofVec3f color;
	};

	Fractal();
	~Fractal();


	inline void findTriangles(ofVec3f a, ofVec3f b, ofVec3f c);
	inline void findTriangles(Triangle t);

	void setup() override;
	void draw() override;
	void update() override;

private:
	
	std::vector<Triangle> triangles;

	float time = 0;
	int tcount = 0;
	int tcount2 = 0;
	Triangle t;
};

#endif