// OOP Game Project
// Dragon Game
// BlueEGG.cpp executes the Constructor and behaviours of the BlueEGG class

#include "Grid.h"
#include "BlueEGG.h"

// Impimentation of the defult BlueEGG Constructor
BlueEGG::BlueEGG(){
    bE_x = 20/4;                      
    bE_y = 20/4;
    bE_symbol = 'B';
}

// Impimentation of the Blue egg Constructor that accepts an (x,y) coordinate and a symbol (B) as a Blue egg
BlueEGG::BlueEGG(int bE_x, int bE_y, char bE_symbol){
    this -> bE_x = bE_x;
    this -> bE_y = bE_y;
    this -> bE_symbol = bE_symbol;
}

// BlueEGG behaviours
int BlueEGG::get_bE_x(){                        // gets x coordinate of Blue egg
    return bE_x;
}

int BlueEGG::get_bE_y(){                        // gets y coordinate of Blue egg
    return bE_y;
}

char BlueEGG::get_bE_symbol(){                  // gets character/symbol of Blue egg
    return bE_symbol;
}

void BlueEGG::set_bE_x(int bE_x){               // sets x coordinate of Blue egg Blue egg
    this -> bE_x = bE_x;
}

void BlueEGG::set_bE_y(int bE_y){               // sets y coordinate of Blue egg
    this -> bE_y = bE_y;
}

// Here is the Destructor
BlueEGG::~BlueEGG(){
}