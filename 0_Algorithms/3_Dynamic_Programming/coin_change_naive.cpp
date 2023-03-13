/******************************************************************************
    @brief        A naive implementation of coin change problem using recursion
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

/*
 * Function Name: coinChange
 * Input: Requires an vector of denominations and the value for which change is required
 * Output: returns the minimum number of coins require
 * Logic: Finds the optimal solution by exploring all the possibilities using recursion
 * Example Call: coinChange(coins, n)
 */
int coinChange(vector<int> coins, int n)
{
    if (n == 0) // base case
        return 0;
    int coinsRequired = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        if (coins[i] <= n)
        {
            int curr = coinChange(coins, n - coins[i]);
            /*checking if any combinations exist with the current denomination and the length of the combination is less than coinsRequired*/
            if (curr != INT_MAX && curr + 1 < coinsRequired)
                coinsRequired = curr + 1; // updating the result with the minimum number
        }
    }
    return coinsRequired;
}

int main()
{
    vector<int> coins = {10, 6, 1}; // denominations
    cout << "Please enter the change required: ";
    int n;
    cin >> n;

    int coinsRequired = coinChange(coins, n);

    if (coinsRequired == -1)
        cout << "Given value cannot be exchanged with available denominations";
    else
        cout << "Minimum coins required are: " << coinsRequired;

    return 0;
}

/*
Analysis: The above code runs in O(2^n), where n is the value of change required.
*/