// OOP Game Project
// Dragon Game

// The Dragon class includes methods to determine location of the Dragon on the game and move the dragon on the grid
#ifndef DRAGON_H
#define DRAGON_H

class Dragon{
    private:
        int dragon_x;
        int dragon_y;
        int dragon_speed;
        char dragon_symbol;
        char dragon_dir;
       
    public:
        // Defult constructor
        Dragon(); 

        // Grid constructor that takes x,y dragon coordinates  and a symbol or letter to represent the dragon
        Dragon(int dragon_x, int dragon_y, char dragon_symbol);
        
        // Dragon behaviours
        int get_dragon_x();                          // gets x coordinate of dragon
        int get_dragon_y();                          // gets y coordinate of dragon
        char get_dragon_symbol();                    // gets the symbol of the dragon
        void set_dragon_x(int dragon_x);              // sets x coordinate of dragon
        void set_dragon_y(int dragon_y);              // gets y coordinate of dragon
        void set_dragon_dir(char dir);               // sets direction of dragon movement
        void set_dragon_movment();                   // sets movement of dragon movement
        
        // Destructor
        ~Dragon();

};

#endif
