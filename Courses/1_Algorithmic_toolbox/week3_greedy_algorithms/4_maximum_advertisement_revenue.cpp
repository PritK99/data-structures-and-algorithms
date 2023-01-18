#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using std::vector;

long long max_dot_product(vector<int> a, vector<int> b) {
  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    // result += ((long long) a[i]) * b[i];
    result += ((long long) *max_element(a.begin(), a.end() ) )* (* max_element(b.begin(), b.end() ));
    *max_element(a.begin(), a.end() ) = 0 ;
    *max_element(b.begin(), b.end() ) = 0 ;
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
