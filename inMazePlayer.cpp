/*
 THE MAZE
 Stijn Slebos   &   Tijmen Smit
 */

#include "inMazePlayer.hpp"
#include "ofMain.h"

inMazePlayer::inMazePlayer(){
    inGridLocation[0] = GRID_SIZE/2;
    inGridLocation[1] = GRID_SIZE/2;
}

void inMazePlayer::update(gridElement* myLocation){
//    myLocation->setMarker(false);
//    for(int i = 0; i<DIRECTIONS;i++ ){
//        if(myLocation->getNeighbourMark((Directions)i)&&canMove((Directions)i, myLocation)){
//            doMove((Directions)i);
//            break;
//        }
//    }
}

void inMazePlayer::draw(){
    ofPushMatrix();
    ofTranslate(inGridLocation[0]*GRID_ELEMENT_SIZE+GRID_ELEMENT_SIZE/2, inGridLocation[1]*GRID_ELEMENT_SIZE+GRID_ELEMENT_SIZE/2);
    
    ofFill();
    ofSetLineWidth(1);
    switch (defineFacedDirection())
    {
     
        case east:
            ofSetColor(0, 0, 0, 255); //Black
            ofDrawRectangle(-3, -6, 4, 1);
            ofDrawRectangle(-3, -6, 1, 3);
            ofDrawRectangle(1, -6, 1, 2);
            ofDrawRectangle(-3, 6, 2, 1);
            ofDrawRectangle(-1, 6, 2, 1);
            ofSetColor(255, 0, 0, 255); //Red
            ofDrawRectangle(-3, -2, 3, 5);
            ofDrawRectangle(0, -1, 1, 2);
            ofSetColor(198, 156, 109, 255); //Skintone
            ofDrawRectangle(-2, -5, 3, 3);
            ofDrawRectangle(-2, 1, 1, 1);
            ofDrawRectangle(0, 1, 1, 1);
            break;
        case west:
            ofSetColor(0, 0, 0, 255); //Black
            ofDrawRectangle(-5, -6, 4, 1);
            ofDrawRectangle(-5, -6, 1, 2);
            ofDrawRectangle(-1, -6, 1, 3);
            ofDrawRectangle(-4, 6, 2, 1);
            ofDrawRectangle(-2, 6, 2, 1);
            ofSetColor(255, 0, 0, 255); //Red
            ofDrawRectangle(-3, -2, 3, 5);
            ofDrawRectangle(-4, -1, 1, 2);
            ofSetColor(198, 156, 109, 255); //Skintone
            ofDrawRectangle(-4, -5, 3, 3);
            ofDrawRectangle(-4, 1, 1, 1);
            ofDrawRectangle(-2, 1, 1, 1);
            break;
        default:
            ofSetColor(255, 0, 0, 255); //Red
            ofDrawRectangle(-3, -2, 3, 5);
            ofSetColor(198, 156, 109, 255); //Skintone
            ofDrawRectangle(-3, -5, 3, 3);
            ofDrawRectangle(-3, 1, 1, 1);
            ofDrawRectangle(-1, 1, 1, 1);
            ofSetColor(0, 0, 0, 255); //Black
            ofDrawRectangle(-4, -6, 4, 1);
            ofDrawRectangle(-4, -6, 1, 2);
            ofDrawRectangle(0, -6, 1, 2);
            ofDrawRectangle(-3, 6, 1, 1);
            ofDrawRectangle(-1, 6, 1, 1);
            break;
    }

    ofSetColor(49, 49, 146, 255); //Blue
    ofDrawRectangle(-3, 3, 1, 4);
    ofDrawRectangle(-1, 3, 1, 4);
    ofPopMatrix();
}


void inMazePlayer::doNextMove(gridElement* myLocation , Directions goToDirection){
    if(canMove(goToDirection, myLocation)){
        doMove(goToDirection);
    }
}

void inMazePlayer::move(Directions direction, gridElement* myLocation){
    if(canMove(direction, myLocation)){
        doMove(direction);
    }
}

void inMazePlayer::doMove(Directions direction){
    if(direction == north){
        inGridLocation[1] -=1;
    }else if(direction == east){
        inGridLocation[0] +=1;
    }else if(direction == south){
        inGridLocation[1] +=1;
    }else if(direction == west){
        inGridLocation[0] -=1;
    }
}

bool inMazePlayer::canMove(Directions direction, gridElement* myLocation){
    bool test = !(myLocation->hasBorders(direction)); //Check for border in direction
    if(test){
        return true;
    }else{
        return false;
    }
}

Directions inMazePlayer::defineFacedDirection(){
    int x,y;
    x = inGridLocation[0]*GRID_ELEMENT_SIZE+GRID_ELEMENT_SIZE/2;
    y = inGridLocation[1]*GRID_ELEMENT_SIZE+GRID_ELEMENT_SIZE/2;
    if(ofGetMouseY() < y && abs(ofGetMouseY()-y) > abs(ofGetMouseX()-x)){
        return north;
    }
    if(ofGetMouseX() > x && abs(ofGetMouseY()-y) < abs(ofGetMouseX()-x)){
        return east;
    }
    if(ofGetMouseY() > y && abs(ofGetMouseY()-y) > abs(ofGetMouseX()-x)){
        return south;
    }
    if(ofGetMouseX() < x && abs(ofGetMouseY()-y) < abs(ofGetMouseX()-x)){
        return west;
    }
}

void inMazePlayer::reset(){
    inGridLocation[0] = GRID_SIZE/2;
    inGridLocation[1] = GRID_SIZE/2;
}
