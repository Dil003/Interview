// OOP Game Project
// Dragon Game
// OrangeEGG.cpp executes the constructor and behaviours of the OrangeEGG class

#include "Grid.h"
#include "OrangeEGG.h"

// Impimentation of the defult OrangeEGG Constructor
OrangeEGG::OrangeEGG(){
    oE_x = 20/4;
    oE_y = 20/4;
    oE_symbol = 'O';
}

// Impimentation of the Orange egg Constructor that accepts an (x,y) coordinate and a symbol (O) as a Orange egg
OrangeEGG::OrangeEGG(int oE_x, int oE_y, char oE_symbol){
    this -> oE_x = oE_x;
    this -> oE_y = oE_y;
    this -> oE_symbol = oE_symbol;
}

// OrangeEGG behaviours
int OrangeEGG::get_oE_x(){                // gets x coordinate of baby OrangeEGG
    return oE_x;
}

int OrangeEGG::get_oE_y(){                // gets y coordinate of baby OrangeEGG
    return oE_y;
}

char OrangeEGG::get_oE_symbol(){          // gets character/symbol of baby OrangeEGG
    return oE_symbol;
}

void OrangeEGG::set_oE_x(int oE_x){       // sets x coordinate of baby OrangeEGG 
    this -> oE_x = oE_x;
}

void OrangeEGG::set_oE_y(int oE_y){       // sets y coordinate of baby OrangeEGG
    this -> oE_y = oE_y;
}

// Here is the Destructor
OrangeEGG::~OrangeEGG(){
}