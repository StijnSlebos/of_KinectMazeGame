/*
 THE MAZE
 Stijn Slebos   &   Tijmen Smit
 */

#include "gameManager.hpp"

gameManager::gameManager(){
        for(int i = 0; i<ENEMIES ; i++){
        ally[i].setGrid(&grid);
    }
    ofTrueTypeFont::setGlobalDpi(72);
    verdana30.load("verdana.ttf", 30, true, true);
    verdana10.load("verdana.ttf", 10, true, true);
    enemySpeed = 1000;
}

void gameManager::update(){
    if(!isEnd){
    player.update(grid.getElement(player.inGridLocation[0], player.inGridLocation[1]));
    //Give the player a pointer to the information about his location in the grid.
    
    if(ofGetElapsedTimeMillis()>allyTimer){ //Timer
        for(int i = 0; i<ENEMIES ; i++){
            ally[i].update(ally[(i+1)%2].getLocation(0), ally[(i+1)%2].getLocation(1));
            ally[i].updateRoute(player.inGridLocation[0], player.inGridLocation[1]);
            
            if(ally[i].isCollision(player.inGridLocation[0], player.inGridLocation[1])){
                isEnd = true;
            }
        }
        allyTimer = ofGetElapsedTimeMillis()+enemySpeed;
    }
        score++;
    if(theCoin.isCollision(player.inGridLocation[0], player.inGridLocation[1])){
        score+= 2000;
        coinTimer = ofGetElapsedTimeMillis()+25000;
        theCoin.newLocation();
        if(enemySpeed >250){
            enemySpeed = enemySpeed *0.9;}
    }
    if(ofGetElapsedTimeMillis()>coinTimer){
            coinTimer = ofGetElapsedTimeMillis()+25000;
            theCoin.newLocation();
        if(enemySpeed >250){
            enemySpeed = enemySpeed *0.9;}
        }
        
    
    }
}

void gameManager::draw(){
    if(!isEnd){
    grid.draw();
    player.draw();
    theCoin.draw();

    for(int i = 0; i<ENEMIES ; i++){
        ally[i].draw();
    }
    
    ofSetColor(255);
    verdana10.drawString(to_string(score), (MAZE_SIZE) - 50, 15);
    }else{
    drawEndScreen();
    }
}

void gameManager::kinectUpdate(bool samples[GRID_SIZE][GRID_SIZE]){
    grid.update(samples);
}

void gameManager::getInput(int input){
    switch(input){
        case 'w':
            player.move(north, grid.getElement(player.inGridLocation[0], player.inGridLocation[1]));
            break;
        case 'd':
            player.move(east, grid.getElement(player.inGridLocation[0], player.inGridLocation[1]));
            break;
        case 's':
            player.move(south, grid.getElement(player.inGridLocation[0], player.inGridLocation[1]));
            break;
        case 'a':
            player.move(west, grid.getElement(player.inGridLocation[0], player.inGridLocation[1]));
            break;
        default:
            break;
    }
}

void gameManager::drawEndScreen()
{
    ofSetColor(255, 255, 0);
    ofDrawRectangle(GRID_ELEMENT_SIZE * 2.5, GRID_ELEMENT_SIZE * 2.5, MAZE_SIZE - GRID_ELEMENT_SIZE * 5, MAZE_SIZE - GRID_ELEMENT_SIZE * 5);
    ofSetColor(0);
    verdana30.setLineHeight(30);
    verdana30.setLetterSpacing(1.037);
    verdana30.drawString("GAME FINISHED!", (MAZE_SIZE/2) - 135, (MAZE_SIZE/2) - 50);
    verdana30.drawString("You scored:", (MAZE_SIZE / 2) - 100, (MAZE_SIZE / 2) + 10);
    verdana30.drawString(to_string(score), (MAZE_SIZE/2) - 50, (MAZE_SIZE/2) + 40);
}

void gameManager::resetGame(){
 //   grid = MazeGrid(); // this results in a move bug for now, maybe the grid needs to be de-allocated
    
    isEnd = false;
    score = 0;
    
    player.reset();
    theCoin.newLocation();
    
    for(int i = 0; i<ENEMIES ; i++){
        ally[i].reset();
        ally[i].setGrid(&grid);
    }
    
}
