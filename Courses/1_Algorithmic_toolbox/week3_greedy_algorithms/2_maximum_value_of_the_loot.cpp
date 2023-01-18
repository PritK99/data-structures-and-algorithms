#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

double get_optimal_value(int capacity, std::vector<int> weights, std::vector<int> values, int n)
{
  double loot = 0.0;

  std ::vector<double> price(n);
  for (int i = 0; i < n; i++)
  {
    price[i] = values[i] / (weights[i] * 1.0);
  }

  double max = *max_element(price.begin(), price.end());

  while (capacity > 0 && max > 0)
  {
    int i = 0;
    max = *max_element(price.begin(), price.end());

    for (i; i < n; i++)
    {
      if (price[i] == max)
      {
        break;
      }
    }
    while (weights[i] > 0 && capacity > 0)
    {
      loot = loot + max;
      capacity--;
      weights[i]--;
    }

    price[i] = 0;
  }

  return loot;
}

int main()
{
  int n;
  int capacity;
  std::cin >> n >> capacity;
  std::vector<int> values(n);
  std::vector<int> weights(n);
  for (int i = 0; i < n; i++)
  {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values, n);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
