// OOP Game Project
// Dragon Game

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ifstream score_file;
    score_file.open("score_record.txt");

    string score_record;
    vector<int> scores;

    while (getline(score_file, score_record)) { // read file contents into string
        scores.push_back(stoi(score_record));  // converts string to int & storing int into vector
    }
 

    // if file is not empty, test if data has been stored into vector
    if(score_record.length() != 0){
        vector<int>::iterator itr;
        sort(scores.begin(), scores.end());
        for (itr = scores.begin(); itr < scores.end(); itr++) {
            cout << *itr << endl;
        }

        // get previous highest score
        cout << *(scores.end() - 1) << endl;
    }
    else{ 
        cout << 0 << endl;
        cout << "file is empty\n";
    }

  return 0;
}
