#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        auto upper = std::upper_bound(nums.begin(), nums.end(), target); 
        if (*(upper -1) == target)
            return std::distance (nums.begin(), upper -1); 
        else{
            if (target > nums.back())
                return nums.size(); 
            else
                return std::distance (nums.begin(), upper);  
        }
    }
};