#include "ofApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	//set cam capture resolution
    camSize.x = 640;
    camSize.y = 480;
	//set framerate
    ofSetFrameRate(50);
    vidGrab.setVerbose(true);
    //set camera Device number and framerate
    //vidGrab.setDeviceID(1); 
    //vidGrab.setDesiredFrameRate(50);

    ofSetBackgroundAuto(false);
    ofBackground(0, 0, 0);
    ofEnableAlphaBlending();
    
    vidGrab.initGrabber(camSize.x, camSize.y);
    
    cFrame.allocate(camSize.x, camSize.y, OF_IMAGE_COLOR);

    mirrorToggle = true;
    flipToggle = false;
    newFrame = false;
    newFrameTwo = false;
    doReset = false;
    doCapture = false;
    redOne = 255;
    greenOne = 255;
    blueOne = 255;
    redTwo = 0;
    greenTwo = 0;
    blueTwo = 0; 
    alphaOne = 6;
    alphaTwo = 1;
    lastCap = -1;
    capTime = 30*1000;
}

void testApp::captureScreen(){
    stringstream capName;
    capName << "captures/lightWriter_" << ((ofGetYear() < 10)?"0":"") << ofGetYear() << ((ofGetMonth() < 10)?"0":"") << ofGetMonth() << ((ofGetDay() < 10)?"0":"") << ofGetDay() << "_" << ((ofGetHours() < 10)?"0":"") << ofGetHours() << ((ofGetMinutes() < 10)?"0":"") << ofGetMinutes() << ((ofGetSeconds() < 10)?"0":"") << ofGetSeconds() << ".jpg";

    ofImage screenCap;
    screenCap.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
    screenCap.saveImage(capName.str());

    capName.str("");
}

//--------------------------------------------------------------
void testApp::update(){
   newFrame = false;
   vidGrab.update();
    if(vidGrab.isFrameNew()){
	//send cam to array
	cFrame.setFromPixels(vidGrab.getPixels(), vidGrab.getWidth(), vidGrab.getHeight(), OF_IMAGE_COLOR);
	//flip and mirror image toggles  
	cFrame.mirror(flipToggle, mirrorToggle);
	//set new frame
	newFrame = true;   
}



/*
newFrameTwo = false;

    vidGrabTwo.update();
    if(vidGrabTwo.isFrameNew()){
        cFrameTwo.setFromPixels(vidGrabTwo.getPixels(), vidGrabTwo.getWidth(), vidGrabTwo.getHeight(), OF_IMAGE_COLOR);
        cFrameTwo.mirror(flipToggle, mirrorToggle);

        newFrameTwo = true;
    }
*/


    int cTime = ofGetElapsedTimeMillis();
    if(lastCap == -1 || (cTime - lastCap) >= capTime){
        doCapture = true;
     //   doReset = true;
        lastCap = cTime;
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    if(doCapture){
        captureScreen();
        doCapture = false;
    }

    if(doReset){
        ofBackground(0, 0, 0);
        doReset = false;
    }

    if(newFrame){
        glBlendEquation(GL_MAX);
        ofSetColor(redOne, greenOne, blueOne, alphaOne); // the first magick numbers
        cFrame.draw(0, 0, ofGetWidth(), ofGetHeight());
        glBlendEquation(GL_FUNC_ADD);
        ofSetColor(redTwo, greenTwo, blueTwo, alphaTwo); // the second magick numbers
        ofRect(0, 0, ofGetWidth(), ofGetHeight());
        ofSetColor(255, 255, 255, 255);
    }
	//display framerate
	//ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 10, 15);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    if(key == 'f' || key == 'F')
        ofToggleFullscreen();
    else if(key == 'v' || key == 'V')
        vidGrab.videoSettings();
    else if(key == ' ')
        doCapture = true;
    else if(key == 'm')
        mirrorToggle = !mirrorToggle;
    else if(key == 'n')
	flipToggle =!flipToggle;       

    else if(key == '.' && alphaTwo <= 255)
        alphaTwo++;
    else if(key == ',' && alphaTwo >= 0)
	alphaTwo--;

    else if(key == ']' && alphaOne <= 255)
	alphaOne++;
    else if(key == '[' && alphaOne >= 0)
	alphaOne--;
    
    else if(key == 'q' && redOne <= 255)
	redOne++;
    else if(key == 'a' && redOne >= 0)
	redOne--;
    
    else if(key == 'w' && greenOne <= 255)
	greenOne++;
    else if(key == 's' && greenOne >= 0)
	greenOne--;

    else if(key == 'e' && blueOne <= 255)
	blueOne++;
    else if(key == 'd' && blueOne >= 0)
	blueOne--;

    else if(key == 't' && redTwo <= 255)
	redTwo++;
    else if(key == 'g' && redTwo >= 0)
	redTwo--;

    else if(key == 'y' && greenTwo <= 255)
	greenTwo++;
    else if(key == 'h' && greenTwo >= 0)
	greenTwo--;

    else if(key == 'u' && blueTwo <= 255)
	blueTwo++;
    else if(key == 'j' && blueTwo >= 0)
	blueTwo--;



    //        else if(alphaOne > 255)
    //        alphaOne = 0;
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    doReset = true;
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
