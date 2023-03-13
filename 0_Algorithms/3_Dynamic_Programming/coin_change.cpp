/******************************************************************
    @brief        Using dynamic programming for coin change problem.
*******************************************************************/

#include <iostream>
#include <vector>

using namespace std;

/*
 * Function Name: minCoins
 * Input: Requires an vector of denominations and the value for which change is required
 * Output: returns the minimum number of coins require
 * Logic: Finds the optimal minimum solution using bottom-to-top method of dynamic programming
 * Example Call: minCoins(denomination, change)
 */
int minCoins(vector<int> denomination, vector<int> change)
{
    for (int i = 1; i < change.size(); i++)
    {
        int coinsRequired = INT_MAX;
        for (int j = 0; j < denomination.size(); j++)
        {
            if (i >= denomination[j])
            {
                if (change[i - denomination[j]] + 1 < coinsRequired)
                {
                    change[i] = change[i - denomination[j]] + 1;
                    coinsRequired = change[i];
                }
            }
        }
    }

    return change[change.size() - 1];
}

int main()
{
    vector<int> denomination = {1, 6, 10}; // denominations
    cout << "Please enter the change required: ";
    int N;
    cin >> N;
    vector<int> change(N + 1);
    change[0] = 0; // It takes 0 coins to change 0 cents
    int coinsRequired = minCoins(denomination, change);

    if (coinsRequired == 0)
    {
        cout << "The given value can not be changed with the current denomination.";
    }
    else
    {
        cout << "Minimum coins required are " << coinsRequired;
    }

    return 0;
}

/*
Analysis: The above code runs in O(m*n), where n is the value of change required and m is the number of denominations
*/