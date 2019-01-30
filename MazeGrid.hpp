/*
 THE MAZE
 Stijn Slebos   &   Tijmen Smit
 */

#ifndef MazeGrid_hpp
#define MazeGrid_hpp

#include <stdio.h>
#include "GridElement.hpp"

class MazeGrid{
public:
    MazeGrid();
    void draw();
    void update(bool[GRID_SIZE][GRID_SIZE]);
    void clickOn(int, int);
    void doMove(Directions);
    
    gridElement* getElement(int, int);
    
private:
    int loc[GRID_SIZE][GRID_SIZE][2];
    gridElement gridElements[GRID_SIZE][GRID_SIZE];
    gridElement myGrid[GRID_SIZE*GRID_SIZE];
    gridElement dummy;
    bool doesKinect;
};

#endif /* MazeGrid_hpp */
