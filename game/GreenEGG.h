// OOP Game Project
// Dragon Game
// GreenEGG.h outlines the behaviours of the GreenEGG class.
// The GreenEGG class contains a default constructor, a modifiable constructor and a range of 'get/set' attributes

#ifndef GREENEGG_H
#define GREENEGG_H

class GreenEGG{
    private:
        // GreenEGG attributes
        int gE_x;                           // x coordinate of gE
        int gE_y;                           // y coordinate of gE
        char gE_symbol;                     // symbol/character of gE

    public:
        // Default GreenEGG constructor
        GreenEGG();

        // GreenEGG constructor that accepts x/y coordinates and a symbol/letter to represent the Green egg
        GreenEGG(int gE_x, int gE_y, char gE_symbol);

        // GreenEGG behaviours
        int get_gE_x();                     // get x coordinate of Green egg
        int get_gE_y();                     // get y coordinate of Green egg
        char get_gE_symbol();               // get symbol/character of Green egg
        void set_gE_x(int gE_x);            // set x coordinate of Green egg
        void set_gE_y(int gE_y);            // set y coordinate of Green egg

        // Here is the Destructor
        ~GreenEGG();

};

#endif//GreenEGG