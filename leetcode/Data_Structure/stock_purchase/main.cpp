#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a
different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction.
If you cannot achieve any profit, return 0.

Runtime: 128ms
memory: 93.2 MB

*/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        // Loop through the stock prices
        for (int i = 0; i < prices.size(); i++)
        {
            // Update the minimum price and maximum profit at the same time
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }

        return maxProfit;
    }
};

int main()
{
    // std::vector <int> v1 {7,6,4,3,1};
    // std::vector <int> v2 {7,1,5,3,6,4};

    // std::vector<int> v3{4, 7, 4, 6};
    // std::vector <int> v4 {4, 7, 2, 4};
    std::vector<int> v5{23, 19, 34, 22, 31};

    Solution s1;
    s1.maxProfit(v5);
    return 0;
}