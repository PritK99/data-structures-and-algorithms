#include <iostream>

int get_fibonacci_last_digit_sum(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;
    int sum = 1 ;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;

        if (current > 9)
        {
            current %= 10 ;
        }
        if (previous > 9)
        {
            previous %= 10 ;
        }

        sum = sum + current ;

        if (sum > 9)
        {
            sum %= 10 ;
        }
    }

    return sum;
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_sum(n);
    std::cout << c << '\n';
    }
