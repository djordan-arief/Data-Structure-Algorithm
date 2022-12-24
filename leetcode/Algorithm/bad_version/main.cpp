#include <iostream>
#include <vector>
#include <algorithm>
/*
Given a sorted array of distinct integers and a target value, 
return the index if the target is found. If not, return the index 
where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.



*/

class Solution
{
public:
    int searchInsert(std::vector<int> &nums, int target){
        if (target < nums[0])
            return 0;
        if (target > nums[nums.size() - 1])
            return nums.size();

        // Initialize left and right pointers
        int left = 0, right = nums.size() - 1;
        // Binary search loop
        while (left <= right){
            int mid = left + (right - left) / 2;
            // Check if the target is smaller than the middle element
            if (target < nums[mid]){
                right = mid - 1;
            }
            // Check if the target is larger than the middle element
            else if (target > nums[mid]){
                left = mid + 1;
            }
            // If the target is equal to the middle element, return the index
            else{
                return mid;
            }
        }
        return left;
    }
};
