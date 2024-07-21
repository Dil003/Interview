/*
This program implements a hash table using linear probing for collision resolution.
The hash table is designed to handle insertion, deletion, and searching of keys based on their last character.
It reads input from the user, processes add/delete operations, and prints the stored keys.
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

const int TSize = 26;

class HashTable {
private:
    // Table represented as an array of pairs (key, status)
    pair<string, char> table[TSize];

    // Returns the last character of the key
    char getLastChar(const string& key) {
        return key.back();
    }

    // Hash function: maps characters 'a' to 'z' to integers 0 to 25
    int hash(char lastChar) {
        return lastChar - 'a';
    }

    // Linear probing: move to the next slot, wrap around the table if the current slot is the last one
    int getNextIndex(int index) {
        return (index + 1) % TSize;
    }

public:
    // Constructor: initialize the hash table with empty slots ('n' = never used)
    HashTable() {
        for (int i = 0; i < TSize; i++) {
            table[i] = make_pair("", 'n');
        }
    }

    // Search for key in hash table
    bool keySer(const string& key) {
        char lastChar = getLastChar(key);
        int index = hash(lastChar);

        while (table[index].second != 'n') {
            if (table[index].second == 'o' && table[index].first == key) {
                return true;
            }
            index = getNextIndex(index);
        }
        return false;
    }

    // Insert a key into the hash table
    void keyIns(const string& key) {
        if (keySer(key)) {
            return;
        }

        // Find index to insert the key
        char lastChar = getLastChar(key);
        int index = hash(lastChar);

        // Linear probing until empty slot is found
        while (table[index].second == 'o') {
            index = getNextIndex(index);
        }

        // Insert the key into the found slot
        table[index].first = key;
        table[index].second = 'o'; // 'o' = occupied
    }

    // Remove key from hash table
    void keyRem(const string& key) {
        char lastChar = getLastChar(key);
        int index = hash(lastChar);

        // Linear probing until an empty slot is found or key is found
        while (table[index].second != 'n') {
            if (table[index].second == 'o' && table[index].first == key) {
                table[index].second = 't'; // 't' = tombstone
                return;
            }
            index = getNextIndex(index);
        }
    }

    // Print all keys stored in the hash table
    void printAllKeys() {
        for (int i = 0; i < TSize; i++) {
            if (table[i].second == 'o') {
                cout << table[i].first << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    HashTable hashTable;
    string input;
    getline(cin, input);

    // Create string stream from the user input from getline
    istringstream inputS(input);

    // Tokenize input
    vector<string> inputL((istream_iterator<string>(inputS)), istream_iterator<string>());

    // Iterator for the vector
    vector<string>::iterator inputI = inputL.begin();

    // Process operation add/delete
    while (inputI != inputL.end()) {
        string opString = *inputI;
        char operate = opString[0];
        string key = opString.substr(1);

        if (operate == 'A') {
            hashTable.keyIns(key);
        } else if (operate == 'D') {
            hashTable.keyRem(key);
        }

        // Iterate to next
        inputI++;
    }

    hashTable.printAllKeys();
    return 0;
}
