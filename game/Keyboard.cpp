// External code:
// Stack Exchange Inc, orlov_dumitru, 2022, 'Using kbhit() and getch() on Linux'
// <https://stackoverflow.com/questions/29335758/using-kbhit-and-getch-on-linux> 
// Alternative method for kbhit() available from conio.h
// Used to detect keyboard presses since #include <conio.h> is unavailable on linux 
// and group members were unable to get SFML to work on their individual computers

#include "Keyboard.h"
#include <unistd.h> // read()
    
Keyboard::Keyboard(){
    tcgetattr(0,&initial_settings);
    new_settings = initial_settings;
    new_settings.c_lflag &= ~ICANON;
    new_settings.c_lflag &= ~ECHO;
    new_settings.c_lflag &= ~ISIG;
    new_settings.c_cc[VMIN] = 1;
    new_settings.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &new_settings);
    peek_character=-1;
}
    
Keyboard::~Keyboard(){
    tcsetattr(0, TCSANOW, &initial_settings);
}
    
int Keyboard::kbhit(){
    unsigned char ch;
    int nread;
    if (peek_character != -1) return 1;
    new_settings.c_cc[VMIN]=0;
    tcsetattr(0, TCSANOW, &new_settings);
    nread = read(0,&ch,1);
    new_settings.c_cc[VMIN]=1;
    tcsetattr(0, TCSANOW, &new_settings);

    if (nread == 1){
        peek_character = ch;
        return 1;
    }
    return 0;
}
    
int Keyboard::getch(){
    char ch;

    if (peek_character != -1){
        ch = peek_character;
        peek_character = -1;
    }
    else read(0,&ch,1);
    return ch;
}
