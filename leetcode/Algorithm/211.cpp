#include <unordered_map>
#include <vector>
#include <string>
using namespace std; 


/*
Design a data structure that supports adding new words and 
finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string 
in the data structure that matches word or false otherwise. 
word may contain dots '.' where dots can be matched with any letter.


*/

class WordDictionary {
private:
    unordered_map<int, vector<string>> words;
public:
    WordDictionary() {
    }
    
    void addWord(string word) {
        int length = word.length();
        words[length].push_back(word);
    }
    
    bool search(string word) {
        int length = word.length();
        if (words.find(length) == words.end()) {
            return false;
        }
        for (string dict_word : words[length]) {
            bool match = true;
            for (int i = 0; i < length; i++) {
                if (word[i] != '.' && word[i] != dict_word[i]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                return true;
            }
        }
        return false;
    }
};