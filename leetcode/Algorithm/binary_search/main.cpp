#include <iostream>
#include <algorithm>
#include <vector>
/*
Given an array of integers nums which is sorted in ascending order, 
and an integer target, write a function to search target in nums. 
If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.



*/

class Solution {
public:
    // faster but uses more memory
    int linear_search(std::vector<int>& nums, int target) {
        // find target in vector of integer
        auto it = std::find(nums.cbegin(), nums.cend(), target); 

        // check if target is in vector of integer
        if (it == nums.cend())
            return -1;
        else{
            return std::distance(nums.cbegin(), it); 
        }
    }

    // slower but uses less memory
    int binary_search (std::vector <int> &nums, int target){
        // check if target is in vector of integer
        if (std::binary_search(nums.cbegin(), nums.cend(), target)){

            // find the target
            auto it = std::find(nums.cbegin(), nums.cend(), target);

            // return the index of target
            return std::distance(nums.cbegin(), it);
        }
        else
            return -1; 
    }
   
};