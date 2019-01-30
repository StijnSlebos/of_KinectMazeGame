/*
 THE MAZE
 Stijn Slebos   &   Tijmen Smit
 */

#ifndef GridElement_hpp
#define GridElement_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Konstant.h"
#include "Directions.hpp"

class gridElement{
public:
    gridElement();
    void setCoor(int [2]);
    void draw();
    
    void setNeighbour(Directions,gridElement*);
    bool getNeighbourMark(Directions);

    void setVisibility(bool);
 
    void setWalls(Directions);
    void removeWalls(Directions);
    void drawWalls();

    void setMarker(bool);
    
    bool checkMouse(int,int);
    bool checkMouseAtDist(int,int,int);
    bool hasBorders(Directions);
    bool hasWall(Directions);
    bool on; //Reason:
    
private:
    int gridLocation[2]; //0=x,1=y
    bool hasWalls [DIRECTIONS];
    bool marked;
    gridElement* myNeighbours[DIRECTIONS];
};

#endif /* GridElement_hpp */
