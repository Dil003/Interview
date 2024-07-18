// OOP Game Project
// Dragon Game
// BlueEGG.h outlines the behaviours of the BlueEGG class.
// The BlueEGG class contains a default constructor, a modifiable constructor and a range of 'get/set' attributes

#ifndef BLUEEGG_H
#define BLUEEGG_H

class BlueEGG{
    private:
        // BlueEGG attributes
        int bE_x;                             // x coordinate of Blue egg
        int bE_y;                             // y coordinate of Blue egg
        char bE_symbol;                       // symbol/character of Blue egg

    public:
        // Default Blue egg constructor
        BlueEGG();

        // BlueEGG constructor that accaepts x/y coordinates and a symbol/letter to represent the Blue egg
        BlueEGG(int bE_x, int bE_y, char bE_symbol);

        // BlueEGG behaviours
        int get_bE_x();                       // get x coordinate of Blue egg
        int get_bE_y();                       // get y coordinate of Blue egg
        char get_bE_symbol();                 // get symbol/character of Blue egg
        void set_bE_x(int bE_x);              // set x coordinate of Blue egg
        void set_bE_y(int bE_y);              // set y coordinate of Blue egg

        // Here is the Destructor
        ~BlueEGG();
};
#endif//BlueEGG