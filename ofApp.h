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

#pragma once

#include "gameManager.hpp"
#include "ofxOpenCv.h"
#include "ofxKinect.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void exit();


		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    //---------------------KINECT_PART_START--------------------------//
    
    ofxKinect kinect;
    
    ofxCvGrayscaleImage grayImage; // grayscale depth image
    ofxCvGrayscaleImage grayThreshNear; // the near thresholded image
    ofxCvGrayscaleImage grayThreshFar; // the far thresholded image
    ofxCvContourFinder contourFinder; // for debug only
    
    int nearThreshold;
    int farThreshold;
    
    bool samples[GRID_SIZE][GRID_SIZE]; // kinect value grid
    
    int angle;
    
    //---------------------KINECT_PART_END--------------------------//
		
    gameManager game;
};
