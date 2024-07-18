// OOP Game Project
// Dragon Game
// RedEGG.h outlines the behaviours of the RedEGG class.
// The RedEGG class contains a default constructor, a modifiable constructor and a range of 'get/set' attributes

#ifndef REDEGG_H
#define REDEGG_H

class RedEGG{
    private:
        // RedEGG attributes
        int rE_x;                             // x coordinate of Red egg
        int rE_y;                             // y coordinate of Red egg
        char rE_symbol;                       // symbol/character of Red egg

    public:
        // Default Red egg constructor
        RedEGG();

        // RedEGG constructor that accepts x/y coordinates and a symbol/letter to represent the Red egg
        RedEGG(int rE_x, int rE_y, char rE_symbol);

        // RedEGG behaviours
        int get_rE_x();                       // get x coordinate of Red egg
        int get_rE_y();                       // get y coordinate of Red egg
        char get_rE_symbol();                 // get symbol/character of Red egg
        void set_rE_x(int rE_x);              // set x coordinate of Red egg
        void set_rE_y(int rE_y);              // set y coordinate of Red egg

        // Here is the Destructor
        ~RedEGG();
};
#endif//RedEGG