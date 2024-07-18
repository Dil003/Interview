// OOP Game Project
// Dragon Game
// OrangeEGG.h outlines the behaviours of the OrangeEGG class.
// The OrangeEGG class contains a default constructor, a modifiable constructor and a range of 'get/set' attributes

#ifndef ORANGEEGG_H
#define ORANGEEGG_H

class OrangeEGG{
    private:
        // OrangeEGG attributes
        int oE_x;                        // x coordinate of OrangeEGG
        int oE_y;                        // y coordinate of OrangeEGG
        char oE_symbol;                  // symbol/character of OrangeEGG
    
    public:
        // Default OrangeEGG constructor
        OrangeEGG(); 

        // OrangeEGG constructor that accepts x/y coordinates and a symbol/letter to represent the Orange egg
        OrangeEGG(int oE_x, int oE_y, char oE_symbol);

        // OrangeEGG behaviours
        int get_oE_x();                  // get x coordinate of Orange egg
        int get_oE_y();                  // get y coordinate of Orange egg
        char get_oE_symbol();            // get symbol/character of Orange egg
        void set_oE_x(int oE_x);         // set x coordinate of Orange egg
        void set_oE_y(int oE_y);         // set y coordinate of Orange egg

        // Here is the Destructor
        ~OrangeEGG();
};

#endif//OrangeEGG