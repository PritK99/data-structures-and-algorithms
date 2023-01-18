/*
Compute the minimum number of coins needed to change the given value into coins with denominations 1, 5, and 10.
*/

#include <iostream>
using namespace std;

int get_change(int m)
{
  int n = (m / 10) + ((m % 10) / 5) + (m % 5);
  return n;
}

int main()
{
  int m;
  cin >> m;
  cout << get_change(m) << '\n';
}
