/*
Approach 1: DFS & Backtracking with pruning strategies
Runtime: 0ms
Memory: 7.25MB
Time Complexity: O(m*n*(3^w)), where m*n is dimension of board and w is length of word
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix.size(); j++)
            {
                if (i > j)
                {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};