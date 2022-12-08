#include <set>
#include <vector>
#include <algorithm>

/*

Given an integer vector nums, return true if any value appears at least twice in the array, 
and return false if every element is distinct.

Runtime: 137ms
Memory: 54.9 MB

*/

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::set <int> set_int; 
        std::for_each(nums.begin(), nums.end(), [&set_int](int x){set_int.insert(x);});
        if (nums.size() > set_int.size()){
            return true;
        }
        return false; 
    }
};