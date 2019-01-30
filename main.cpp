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

#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofSetupOpenGL(MAZE_SIZE, MAZE_SIZE, OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
