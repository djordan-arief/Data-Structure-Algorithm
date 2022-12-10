#include <iostream>
#include <vector>

/*

You are given two integer arrays nums1 and nums2, 
sorted in non-decreasing order, and two integers m and n, 
representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, 
but instead be stored inside the array nums1. To accommodate this, 
nums1 has a length of m + n, where the first m elements denote the elements 
that should be merged, and the last n elements are set to 0 and should be ignored. 
nums2 has a length of n.

Runtime: 6ms
Memory: 8.9mb

*/

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        nums1.erase(nums1.begin()+ m, nums1.end()); // erase element from m index to end of vector
        nums2.erase(nums2.begin() + n, nums2.end()); // erase element from n index to end of vector

        std::for_each(nums2.begin(), nums2.end(), [&nums1](int x){nums1.push_back(x); }); // insert element v2 to v1
        std::sort(nums1.begin(), nums1.end()); // sort v1 to ascending order
        std::cout << "["; 
        for (int i = 0; i < nums1.size(); i++){ // display all elements in v1
            std::cout << nums1[i] << " "; 
        }
        std::cout << "]" << std::endl; 
    }
};

int main (){
    std::vector <int> vector1 {0}; 
    std::vector <int> vector2 {1}; 

    Solution s1; 
    s1.merge(vector1, 0, vector2, 1); 

    return 0; 
}