#include <iostream>
#include <vector>

using namespace std;

int min(int x, int y, int z)
{
  if (x < y && x < z)
  {
    return x;
  }
  else
  {
    return min(y, z);
  }
}

int minOperations(vector<int> &num)
{
  for (int i = 2; i < num.size(); i++)
  {
    int OperationsRequired = 9999999;

    int x = 999999, y = 999999, z = 999999; 

    if (i >= 1)
    {
      x = num[i - 1] + 1;
    }
    if (i%2 == 0)
    {
      y = num[i / 2] + 1;
    }
    if (i%3 == 0)
    {
      z = num[i / 3] + 1;
    }

    num[i] = min(x, y, z);  
  }

  return num[num.size()-1];
}

int main()
{
  int N;
  cin >> N;
  vector<int> number(N + 1);
  vector<int> result;
  number[0] = 0; // 0 is invalid
  number[1] = 0; // It takes 0 operations to reach from 1 to 1
  int OperationsRequired = minOperations(number);

  cout << OperationsRequired << endl;

  //To print the results

  result.push_back(N) ;

  for (int i = 0 ; i < OperationsRequired ; i++)
  {
      if (number[N-1] + 1 == number[N])
      {
        result.push_back(N-1) ;
        N = N-1 ;
      }
      else if (N%2 == 0 && number[N/2] + 1 == number[N])
      {
        result.push_back(N/2) ;
        N = N/2 ;
      }
      else
      {
        result.push_back(N/3) ;
        N = N/3 ;
      }
  }

  for (int i = result.size() - 1 ; i >= 0; i--)
  {
    cout << result[i] << " " ;
  }
  
  return 0;
}
