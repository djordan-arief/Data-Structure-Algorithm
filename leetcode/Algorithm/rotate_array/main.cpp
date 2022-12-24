#include <vector>
#include <algorithm>

/*
Given an array, rotate the array to the right by k steps, 
where k is non-negative.

Ex 1:
Array = [1, 2, 3, 4, 5, 6, 7], K = 3
result = [5,6,7, 1, 2, 3, 4]

*/


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        std::rotate(nums.begin(), nums.begin() + nums.size() - k, nums.end());
    }
};