/*
Approach 1: DFS & Backtracking
Runtime: 555ms
Memory: 8.70MB
Time Complexity: O(m*n*(3^w)), where m*n is dimension of board and w is length of word
*/
class Solution {
public:
    bool dfs(string word, vector<vector<char>>& board, vector<vector<bool>> &visited, int i, int j, int k)
    {
        visited[i][j] = 1;
        if (k > word.size()-1)
        {
            return true;
        }
        // cout << i << j << word[k-1] << k << word.size()<< endl;

        if (j != 0)
        {
            if(word[k] == board[i][j-1] && visited[i][j-1] == 0)
            {
                if (dfs(word, board, visited,i, j-1, k+1))
                {
                    return true;
                }
            }
        }
        if (j!=board[0].size()-1 && visited[i][j+1] == 0)
        {
            if(word[k] == board[i][j+1])
            {
                if (dfs(word, board, visited,i, j+1, k+1))
                {
                    return true;
                }
            }
        }
        if (i!=0 && visited[i-1][j] == 0)
        {
            if(word[k] == board[i-1][j])
            {
                if (dfs(word, board, visited,i-1, j, k+1))
                {
                    return true;
                }
            }
        }
        if (i!=board.size()-1 && visited[i+1][j] == 0)
        {
            if(word[k] == board[i+1][j])
            {
                if (dfs(word, board, visited,i+1, j, k+1))
                {
                    return true;
                }
            }
        }
        visited[i][j] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (word[0] == board[i][j])
                {
                    vector<vector<bool>> visited (m, vector <bool> (n));
                    if (dfs(word, board, visited,i, j, 1))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};