/*
 THE MAZE
 Kinnect game.
 
 THU 22/01/2019
 
 Made by:
 Stijn Slebos
 &
 Tijmen Smit
 
 Programming and AI
 Creative Technology
 University of Twente
 */

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //---------------------KINECT_PART_START--------------------------//
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    // enable depth->video image calibration
    kinect.setRegistration(true);
    
    //kinect.init();
    //kinect.init(true); // shows infrared instead of RGB video image
    kinect.init(false, false); // disable video image (faster fps)
    
    kinect.open();        // opens first available kinect
    // print the intrinsic IR sensor values
    if(kinect.isConnected()) {
        ofLogNotice() << "sensor-emitter dist: " << kinect.getSensorEmitterDistance() << "cm";
        ofLogNotice() << "sensor-camera dist:  " << kinect.getSensorCameraDistance() << "cm";
        ofLogNotice() << "zero plane pixel size: " << kinect.getZeroPlanePixelSize() << "mm";
        ofLogNotice() << "zero plane dist: " << kinect.getZeroPlaneDistance() << "mm";
    }
    
    grayImage.allocate(kinect.width, kinect.height);
    grayThreshNear.allocate(kinect.width, kinect.height);
    grayThreshFar.allocate(kinect.width, kinect.height);
    
    nearThreshold = 200; //0-255
    farThreshold = 130; //0-255
    
    ofSetFrameRate(40);
    
    // 20 the tilt on startup
    angle = 5;
    kinect.setCameraTiltAngle(angle);
    //---------------------KINECT_PART_END--------------------------//
}

//--------------------------------------------------------------
void ofApp::update(){
    game.update();
    
    //---------------------KINECT_PART_START--------------------------//
    //ofBackground(100, 100, 100);
    kinect.update();
    
    // there is a new frame and we are connected
    if(kinect.isFrameNewDepth()) {
        // load grayscale depth image from the kinect source
        grayImage.setFromPixels(kinect.getDepthPixels()); // OpenCV pixel manegment
        ofPixels & pix = grayImage.getPixels();
        int numPixels = pix.size();
        
        for(int i = 0; i < numPixels; i++) {
            if(pix[i] < nearThreshold && pix[i] > farThreshold) {
                pix[i] = 255;
            } else {
                pix[i] = 0;
            }
        }
        for (int x = 0; x < GRID_SIZE; x++) for (int y = 0; y < GRID_SIZE; y++)
        {
            samples[x][y] = pix[GRID_SIZE*640+95+(640)*(y*15+8)+x*15+8] == 255;
        }
        game.kinectUpdate(samples); //Send samples to the gameboard.
        
        // update and mirror the cv images for contour finder
        grayImage.getPixels().mirror(false, true);
        grayImage.flagImageChanged();
        contourFinder.findContours(grayImage, 10, (kinect.width*kinect.height)/2, 20, false);
    }
    //---------------------KINECT_PART_END--------------------------//
}

//--------------------------------------------------------------
void ofApp::draw(){
    game.draw();
}

void ofApp::exit() {
    //---------------------KINECT_PART_START--------------------------//
    kinect.setCameraTiltAngle(0); // zero the tilt on exit
    kinect.close();
    //---------------------KINECT_PART_END--------------------------//
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch(key){
            
        case 'r':
            game.resetGame();
            break;
            
        case 'w':
        case 'd':
        case 's':
        case 'a':
            game.getInput(key); //Move the player.
            break;
            
            //KINECT
        case '>':
        case '.':
            farThreshold ++;
            if (farThreshold > 255) farThreshold = 255;
            break;
            
        case '<':
        case ',':
            farThreshold --;
            if (farThreshold < 0) farThreshold = 0;
            break;
            
        case '+':
        case '=':
            nearThreshold ++;
            if (nearThreshold > 255) nearThreshold = 255;
            break;
            
        case '-':
            nearThreshold --;
            if (nearThreshold < 0) nearThreshold = 0;
            break;
            
        case 'o':
            kinect.setCameraTiltAngle(angle); // go back to prev tilt
            kinect.open();
            break;
            
        case 'c':
            kinect.setCameraTiltAngle(0); // zero the tilt
            kinect.close();
            break;
            
        case OF_KEY_UP:
            angle++;
            if(angle>30) angle=30;
            kinect.setCameraTiltAngle(angle);
            break;
            
        case OF_KEY_DOWN:
            angle--;
            if(angle<-30) angle=-30;
            kinect.setCameraTiltAngle(angle);
            break;
        default:
            break;
    }
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
