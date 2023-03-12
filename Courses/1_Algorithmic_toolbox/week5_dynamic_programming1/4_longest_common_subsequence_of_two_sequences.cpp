#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

int edit_distance(vector<int> num1, vector<int> num2, int x, int y, int count)
{
  int matrix[x + 1][y + 1] = {0};

  for (int i = 0; i < x + 1; i++)
  {
    matrix[i][0] = i;
  }

  for (int j = 0; j < y + 1; j++)
  {
    matrix[0][j] = j;
  }

  for (int i = 1; i < x + 1; i++)
  {
    for (int j = 1; j < y + 1; j++)
    {
      if (num1[i - 1] == num2[j - 1])
      {
        matrix[i][j] = min(matrix[i - 1][j - 1], matrix[i][j - 1] + 1, matrix[i - 1][j] + 1);
      }
      else
      {
        matrix[i][j] = min(matrix[i - 1][j - 1], matrix[i][j - 1], matrix[i - 1][j]) + 1;
      }
    }
  }

  for (int i = 0 ; i < x+1 ; i ++)
  {
    for (int j = 0 ; j < y+1; j++)
    {
      cout << matrix[i][j] << " " ;
    }
    cout << endl;
  }

  int i = x, j = y, counter = 0;
  while (i > 0 || j > 0)
  {
    int temp = matrix[i][j];

    if (i == 0)
    {
      j = j - 1;
    }

    else if (j == 0)
    {
      i = i - 1;
    }

    else
    {
      int x = min(matrix[i - 1][j], matrix[i - 1][j - 1], matrix[i][j - 1]);

      if (matrix[i - 1][j - 1] == x && x == temp)
      {
        counter++;
        cout << num1[i - 1] << " - " << num2[j - 1] << endl;
        i--;
        j--;
      }
      else if (matrix[i][j - 1] == x)
      {
        j = j - 1;
      }
      else if (matrix[i - 1][j] == x)
      {
        i = i - 1;
      }
      else
      {
        i--;
        j--;
      }
    }
  }

  cout << counter << endl;

  return matrix[x][y];
}

int main()
{
  int m, n;
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

  int cost = 0;

  int total_cost = edit_distance(num1, num2, m, n, cost);

  return 0;
}