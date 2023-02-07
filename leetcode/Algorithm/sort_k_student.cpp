/*
There is a class with m students and n exams. 
You are given a 0-indexed m x n integer matrix score, 
where each row represents one student and score[i][j] 
denotes the score the ith student got in the jth exam. 
The matrix score contains distinct integers only.

You are also given an integer k. Sort the students 
(i.e., the rows of the matrix) by their scores in the kth 
(0-indexed) exam from the highest to the lowest.

Return the matrix after sorting it.
Leetcode: 2545 Sort the students by their Kth Score

*/

#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        map<int, vector<int>> m; 
        vector<vector<int>> result;

        for (int i = 0; i < score.size(); i++){
            m[score[i][k]] = score[i];
        }

        auto it = m.rbegin();
        while (it != m.rend()){
            result.emplace_back(it->second);
            it++;
        }
        return result; 
    }
};