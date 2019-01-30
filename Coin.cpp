//
//  Coin.cpp
//  The_Maze v2
//
//  Created by Stijn on 23/01/2019.
//

#include "Coin.hpp"
#include "ofMain.h"
#include <stdio.h>

coin::coin(){

    x = std::rand()%GRID_SIZE;
    y = std::rand()%GRID_SIZE;
}

void coin::draw(){
    ofPushMatrix();
    ofTranslate(x*GRID_ELEMENT_SIZE+GRID_ELEMENT_SIZE/2, y*GRID_ELEMENT_SIZE+GRID_ELEMENT_SIZE/2);
    ofSetColor(200, 200, 0);
    ofDrawEllipse(0, 0, GRID_ELEMENT_SIZE*3/4, GRID_ELEMENT_SIZE*3/4);
    ofSetColor(200, 170, 0);
    ofDrawEllipse(0, 0, GRID_ELEMENT_SIZE*3/5, GRID_ELEMENT_SIZE*3/5);
    ofPopMatrix();
}

bool coin::isCollision(int otherX, int otherY){
    if(x==otherX && y == otherY){
        return true;
    }else {
        return false;
    }
}

void coin::newLocation(){
    x = std::rand()%GRID_SIZE;
    y = std::rand()%GRID_SIZE;
}
