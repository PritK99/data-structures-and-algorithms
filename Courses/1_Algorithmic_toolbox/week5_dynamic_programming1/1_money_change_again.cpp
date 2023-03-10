#include <iostream>
#include <vector>

using namespace std;

int minCoins(vector<int> denomination, vector<int> change)
{
    for (int i = 1 ; i < change.size() ; i++)
    {
        int coinsRequired = 9999999 ;
        for (int j = 0 ; j < denomination.size(); j++)
        {
            if (i >= denomination[j])
            {
                if (change[i - denomination[j]] + 1 < coinsRequired )
                {
                    change[i] = change[i - denomination[j]] + 1 ;
                    coinsRequired = change[i];
                }
            }
        }
    }

    return change[change.size() - 1];
}

int main()
{
    vector<int>denomination = {1, 3, 4}; // denominations
    int N;
    cin >> N;
    vector<int> change (N+1) ;
    change[0] = 0 ; //It takes 0 coins to change 0 cents
    int coinsRequired = minCoins(denomination, change);

    if (coinsRequired == 0)
    {
        cout << "The given value can not be changes with the current denomination.";
    }
    else
    {
        cout << coinsRequired;
    }

    return 0;
}
