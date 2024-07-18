// OOP Game Project
// Dragon Game

// Test menu in main

#include <iostream>
#include <string>
#include <unistd.h>
#include "Menu.h"
using namespace std;

int main(){
    Menu m1;
    bool valid = false;
    while (valid != true){
        m1.set_choice(0); // reinitialize choice
        m1.display_menu();
        switch(m1.get_choice()){
            case 1:
                // m1.display_levels();
                valid = true;
                // create game object
                break;
            case 2:
                cout << endl;
                m1.display_rules();
                break;
            case 3:
                valid = true;
                return 0;
                break;
            default:
                cout << endl;
                cout << "       Invalid choice please try again\n";
                break;
        }
    }

    return 0;
}
