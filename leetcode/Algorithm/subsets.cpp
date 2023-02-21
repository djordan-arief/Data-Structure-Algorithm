#include <vector>
using namespace std;

/*
Given an integer array nums of unique elements, return all possible 
subsets(the power set).

The solution set must not contain duplicate subsets. 
Return the solution in any order.


*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // create an initial empty vector
        vector<vector<int>> subs = {{}};

        // for every number in nums vector
        for (int num : nums) {
            int n = subs.size();

            // iterate through existing subsets
            for (int i = 0; i < n; i++) {
                // create a new subsets
                subs.push_back(subs[i]); 

                // add the num into the new subsets
                subs.back().push_back(num);
            }
        }
        return subs;
    }
};