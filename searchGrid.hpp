/*
 THE MAZE
 Stijn Slebos   &   Tijmen Smit
 */

#ifndef searchGrid_hpp
#define searchGrid_hpp

#include <stdio.h>
#include "MazeGrid.hpp"
#include "PriorityQueue.h"
#include "searchGridElement.hpp"

class searchGrid{
public:
    searchGrid();
    
    void greedy(MazeGrid*, int,int,int,int);
    void reset();
    searchGridElement fakeGrid[GRID_SIZE][GRID_SIZE];
    searchGridElement dummy;
};
#endif /* searchGrid_hpp */
