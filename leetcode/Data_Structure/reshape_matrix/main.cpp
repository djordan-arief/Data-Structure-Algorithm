#include <iostream>
#include <vector>

using namespace std;

/*
In MATLAB, there is a handy function called reshape which can reshape an m x n matrix
into a new one with a different size r x c keeping its original data.

You are given an m x n matrix mat and two integers r and c representing the number of rows
and the number of columns of the wanted reshaped matrix.

The reshaped matrix should be filled with all the elements of the original matrix in
the same row-traversing order as they were.

If the reshape operation with given parameters is possible and legal,
output the new reshaped matrix; Otherwise, output the original matrix.

Runtime: 25ms
Memory: 10.7MB


*/

class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        // check if matrix can be reshaped
        if ((mat.size() * mat[0].size()) != (r * c))
        {
            return mat; // matrix cannot be reshaped
        }
        else
        {
            vector<int> row;
            vector<vector<int>> mat_reshaped;

            // loop through the row of the matrix
            for (int i = 0; i < mat.size(); i++)
            {
                // loop through the column of the matrix
                for (int j = 0; j < mat[i].size(); j++)
                {
                    row.push_back(mat[i][j]);
                    if (row.size() == c)
                    {
                        mat_reshaped.push_back(row);
                        row.clear();
                    }
                }
            }
            return mat_reshaped;
        }
    }
};