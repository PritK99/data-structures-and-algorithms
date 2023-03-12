/*This is a dynamic programming approach to the cut-rod problem using bottom-top approach.This algorithm works in n^(2) or polynomial time.*/
#include <iostream>
#include <vector>

using namespace std;

int cutRod(vector<int> price,vector<int> &result, int size)
{
    if (size == 0) // base case
    {
        return 0;
    }

    result[0] = size*price[0] ;

    for (int i = 1; i <= size; i++)
    {
        int total = INT_MIN;
        for (int j = 1 ; j <= i; j++)
        {
            total = max(total, price[j] + price[i-j] );
        }
        result[i] = total;
    }

    return price[size-1]  ;
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
    vector<int> result(size, INT_MIN);

    for (int i = 0; i < size; i++)
    {
        cout << "Enter price of rod for length " << i + 1 << ": ";
        cin >> price[i];
    }

    int max_price = cutRod(price, result, size);

    cout << "The maximum price possible is: " << max_price;
}