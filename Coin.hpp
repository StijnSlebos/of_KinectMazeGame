//
//  Coin.hpp
//  The_Maze v2
//
//  Created by Stijn on 23/01/2019.
//

#ifndef Coin_hpp
#define Coin_hpp

#include <stdio.h>
#include "Konstant.h"

class coin{
public:
    coin();
    
    void draw();
    
    void newLocation();
    void getPicked();
    
    bool isCollision(int, int);
private:
    int x,y;
};



#endif /* Coin_hpp */
