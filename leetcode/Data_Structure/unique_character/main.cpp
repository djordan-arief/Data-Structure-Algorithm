#include <iostream>
#include <string>
#include <map>
#include <unordered_map>

/*
Given a string s, find the first non-repeating character in it 
and return its index. If it does not exist, return -1.

Runtime: 110ms
Memory: 10.8MB

*/

class Solution {
public:
    int firstUniqChar(std::string s) {
        int smallest_index = INT_MAX; 
        std::unordered_map <char, int> mapc; 

        // add every character of the string into map of char
        std::for_each(s.cbegin(), s.cend(), [&mapc](char x){
            mapc[x]++; 
        }); 

        // loop through the map
        for (auto iterator = mapc.begin(); iterator != mapc.end(); iterator ++){

            // check for non repeating character
            if (iterator -> second == 1 && s.find(iterator ->first) < smallest_index){

                // find the smallest index of non repeating character
                smallest_index = s.find(iterator ->first);
            }
        }

        // if smallest index remains INT_MAX, it means there are no non repeating character
        if (smallest_index == INT_MAX)
            smallest_index = -1; 


        return smallest_index;
    }
};

int main (){
    Solution s1;
    s1.firstUniqChar("Hello"); 
    s1.firstUniqChar("Djordan Arief Firdausy"); 
    return 0; 
}
