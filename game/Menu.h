// OOP Game Project
// Dragon Game
// Menu.h outlines atribute and behaviours of Menu class

#ifndef MENU_H
#define MENU_H

class Menu{
    private:
        int _choice;

    public:
        // Menu constructor
        Menu();

        // Menu behaviours
        void display_menu();                        
        void display_rules();
        void display_game_over();
        void set_choice(int);
        int get_choice();

        // Destructor
        ~Menu();
};

#endif
