/******************************************************************************
    @brief        A naive implementation of coin change problem.
*******************************************************************************/

#include <iostream>

using namespace std;

int minCoins(int C[], int l, int N)
{
    if (N == 0) // base case
        return 0;
    int coinsRequired = INT_MAX;
    for (int i = 0; i < l; i++)
    {
        if (C[i] <= N)
        {
            int curr = minCoins(C, l, N - C[i]);
            /*checking if any combinations exist with the current denomination and the length of the combination is less than coinsRequired*/
            if (curr != INT_MAX && curr + 1 < coinsRequired)
                coinsRequired = curr + 1; // updating the result with the minimum number
        }
    }
    return coinsRequired;
}

int coinChange(int C[], int l, int N)
{ // wrapper method to handle -1 case
    int coinsRequired = minCoins(C, l, N);
    if (coinsRequired == INT_MAX)
        return -1;
    return coinsRequired;
}

int main()
{
    int coins[] = {10, 6, 1}; // denominations
    cout << "Please enter the change required: ";
    int N;
    cin >> N;
    int l = sizeof(coins) / sizeof(coins[0]); // number of denominations
    int coinsRequired = coinChange(coins, l, N);

    if (coinsRequired == -1)
        cout << "Given value cannot be exchanged with available denominations";
    else
        cout << "Minimum coins required are " << coinsRequired;

    return 0;
}
