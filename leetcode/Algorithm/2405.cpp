/*
Given a string s, partition the string into one or more substrings 
such that the characters in each substring are unique. 
That is, no letter appears in a single substring more than once.

Return the minimum number of substrings in such a partition.

Note that each character should belong to exactly one substring 
in a partition.
*/
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int partitionString(string s) {
        // map to store the char already in substring
        unordered_map <char, int> m; 

        // count the minimum substrings needed
        int number_substrings = 1; 

        for (int i = 0; i < s.size(); i++){
            // check if the char is already in substring
            if (m[s[i]] != 0){
                // add the number of substring needed
                number_substrings++;

                // clear the content of the map
                m.clear();
            }

            // store the visited char in map; 
            m[s[i]]++;
        }
        return number_substrings;
    }
};