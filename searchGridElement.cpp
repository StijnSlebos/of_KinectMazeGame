/*
 THE MAZE
 Stijn Slebos   &   Tijmen Smit
 */

#include "searchGridElement.hpp"

searchGridElement::searchGridElement(){
    visited = false;
    marked = false;
    distance = 0;
}

//NEIGHBOUR
void searchGridElement::setNeighbour(Directions direction, searchGridElement* grid){
    myNeighbours[direction] = grid;
}

searchGridElement* searchGridElement::getNeighbour(Directions direction){
    return (myNeighbours[direction]);
}

void searchGridElement::setCoor(int x, int y){
    inGridX = x;
    inGridY = y;
}

//DISTANCE
void searchGridElement::setDistance(int x, int y){
    distance = abs(x-inGridX)+abs(y-inGridY);
}

int searchGridElement::getDistance() const{
    return distance;
}

//PARENTS
bool searchGridElement::hasParent() const {
    return parent != nullptr;
}

searchGridElement* searchGridElement::getParent() const {
    return parent;
}

void searchGridElement::setParent(searchGridElement* parent) {
    this->parent = parent;
}

//BOOL OPERATORS
void searchGridElement::visit(){
    visited = true;
}

void searchGridElement::mark(){
    marked = true;
}

void searchGridElement::unmark(){
    marked = false;
}

