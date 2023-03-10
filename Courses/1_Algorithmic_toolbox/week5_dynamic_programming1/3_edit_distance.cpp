#include <iostream>
#include <string>
#include <vector>

using namespace std;

int min (int x, int y, int z)
{
  if (x <= y && x <= z )
  {
    return x ;
  }
  else
  {
    return min(y,z) ;
  }
}

int edit_distance(string string1, string string2, int x, int y, int count)
{
  int matrix[x+1][y+1] = {0} ;

  for (int i = 0 ; i < x+1 ; i++ )
  {
    matrix[i][0] = i ;
  }

  for (int j = 0 ; j < y+1 ; j++ )
  {
    matrix[0][j] = j ;
  }

  for (int i = 1 ; i < x+1 ; i++)
  {
    for(int j = 1 ; j < y+1 ; j++)
    {
      if (string1[i-1] == string2[j-1])
      {
        matrix[i][j] = min(matrix[i-1][j-1], matrix[i][j-1] + 1 , matrix[i-1][j] + 1);
      }
      else
      {
        matrix[i][j] = min(matrix[i-1][j-1], matrix[i][j-1], matrix[i-1][j]) + 1;
      }
    }
  }

  return matrix[x][y] ;
}

int main()
{
  string string1, string2;
  cin >> string1;
  cin >> string2;

  int i = string1.length();
  int j = string2.length();

  int cost = 0;

  int total_cost = edit_distance(string1, string2, i, j, cost);
  cout << total_cost;
  return 0;
}