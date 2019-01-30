/*
 THE MAZE
 Stijn Slebos   &   Tijmen Smit
 */

#ifndef gameManager_hpp
#define gameManager_hpp

#include <stdio.h>
#include "MazeGrid.hpp"
#include "inMazePlayer.hpp"
#include "Enemy.hpp"
#include "Coin.hpp"

#define ENEMIES 2

class gameManager{
public:
    gameManager();
    
    void update();
    void draw();
    void getInput(int); //Move Player
    void kinectUpdate(bool[GRID_SIZE][GRID_SIZE]); //Update the kinect Grid
    
    void drawEndScreen();
    void resetGame();
    
private:
    MazeGrid grid;
    inMazePlayer player;
    //enemy ally1;
    //enemy ally2;
    enemy ally[ENEMIES];
    int allyTimer;
    coin theCoin;
    
    //GameVariables
    ofTrueTypeFont verdana30;
    ofTrueTypeFont verdana10;
    
    int score, coinTimer, enemySpeed;
    bool isEnd;
};

#endif /* gameManager_hpp */
