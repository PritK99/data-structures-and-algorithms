/*
Approach 1: Spiral Traversal
Runtime: 0ms
Memory: 7.31MB
Time Complexity: O(m*n), where m*n is dimension of matrix
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size()-1;
        int col = matrix[0].size()-1;
        vector <int> answer;

        int start_row = 0;
        int start_col = 0;
        while (start_row < row && start_col < col)
        {
            //Top Sequence
            for (int i = start_col; i < col; i++)
            {
                answer.push_back(matrix[start_row][i]);
            }

            //Right Sequence
            for (int i = start_row; i < row; i++)
            {
                answer.push_back(matrix[i][col]);
            }

            //Bottom Sequence
            for (int i = start_col; i < col; i++)
            {
                answer.push_back(matrix[row][matrix[0].size()-1-i]);
            }

            //Left Sequence
            for (int i = start_row; i < row; i++)
            {
                answer.push_back(matrix[matrix.size()-1-i][start_col]);
            }

            row--;
            col--;
            start_row++;
            start_col++;
        }

        if (row == start_row)
        {
            for (int i = start_col; i <= col; i++)
            {
                answer.push_back(matrix[row][i]);
            }
        }
        else if (col == start_col)
        {
            for (int i = start_row; i <= row; i++)
            {
                answer.push_back(matrix[i][col]);
            }
        }
        return answer;
    }
};