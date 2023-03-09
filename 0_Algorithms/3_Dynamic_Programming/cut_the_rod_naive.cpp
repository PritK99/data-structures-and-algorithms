/*This is a naive approach to the cut-rod problem. Using recursion, we find the maximum price at which we can cut and sell the rod. Since there are 2^(n-1) different possibilities to cut a rod of length n, this algorithm works in 2^(n) or exponential time.*/
#include <iostream>
#include <vector>

using namespace std;

int cutRod(vector<int> price, int size)
{
    if (size == 0) // base case
    {
        return 0;
    }

    int total = INT_MIN;
    for (int i = 1; i <= size; i++)
    {
        total = max(total, price[i - 1] + cutRod(price, size - i));
    }

    return total;
}

int main()
{
    int size;
    cout << "Please enter the length of rod: ";
    cin >> size;

    if (size < 0)
    {
        cout << "Invalid length";
        exit(0);
    }

    vector<int> price(size);

    for (int i = 0; i < size; i++)
    {
        cout << "Enter price of rod for length " << i + 1 << ": ";
        cin >> price[i];
    }

    int max_price = cutRod(price, size);

    cout << "The maximum price possible is: " << max_price;
}