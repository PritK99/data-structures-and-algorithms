#include <iostream>

int get_fibonacci_last_digit_partial_sum(int m, int n) {

    if ( n <=1 )
    {
        return n ;
    }

    int previous = 0;
    int current  = 1;
    int sum = 0 ;

    for (int i = 0; i < m - 2; ++i) {
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
        std::cout << previous <<  " " << current << std :: endl ;
    }

    std::cout << std :: endl ;
    
    for (int i = m-n+1; i < n - 2; ++i) {
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

        std::cout << previous <<  " " << current << std :: endl ;
    }

    return sum;
}

int main() {
    int m, n;
    std::cin >> m >> n;
    int c = get_fibonacci_last_digit_partial_sum(m,n);
    std::cout << c << '\n';
    }
