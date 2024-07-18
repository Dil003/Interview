// OOP Game Project
// Dragon Game
// GreenEGG.cpp executes the constructor and behaviours of the GreenEGG class

#include "Grid.h"
#include "GreenEGG.h"

// Impimentation of the defult GreenEGG Constructor
GreenEGG::GreenEGG(){
    gE_x = 20/4;
    gE_y = 20/4;
    gE_symbol = 'G';
}

// Impimentation of the Green egg Constructor that accepts an (x,y) coordinate and a symbol (G) as a Green egg
GreenEGG::GreenEGG(int gE_x, int gE_y, char gE_symbol){
    this -> gE_x = gE_x;
    this -> gE_y = gE_y;
    this -> gE_symbol = gE_symbol;
}

// GreenEGG behaviours
int GreenEGG::get_gE_x(){                 // gets x coordinate of gE
    return gE_x;
}

int GreenEGG::get_gE_y(){                 // gets y coordinate of gE
    return gE_y;
}

char GreenEGG::get_gE_symbol(){           // gets character/symbol of gE
    return gE_symbol;
}

void GreenEGG::set_gE_x(int gE_x){        // sets x coordinate of gE
    this -> gE_x = gE_x;
}

void GreenEGG::set_gE_y(int gE_y){        // sets y coordinate of gE
    this -> gE_y = gE_y;
}

// Here is the Destructor
GreenEGG::~GreenEGG(){
}