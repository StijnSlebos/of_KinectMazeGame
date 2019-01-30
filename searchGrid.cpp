/*
 THE MAZE
 Stijn Slebos   &   Tijmen Smit
 */

#include "searchGrid.hpp"

searchGrid::searchGrid(){
    for (int i = 0; i < DIRECTIONS; i++) {
        dummy.setNeighbour((Directions)i, &dummy);
    }
    
    for (int x = 0; x < GRID_SIZE; x++) {
        for (int y = 0; y < GRID_SIZE; y++) {
            fakeGrid[x][y].setCoor(x,y);
        }
    }
    
    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            if (x > 0) {
                fakeGrid[x][y].setNeighbour(west, &fakeGrid[x - 1][y]);
            }
            else {
                fakeGrid[x][y].setNeighbour(west, &dummy);
            }
            if (x < GRID_SIZE - 1) {
                fakeGrid[x][y].setNeighbour(east, &fakeGrid[x + 1][y]);
            }
            else {
                fakeGrid[x][y].setNeighbour(east, &dummy);
            }
            if (y > 0) {
                fakeGrid[x][y].setNeighbour(north, &fakeGrid[x][y - 1]);
            }
            else {
                fakeGrid[x][y].setNeighbour(north, &dummy);
            }
            if (y < GRID_SIZE - 1) {
                fakeGrid[x][y].setNeighbour(south, &fakeGrid[x][y + 1]);
            }
            else {
                fakeGrid[x][y].setNeighbour(south, &dummy);
            }
        }
    }
}

class DistanceCompare {
public:
    bool operator()(searchGridElement const* a, searchGridElement const* b) const {
        return a->getDistance() > b->getDistance();
    }
};

void searchGrid::greedy(MazeGrid* boardCopy, int startX, int startY, int endX, int endY){
    // priority queue which sorts elements based on its manhattan distance to the
    // end (distance is a member of gridElement) for greedy search
    PriorityQueue<searchGridElement*, DistanceCompare> queue;
    
    searchGridElement* start_element = &fakeGrid[startX][startY];
    searchGridElement* end_element = &fakeGrid[endX][endY];
    
    start_element->visit();
    
    queue.push(start_element);
    
    bool found_end = false;
    
    while (!queue.empty()) {
        searchGridElement* current_element = queue.front();
        queue.pop();
        
        if (current_element == end_element) {
            end_element->mark();
            // found end, so stop
            
            while (current_element->hasParent()) {
                current_element = current_element->getParent();
                current_element->mark();
            }
            break;
        }
        
        for (int direction = 0; direction < DIRECTIONS; direction++) {
            if(!boardCopy->getElement(current_element->inGridX, current_element->inGridY)->hasWall((Directions)direction)&&
               !current_element->myNeighbours[direction]->visited)
            {
                searchGridElement* next_element = current_element->myNeighbours[direction];
                next_element->visit();
                next_element->setParent(current_element);
                next_element->setDistance(endX, endY);
                queue.push(next_element);
            }
        }
    }
}

void searchGrid::reset(){
    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            fakeGrid[x][y].visited = false;
            fakeGrid[x][y].marked = false;
            fakeGrid[x][y].distance = 0;
            fakeGrid[x][y].parent = nullptr;          
        }
    }
}
