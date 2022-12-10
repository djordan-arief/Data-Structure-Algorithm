#include <vector>

/*


Given an array of integers nums and an integer target, 
return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, 
and you may not use the same element twice.

You can return the answer in any order.

Runtime: 405ms
Memory: 10.2 MB

*/

std::vector <int> TwoSum (std::vector <int> &nums, int target){
     // check every possible pair of numbers
  for (int i = 0; i < nums.size(); ++i)
  {
    for (int j = i + 1; j < nums.size(); ++j)
    {
      // if the numbers add up to the target sum, return their indices
      if (nums[i] + nums[j] == target)
      {
        return {i, j};
      }
    }
  }

  // if no pair of numbers adds up to the target sum, return an empty vector
  return {};
}

int main (){
    std::vector <int> vect {3,2,4}; 
    TwoSum(vect, 6); 
    return 0; 
}
