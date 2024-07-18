// OOP Game Project
// Dragon Game
// RedEGG.cpp executes the constructor and behaviours of the RedEGG class

#include "Grid.h"
#include "RedEGG.h"

// Impimentation of the defult RedEGG Constructor
RedEGG::RedEGG(){
    rE_x = 20/4;                      
    rE_y = 20/4;
    rE_symbol = 'R';
}

// Impimentation of the Red egg Constructor that accepts an (x,y) coordinate and a symbol (R) as a Red egg
RedEGG::RedEGG(int rE_x, int rE_y, char rE_symbol){
    this -> rE_x = rE_x;
    this -> rE_y = rE_y;
    this -> rE_symbol = rE_symbol;
}

// RedEGG behaviours
int RedEGG::get_rE_x(){                        // gets x coordinate of Red egg
    return rE_x;
}

int RedEGG::get_rE_y(){                        // gets y coordinate of Red egg
    return rE_y;
}

char RedEGG::get_rE_symbol(){                  // gets character/symbol of Red egg
    return rE_symbol;
}

void RedEGG::set_rE_x(int rE_x){               // sets x coordinate of Red egg Red egg
    this -> rE_x = rE_x;
}

void RedEGG::set_rE_y(int rE_y){               // sets y coordinate of Red egg
    this -> rE_y = rE_y;
}

// Destructor
RedEGG::~RedEGG(){
}
