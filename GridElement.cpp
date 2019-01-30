/*
 THE MAZE
 Stijn Slebos   &   Tijmen Smit
 */

#include "GridElement.hpp"

gridElement::gridElement(){
    for(int i = 0; i<DIRECTIONS;i++){
        myNeighbours[i] = nullptr;
        hasWalls[i]=false;
    }
    on = false;    
}

void gridElement::setNeighbour(Directions direction,gridElement* gridElement){
   myNeighbours[direction] = gridElement;
}

bool gridElement::getNeighbourMark(Directions direction){
    return myNeighbours[direction]->marked;
}

void gridElement::setCoor(int loc[2]){
    gridLocation[0] = loc[0];
    gridLocation[1] = loc[1];
}

void gridElement::draw(){
    ofSetLineWidth(4);
    if(on){
        ofSetColor(50, int((gridLocation[0]*100)/MAZE_SIZE), 200-int((gridLocation[1]*100)/MAZE_SIZE));
    } else {
        ofSetColor(10);
    }
        ofDrawRectangle(gridLocation[0], gridLocation[1], GRID_ELEMENT_SIZE, GRID_ELEMENT_SIZE);
    if(on){ ofSetColor(255);
        drawWalls();
    }
}

void gridElement::drawWalls(){    
    if(hasWalls[0]){
        ofDrawLine(gridLocation[0], gridLocation[1], gridLocation[0]+GRID_ELEMENT_SIZE, gridLocation[1]);}
    if(hasWalls[1]){
        ofDrawLine(gridLocation[0]+GRID_ELEMENT_SIZE, gridLocation[1], gridLocation[0]+GRID_ELEMENT_SIZE, gridLocation[1]+GRID_ELEMENT_SIZE);}
    if(hasWalls[2]){
        ofDrawLine(gridLocation[0], gridLocation[1]+GRID_ELEMENT_SIZE, gridLocation[0]+GRID_ELEMENT_SIZE, gridLocation[1]+GRID_ELEMENT_SIZE);}
    if(hasWalls[3]){
        ofDrawLine(gridLocation[0], gridLocation[1], gridLocation[0], gridLocation[1]+GRID_ELEMENT_SIZE);}
}

void gridElement::setVisibility(bool set){
    on = set;
}

void gridElement::setMarker(bool mark){
    marked = mark;
}

bool gridElement::checkMouse(int x, int y){
    if(x>gridLocation[0] && x<gridLocation[0]+GRID_ELEMENT_SIZE && y>gridLocation[1] && y<gridLocation[1]+GRID_ELEMENT_SIZE){
        return true;
    }else {return false;}
}

bool gridElement::checkMouseAtDist(int x,int y,int dist){
    int diagonal = ofDist(gridLocation[0] + GRID_ELEMENT_SIZE/2, gridLocation[1] + GRID_ELEMENT_SIZE/2, x, y);
    if(diagonal<=dist){return true;}
}

void gridElement::setWalls(Directions direction){
    hasWalls[direction] = true;
    if(myNeighbours[direction]->hasWalls[oppositeDirection(direction)] == false){
        myNeighbours[direction]->setWalls(oppositeDirection(direction));
    }
}

void gridElement::removeWalls(Directions direction){
    hasWalls[direction] = false;
    if(myNeighbours[direction]->hasWalls[oppositeDirection(direction)] == true){
        myNeighbours[direction]->removeWalls(oppositeDirection(direction));
    }
}

bool gridElement::hasBorders(Directions direction){
    if(!myNeighbours[direction]->on || hasWall(direction)){return true;}else {return false;}
}

bool gridElement::hasWall(Directions direction){
    if(hasWalls[direction]){
        return true;}
    else{
        return false;}
}
