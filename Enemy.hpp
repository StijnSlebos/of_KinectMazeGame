/*
 THE MAZE
 Stijn Slebos   &   Tijmen Smit
 */

#ifndef Enemy_hpp
#define Enemy_hpp

#include <stdio.h>
#include "searchGrid.hpp"

class enemy{
public:
    enemy();
    
    void setGrid(MazeGrid*);
    
    void draw();
    void update(int,int);
    void updateRoute(int,int);
    void move(Directions);
     void reset();
    
    int getLocation(int);
    bool enemyInDirection(Directions, int, int);
    bool isCollision(int, int);
    
   
    
private:
    MazeGrid* playfield;
    int inGridX, inGridY;
    bool gridPath[GRID_SIZE][GRID_SIZE];
    Directions facedDirection;
    
    int stepcounter, maxCount;
    
    searchGrid myAI;
};



#endif /* Enemy_hpp */
