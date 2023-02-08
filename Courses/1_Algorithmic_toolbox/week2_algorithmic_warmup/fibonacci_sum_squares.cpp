#include <iostream>
/*
Here, F1^2 + F2^2 ...... + Fn^2 = Fn * F(n+1)
Thus, term1 is nth fibonacci term
term2 is (n+1)th fibonacci term
we simply output the last digit of term1*term2
*/
int term1 = 0, term2 = 0;

int get_fibonacci_last_digit_naive(long long n)
{
    if (n <= 1)
        return n;

    int previous = 0;
    int current = 1;

    for (int i = 0; i < n - 1; ++i)
    {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;

        if (current > 9)
        {
            current %= 10;
        }
        if (previous > 9)
        {
            previous %= 10;
        }
    }

    term1 = current % 10;

    int tmp_previous = previous;
    previous = current;
    current = tmp_previous + current;

    if (current > 9)
    {
        current %= 10;
    }
    if (previous > 9)
    {
        previous %= 10;
    }

    term2 = current % 10;

    return 0;
}

int main()
{
    long long n;
    std::cin >> n;
    get_fibonacci_last_digit_naive(n);
    if (n <= 1)
    {
        std::cout << n << '\n';
    }
    else
    {
        long long c = term1 * term2 % 10;
        std::cout << c << '\n';
    }
}
