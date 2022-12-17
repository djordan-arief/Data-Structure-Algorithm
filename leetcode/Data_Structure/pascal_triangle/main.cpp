#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> generate(int numRows)
    {
        std::vector<std::vector<int>> pascal;

        // Iterate over the rows
        for (int i = 0; i < numRows; i++)
        {
            // Create a new row with the same number of columns as the current row number
            std::vector<int> row(i + 1);

            // Set the first and last elements to 1
            row[0] = row[i] = 1;

            // Compute the rest of the elements in the row
            for (int j = 1; j < i; j++)
            {
                row[j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }

            // Add the current row to the triangle
            pascal.push_back(row);
        }

        return pascal;
    }
};

int main()
{
    std::vector<int> vect{1};
    std::cout << vect[1] << std::endl;
    return 0;
}