#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * Function Name: min
 * Input: 3 int values which are to be compared
 * Output: Returns the minimum of 3 numbers
 * Logic: To get the minimum of 3 given numbers
 * Example Call: min(5, 8, 18)
 */
int min(int x, int y, int z)
{
  if (x <= y && x <= z)
  {
    return x;
  }
  else
  {
    return min(y, z);
  }
}

/*
 * Function Name: LCS
 * Input: 2 integer vectors
 * Output: Returns the length of longest common subsequence in two strings
 * Logic: Creates a 2D matrix and calculates longest common subsequence using dynamic programming
 * Example Call: LCS(v1, v2)
 */
int LCS(vector<int> num1, vector<int> num2, int x, int y)
{
    int matrix[x + 1][y + 1] ;

    for (int i = 0; i < x + 1; i++)
  {
    matrix[i][0] = 0;
  }

  for (int j = 0; j < y + 1; j++)
  {
    matrix[0][j] = 0;
  }

  for (int i = 1; i < x + 1; i++)
  {
    for (int j = 1; j < y + 1; j++)
    {
      if (num1[i - 1] ==  num2[j - 1])
      {
        matrix[i][j] = matrix[i - 1][j - 1] + 1;
      }
      else
      {
        matrix[i][j] = max(matrix[i][j - 1], matrix[i - 1][j]);
      }
    }
  }

  for (int i = 0 ; i < x+1 ; i++)
  {
    for (int j = 0 ; j < y+1 ; j++)
    {
      cout << matrix[i][j] << " " ;
    }
    cout << endl ;
  }

    return matrix[x][y];
}

int main()
{
  int m, n, z;

  cin >> m;
  vector<int> num1(m);
  for (int i = 0; i < m; i++)
  {
    cin >> num1[i];
  }

  cin >> n;
  vector<int> num2(n);
  for (int i = 0; i < n; i++)
  {
    cin >> num2[i];
  }

  // cin >> z;
  // vector<int> num3(z);
  // for (int i = 0; i < z; i++)
  // {
  //   cin >> num3[i];
  // }

  int lcs = LCS(num1, num2, m, n);
  cout << lcs ;

  return 0;
}