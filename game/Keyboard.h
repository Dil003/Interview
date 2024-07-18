// External code:
// Stack Exchange Inc, orlov_dumitru, 2022, 'Using kbhit() and getch() on Linux'
// <https://stackoverflow.com/questions/29335758/using-kbhit-and-getch-on-linux> 
// Alternative method for kbhit() available from conio.h
// Used to detect keyboard presses since #include <conio.h> is unavailable on linux 
// and group members were unable to get SFML to work on their individual computers

#ifndef KEYBOARD_H
#define KEYBOARD_H
    
#include <termios.h>
    
class Keyboard{
    private:
        struct termios initial_settings, new_settings;
        int peek_character;

    public:
        Keyboard();
        ~Keyboard();
        int kbhit(); // refers to keyboard hit
        int getch(); // gets character corrsponding to the key pressed
};
    
#endif
