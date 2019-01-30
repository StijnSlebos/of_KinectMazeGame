/*
 THE MAZE
 Stijn Slebos   &   Tijmen Smit
 */

#ifndef Directions_hpp
#define Directions_hpp

#include <stdio.h>

#define DIRECTIONS 4

enum Directions{
    north = 0,
    east = 1,
    south = 2,
    west = 3
};

Directions oppositeDirection(Directions);

#endif /* Directions_hpp */
