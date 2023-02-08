#include <iostream>

long long gcd(int a, int b) {
  if (b == 0)
  {
    return a ;
  }
  long long a_prime = a % b ;
  return gcd (b , a_prime) ;
}

long long lcm(int a, int b) {
  long long x = gcd(a,b) ;
  // std::cout << x << std::endl;
  long long temp = a/x ;
  return b*temp;
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}
