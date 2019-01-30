/*
 THE MAZE
 Stijn Slebos   &   Tijmen Smit
 */

#include "Enemy.hpp"

enemy::enemy(){
    inGridX = std::rand()%GRID_SIZE;
    inGridY = std::rand()%GRID_SIZE;
    facedDirection = east;
    stepcounter = 4;
    maxCount = 3;
}

void enemy::setGrid(MazeGrid* copy){
    playfield = copy;
}

void enemy::draw(){
    ofPushMatrix();
    ofTranslate(inGridX*GRID_ELEMENT_SIZE+GRID_ELEMENT_SIZE/2, inGridY*GRID_ELEMENT_SIZE+GRID_ELEMENT_SIZE/2);
    
    ofFill();
    ofSetLineWidth(1);
    switch (facedDirection)
    {
        case east:
            ofSetColor(0, 0, 0, 255); //Black
            ofDrawRectangle(-3, -6, 4, 1);
            ofDrawRectangle(-3, -6, 1, 3);
            ofDrawRectangle(1, -6, 1, 2);
            ofDrawRectangle(-3, 6, 2, 1);
            ofDrawRectangle(-1, 6, 2, 1);
            ofSetColor(30, 180, 30, 255); //Green
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
            ofSetColor(30, 180, 30, 255); //Green
            ofDrawRectangle(-3, -2, 3, 5);
            ofDrawRectangle(-4, -1, 1, 2);
            ofSetColor(198, 156, 109, 255); //Skintone
            ofDrawRectangle(-4, -5, 3, 3);
            ofDrawRectangle(-4, 1, 1, 1);
            ofDrawRectangle(-2, 1, 1, 1);
            break;
        default:
            ofSetColor(30, 180, 30, 255); //Green
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

void enemy::update(int otherX, int otherY){
    myAI.fakeGrid[inGridX][inGridY].unmark();
    for(int directions = 0; directions < DIRECTIONS; directions ++ ){
        if(myAI.fakeGrid[inGridX][inGridY].getNeighbour((Directions)directions)->marked &&
           !playfield->getElement(inGridX, inGridY)->hasWall((Directions)directions) &&
           !(enemyInDirection((Directions)directions, otherX, otherY))){
            move((Directions)directions);
            facedDirection = (Directions)directions;
            break;
        }
    }  
}

bool enemy::enemyInDirection(Directions direction, int otherX, int otherY){
    if((direction == north && otherY == inGridY-1 && otherX == inGridX) ||
       (direction == east && otherX == inGridX+1 && otherY == inGridY) ||
       (direction == south && otherY == inGridY+1 && otherX == inGridX) ||
       (direction == west && otherX == inGridX-1 && otherY == inGridY)){
        return true;
    }else {
        return false;
    }
}

void enemy::move(Directions direction){
    if(direction == north){
        inGridY -=1;
    }else if(direction == east){
        inGridX +=1;
    }else if(direction == south){
        inGridY +=1;
    }else if(direction == west){
        inGridX -=1;
    }
}

void enemy::updateRoute(int playerX, int playerY){
    stepcounter ++;
    if(stepcounter>maxCount){
    myAI.reset();
    stepcounter = 0;
    myAI.greedy(playfield, inGridX, inGridY, playerX, playerY);
    myAI.fakeGrid[inGridX][inGridY].unmark();
        }
}

int enemy::getLocation(int val){
    if(val == 0){
        return inGridX;
    }else if(val == 1){
        return inGridY;
    }
    
}

bool enemy::isCollision(int otherX, int otherY){
    if(inGridX==otherX && inGridY == otherY){
        return true;
    }else {
        return false;
    }
}

void enemy::reset(){
    inGridX = std::rand()%GRID_SIZE;
    inGridY = std::rand()%GRID_SIZE;
}

