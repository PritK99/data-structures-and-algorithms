/******************************************************************************
    @brief        Using dynamic programming for coin change problem.
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

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
