// OOP Game Project
// Dragon Game
// Player.h

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player{

    private:
    // Player attributes
        std::string _name;             // name of the player
        int _current_score;            // current score of the player
        int _highest_score;            // highest score achieved by the player
        void set_high_score(int);      // setting the high score achieved by the player

    public:
    //  Defult Player constructor
        Player();

    // Player behaviours
        std::string get_name();            // get name of the player
        void set_name(std::string);        // set name of the player
        int get_current_score();           // get current score of the player
        int get_high_score();              // get high score of the player
        int get_file_high_score();         // get highes score of the player

        void set_current_score(int);       // set current score of the player

        void update_current_score(int);    // update current score of the player
        void update_high_score();          // update high score of the player
        void update_score_file(int);       // update high score of the player in the file

        // Destructor
        ~Player();


};

#endif //PLAYER
