#include <algorithm>
#include <vector>

/*

Given an integer array nums, find the subarray which has the largest sum and return its sum.

Runtime: 318ms
Memory: 67.7 MB

*/

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        // Initialize maximum sum ending at index 0
    int max_ending_here = nums[0];
    // Initialize maximum sum seen so far
    int max_so_far = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        // Update maximum sum ending at index i
        max_ending_here = std::max(nums[i], max_ending_here + nums[i]);
        // Update maximum sum seen so far
        max_so_far = std::max(max_so_far, max_ending_here);
    }

    return max_so_far;
    }
};