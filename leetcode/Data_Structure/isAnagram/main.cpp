#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>


/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or 
phrase, typically using all the original letters exactly once.

Runtime: 10ms 86.10%
Memory: 7.5MB 13.27%


*/

class Solution
{
public:
    bool isAnagram(std::string s, std::string t)
    {
        std::unordered_map<char, int> s_map;
        std::unordered_map<char, int> t_map;

        if (s.size() != t.size())
            return false;
        else{
            // for each character in s, add it to s_map and count the num of appearence
            std::for_each(s.begin(), s.end(), [&s_map](char x){ s_map[x]++; });

            // for each character in t, add it to s_map and count the num of appearence
            std::for_each(t.begin(), t.end(), [&t_map](char x){ t_map[x]++; });

            // check if both map are equal
            if (s_map == t_map)
                return true; 
            else
                return false; 
        }
    }
};

int main()
{
    std::cout << std::boolalpha; 
    Solution s1;
    bool anagram = s1.isAnagram("rat", "car");
    std::cout << anagram << std::endl; 
    return 0;
}