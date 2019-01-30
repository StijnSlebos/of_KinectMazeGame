/*
 THE MAZE
 Stijn Slebos   &   Tijmen Smit
 */

#ifndef inMazePlayer_hpp
#define inMazePlayer_hpp

#include <stdio.h>
#include "GridElement.hpp"

class inMazePlayer{
public:
    inMazePlayer();

    void update(gridElement*);
    void draw();
    void doNextMove(gridElement*, Directions);
    
    void move(Directions, gridElement*);
    void doMove(Directions);
    
    bool canMove(Directions,gridElement*);
    
    int inGridLocation[2];

    void reset();
        
private:
    Directions defineFacedDirection();
};


#endif /* inMazePlayer_hpp */
