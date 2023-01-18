#include <iostream>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int i = 1;
  int count = 0;

  while (n > 0 && n >= i)
  {
    n = n - i;
    count++;
    i++;
  }

  int solution[count] = {0} ;

  for (int i = 0 ; i < count ; i++)
  {
    solution[i] = i+1 ;
  }

  solution[count-1] += n ;

  cout << count << endl ;
  for (int i = 0 ; i < count ; i++)
  {
    cout << solution[i] << " " ;
  }

  return 0;
}