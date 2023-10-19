/*
Approach 1: Store all locations of 0s in a vector and then set zero for all rows and columns
Runtime: 12ms
Memory: 13.8MB
Time Complexity: O((m*n)(m+n)), where m*n is dimension of board. The worst case can be when the entire matrix is filled with zeros and each zero requires (m+n) time complexity to SetZero.
*/
class Solution {
public:
    void setZero(vector<vector<int>>& matrix, int i, int j)
    {
        for (int x = 0; x < matrix.size(); x++ )
        {
            matrix[x][j] = 0;
        }

        for (int x = 0; x < matrix[0].size(); x++ )
        {
            matrix[i][x] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector <pair <int, int>> v;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    pair <int, int> p;
                    p.first = i;
                    p.second = j;
                    v.push_back(p);
                }
            }
        }

        for (int i = 0; i < v.size(); i++)
        {
            setZero(matrix, v[i].first, v[i].second);
        }
    }
};

/*
Approach 2: Store all rows and cols of 0s in a set and then set zero for all rows and columns
Runtime: 7ms
Memory: 13.92MB
Time Complexity: O(m^2 + n^2 + m*n), where m*n is dimension of board. The worst case can be when the entire matrix is filled with zeros and each zero requires (m+n) time complexity to SetZero.
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set <int> row;
        set <int> col;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        //row sweeper
        for (auto i : row)
        {
            for (int x = 0; x < matrix[0].size(); x++)
            {
                matrix[i][x]=0;
            }
        }
        //col sweeper
        for (auto i : col)
        {
            for (int x = 0; x < matrix.size(); x++)
            {
                matrix[x][i]=0;
            }
        }
    }
};

/*
Approach 3: Without using additional memory by using matrix first row and first column itself as flag.
Runtime: 16ms
Memory: 13.6MB
Time Complexity: O(m^2 + n^2 + m*n), where m*n is dimension of board. The worst case can be when the entire matrix is filled with zeros and each zero requires (m+n) time complexity to SetZero.
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool special_row = 0, special_col = 0;

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    if (i == 0)
                    {
                        special_row = 1;
                    }
                    if (j == 0)
                    {
                        special_col = 1;
                    }
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        //row sweeper
        for (int x = 1; x < matrix.size(); x++)
        {
            if (matrix[x][0]==0)
            {
                for (int i = 1; i < matrix[0].size(); i++)
                {
                    matrix[x][i]=0;
                }
            }  
        }
        //col sweeper
        for (int x = 1; x < matrix[0].size(); x++)
        {
            if (matrix[0][x]==0)
            {
                for (int i = 1; i < matrix.size(); i++)
                {
                    matrix[i][x]=0;
                }
            }  
        }
        //special check for first row and first col
        if (special_row)
        {
            for (int i = 1; i < matrix[0].size(); i++)
            {
                matrix[0][i]=0;
            }
        }
        if (special_col)
        {
            for (int i = 1; i < matrix.size(); i++)
            {
                matrix[i][0]=0;
            }
        }  
    }
};