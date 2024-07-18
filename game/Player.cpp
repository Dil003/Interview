// OOP Game Project
// Dragon Game

// Including all libraries and header files
#include "Player.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// Implementation of Player constructor
Player::Player(){
    this->_name = "no_name";
    this->_current_score = 0; // intializing score
    this->_highest_score = get_file_high_score();                   // previous high score
}

// Implementation of get_file_high_score()
int Player::get_file_high_score(){

    // Reading score file
    ifstream score_file;
    score_file.open("score_record.txt");

    std::string score_record;
    vector<int> scores;

    while (getline(score_file, score_record)) {                     // read file contents into string
        scores.push_back(stoi(score_record));                       // converts string to int & storing int into vector
    }

    // If file is not empty, test if data has been stored into vector
    int high_score;

    if(score_record.length() != 0){
        vector<int>::iterator itr;
        sort(scores.begin(), scores.end());

        // Get previous highest score
        high_score = *(scores.end() - 1);
    }
    else{
        high_score = 0;                                             // initializing the high score
        ofstream data_log("data_log.txt", ios::app);                // storing scores/high scores into a .txt file
        data_log << "Empty Score File read successful" << std::endl;
        data_log.close();
    }

    score_file.close();                                             //close file

    return high_score;                                              // returning high score
}

// Implementation of set_name()
void Player::set_name(std::string name){
    this->_name = name;
}

// Implementation of get_name()
string Player::get_name(){
    return this->_name;
}

// Implementation of set_current_score()
void Player::set_current_score(int score){
    this->_current_score = score;
}

// Implementation of get_current_score()
int Player::get_current_score(){
    return this->_current_score;
}

// Implementation of set_high_score()
void Player::set_high_score(int score){
    this->_highest_score = score;
}

// Implementation of get_high_score()
int Player::get_high_score(){
    return this->_highest_score;
}

// Implementation of update_current_score()
void Player::update_current_score(int score){
    this->_current_score += score;
}

// Implementation of update_high_score()
void Player::update_high_score(){
    if(_current_score > _highest_score){
        set_high_score(_current_score);
        cout << "New Best Score!\n";
    }
    else{
        cout << "No New High Score\n";
    }
}

// Implementation of update_score_file()
void Player::update_score_file(int score){
    ofstream score_file("score_record.txt", ios::app);
    score_file << score << "\n";
    score_file.close();
}

// Implementation of Player destructor
Player::~Player(){
}
