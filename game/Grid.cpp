// OOP Game Project
// Dragon Game
// Grid.cpp implements the constructors and behaviours of the Grid class.

#include <iostream>
#include "Grid.h"
#include "Dragon.h"
#include "OrangeEGG.h"
#include "GreenEGG.h"
#include "BlueEGG.h"
#include "RedEGG.h"

// defult Grid constructor setting the size of the field on terminal and inialising variables
Grid::Grid(){
    rows = 20;
    cols = 20;
    dragon_list = nullptr; // setting all the lists to nothing 
    oE_list = nullptr;
    gE_list = nullptr;
    bE_list = nullptr;
   array = &p; // declare the double pointer of array as the adreess of the p pointer to inisliase
}

// takes parameters row and cols and fills the grid with empty space of ' '.
Grid::Grid(int rows, int cols){
    this -> rows = rows;
    this -> cols = cols;

    // Create new array
    array = new char*[rows];
    for (int i = 0; i < rows; i++){
        array[i] = new char[cols];
    }

    // Fill array with '.'
    for (int i = 0; i < rows; i ++){
        for (int j = 0; j < cols; j++){
            array[i][j] = ' ';
        }
    }
}


// Grid behaviours
Dragon* Grid::get_dragon(){                           // return Dragon pointer
    return dragon_list;
}

Dragon* Grid::set_dragon(Dragon* dragon){               // set Dragon pointer
    dragon_list = dragon;
    return dragon_list;
}

OrangeEGG* Grid::get_oE(){                       // return OrangeEGG pointer
    return oE_list;
}

OrangeEGG* Grid::set_oE(OrangeEGG* oE){        // set OrangeEGG pointer
    oE_list = oE;
    return oE_list;
}

GreenEGG* Grid::get_gE(){                        // return GreenEGG pointer
    return gE_list;
}

GreenEGG* Grid::set_gE(GreenEGG* gE){         // set GreenEGG pointer
    gE_list = gE;
    return gE_list;
}

BlueEGG* Grid::get_bE(){                      // get BlueEGG pointer
    return bE_list;
}

BlueEGG* Grid::set_bE(BlueEGG* bE){       // set BlueEGG pointer
    bE_list = bE;
    return bE_list;
}

RedEGG* Grid::get_rE(){                      // get RedEGG pointer
    return rE_list;
}

RedEGG* Grid::set_rE(RedEGG* rE){       // set RedEGG pointer
    rE_list = rE;
    return rE_list;
}

void Grid::print_game(){                                    // print grid, dragon and eggs in terminal             
    
    // Grid colours (text highlight)
    const std::string blue("\033[3;44;3m");                 // for BlueEGG and boarder
    const std::string white("\033[3;47;3m");                // for the screen where the dragon moves and the eggs spawn
    const std::string green("\033[3;42;3m");                // for GreenEGG
    const std::string orange("\033[3;48;2;255;165;3m");     // for OrangeEGG
    const std::string red("\033[3;41;3m");                  // for RedEGG
    const std::string yellow("\033[3;43;3m");               // for dragon
    const std::string revert("\033[0m");                    // revert back to normal terminal colour style

    // Print grid with array looping over each position and printing the symbol of each egg and the dragon depending on x and y
     for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){

            // Print the dragon symbol
            if (i == dragon_list->get_dragon_y() && j == dragon_list->get_dragon_x()){
                std::cout << yellow << dragon_list->get_dragon_symbol() << " " << revert;
            }

               // set the edge to a blue boarder so the player knows where they cant touch 
            else if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1){
            std::cout << blue << array[i][j] << " " << revert;       
            }

            // Print baby OrangeEGG symbol
            else if (i == oE_list->get_oE_y() && j == oE_list->get_oE_x()){
                std::cout << orange << oE_list->get_oE_symbol() << " " << revert;
            }

            // Print green egg
            else if (i == gE_list->get_gE_y() && j == gE_list->get_gE_x()){
                std::cout << green << gE_list->get_gE_symbol() << " " << revert;
            }

            // Print the blue egg 
            else if (i == bE_list->get_bE_y() && j == bE_list->get_bE_x()){
                std::cout << blue << bE_list->get_bE_symbol() << " " << revert;
            }
            else if (i == rE_list->get_rE_y() && j == rE_list->get_rE_x()){
                std::cout << red << rE_list->get_rE_symbol() << " " << revert;
            } else {
                std::cout << white << array[i][j] << " " << revert;   // Print remaining array in white
            } 
            }
            // end line here so the array loops over until j reaches the max and then the next value of i will be the next row
             std::cout << std::endl;
            
             
        }
       
}
       
    


void Grid::delete_grid(){
    delete[] array; 
}

// Destructor
Grid::~Grid(){
}


