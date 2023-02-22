#include <iostream>
#include <vector>
using namespace std;

/*
Given n pairs of parentheses, write a function to 
generate all combinations of well-formed parentheses.

*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr = "";
        int open = 0, close = 0;
        generate(res, curr, open, close, n);
        return res;
    }

    void generate(vector<string>& res, string& curr, int open, int close, int n){
        if (open == n && close == n) {
            res.push_back(curr);
            return;
        }
        if (open < n) {
            curr.push_back('(');
            generate(res, curr, open + 1, close, n);
            curr.pop_back();
        }
        if (close < open) {
            curr.push_back(')');
            generate(res, curr, open, close + 1, n);
            curr.pop_back();
        }
    }
};