// OOP Game Project
// Dragon Game
// Grid.h outline the attributes and behaviours of a Grid class.
// The Grid class contains places to store an array used to define the game grid, the dragon and the 
// game items (baby OrangeEGG, gE, BlueEGG).

#ifndef GRID_H
#define GRID_H

#include <string>

#include "Dragon.h"
#include "OrangeEGG.h"
#include "GreenEGG.h"
#include "BlueEGG.h"
#include "RedEGG.h"

class Grid{
    private:
        // Something to store an array
        char *p;
        char** array;
    

        // Grid dimensions
        int rows;
        int cols;   

        // Something to store dragon
        Dragon* dragon_list;

        // Something to store game items
        OrangeEGG* oE_list;
        GreenEGG* gE_list;
        BlueEGG* bE_list;
        RedEGG* rE_list;

    public:
        // Defult Grid constructor
        Grid();

        // Grid constructor that accaepts the number of rows and columns
        Grid(int rows, int cols);

        // Grid behaviour
        void print_game();                          // print the grid with the dragon and game items

        Dragon* set_dragon(Dragon* dragon);             // sets dragon for the grid
        Dragon* get_dragon();                         // gets dragon pointer for the grid

        OrangeEGG* set_oE(OrangeEGG* oE);       // sets baby OrangeEGG for the grid
        OrangeEGG* get_oE();                      // gets baby OrangeEGG pointer for the grid

        GreenEGG* set_gE(GreenEGG* gE);         // sets gE for the grid
        GreenEGG* get_gE();                       // gets gE pointer for the grid

        BlueEGG* set_bE(BlueEGG* bE);       // sets BlueEGG for the grid
        BlueEGG* get_bE();                      // gets BlueEGG pointer on the grid

        RedEGG* set_rE(RedEGG* rE);       // sets red egg for the grid
        RedEGG* get_rE();                 // gets red eggs pointer on the grid
    
        void delete_grid();                         // deletes array

        // Destructor
        ~Grid();
};

#endif//GRID
