#pragma once

#include "ofMain.h"
#include "ofxGstV4L2Sink.h"
class testApp : public ofBaseApp{
    protected:
        ofVideoGrabber vidGrab;
	ofImage img;
        ofImage cFrame;
        ofPoint camSize;
        bool newFrame;
	bool newFrameTwo;
        bool doReset;
        bool doCapture;
        bool mirrorToggle;
        bool flipToggle;
        int lastCap;
        int capTime;
	int redOne;
	int redTwo;
	int greenOne;
	int greenTwo;
	int blueOne;
	int blueTwo;
        int alphaOne;
        int alphaTwo;
        void captureScreen();

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

};
