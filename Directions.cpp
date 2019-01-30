/*
            THE MAZE
 Stijn Slebos   &   Tijmen Smit
 */

#include "Directions.hpp"

Directions oppositeDirection(Directions direction) {
    switch (direction) {
        case north:
            return south;
            
        case east:
            return west;
            
        case south:
            return north;
            
        case west:
            return east;
    }
    return north;
}
