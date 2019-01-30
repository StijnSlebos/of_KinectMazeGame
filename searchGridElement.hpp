/*
 THE MAZE
 Stijn Slebos   &   Tijmen Smit
 */

#ifndef searchGridElement_hpp
#define searchGridElement_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Directions.hpp"

class searchGridElement{
public:
    searchGridElement();
    
    void setNeighbour(Directions,searchGridElement*);
    searchGridElement* getNeighbour(Directions);
    void setCoor(int, int);
    
    void setDistance(int, int);
    int getDistance() const;
    
    void visit();
    void mark();
    void unmark();
    
    bool hasParent() const;
    searchGridElement* getParent() const;
    void setParent(searchGridElement*);
    
    int inGridX, inGridY;
    int distance;
    
    bool visited, marked;
    searchGridElement* parent;
    searchGridElement*  myNeighbours [DIRECTIONS];
};
#endif /* searchGridElement_hpp */
