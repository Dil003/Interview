// OOP Game Project
// Dragon Game

#include "Grid.h"
#include "Dragon.h"

// Implimentation of defult Dragon constructor
Dragon::Dragon(){
    dragon_x = 20/2;
    dragon_y = 20/2;
    dragon_speed = 1;
    dragon_symbol = 'D';
    dragon_dir = 'O';                                            // inital direction of dragon is 'O'= undefined
}

// Implimentation of Dragon constructor that accepts x amd y coordinates and a character/symbol
Dragon::Dragon(int dragon_x, int dragon_y, char dragon_symbol){
    this -> dragon_x = dragon_x;
    this -> dragon_y = dragon_y;
    dragon_speed = 1;
    this -> dragon_symbol = dragon_symbol;
    dragon_dir = 'O';                                            // inital direction of dragon is undefined
}

// Implementation of Dragon behaviours
void Dragon::set_dragon_dir(char dir){                            // set the dragons direction
    dragon_dir = dir;
}

int Dragon::get_dragon_x(){                                       // get current x coordinate of dragon
    return dragon_x;
}

int Dragon::get_dragon_y(){                                       // get current y coordinate of dragon
    return dragon_y;
}

char Dragon::get_dragon_symbol(){                                 // get symbol of the dragon
    return dragon_symbol;
}

void Dragon::set_dragon_x(int dragon_x){                           // set the x coordinate of dragon
    this -> dragon_x = dragon_x;
}

void Dragon::set_dragon_y(int dragon_y){                       // set the y coordinate of dragon
    this -> dragon_y = dragon_y;
}



// Destructor
Dragon::~Dragon(){
}
