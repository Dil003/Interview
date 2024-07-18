// OOP Game Project
// Dragon Game

// Test Player object

#include "Player.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
    Player p1;

    // check object construction
    cout << p1.get_name() << endl;
    cout << p1.get_current_score() << endl;
    cout << p1.get_high_score() << endl;

    // check set_name
    cout << "Enter player name: \n";
    string name;
    cin >> name;
    p1.set_name(name);
    cout << "Welcome " << p1.get_name() << endl;

    // test update_current_score
    p1.update_current_score(2);
    p1.update_current_score(1);
    p1.update_current_score(5);
    if(p1.get_current_score() != 8){
        cout << "update_current_score() failed \n";
    }

    cout << "Current High Score: " << p1.get_high_score() << endl;

    // test update_high_score (current < high)
    p1.update_high_score();

    // test update_high_score (current = high)
    p1.update_current_score(9);
    p1.update_high_score();

    // test update_high_score (current > high)
    p1.update_current_score(1);
    p1.update_high_score();

    // test update_score_file & get_file_high_score
    cout << p1.get_current_score() << endl;
    p1.update_score_file(p1.get_current_score());
    cout << p1.get_file_high_score() << endl;

    return 0;
}
