/***************************************************************************
    @brief        Using dynamic programming for 0/1 Knapsack_limited problem
****************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Function Name: knapsack
 * Input: Requires an vector of price, weights, status and values of capacity and n
 * Output: returns the maximum profit
 * Logic: Finds the optimal solution using bottom-to-top method of dynamic programming
 * Example Call: knapsack(price, weight, capacity, n - 1, status)
 */
int knapsack(vector<int> price, vector<int> weight, int capacity, int n, vector<bool> &status)
{
    vector<vector<int>> matrix(weight.size() + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i < matrix.size(); i++)
    {
        for (int j = 1; j < matrix[0].size(); j++)
        {
            if (weight[i - 1] <= j)
            {
                matrix[i][j] = max(matrix[i - 1][j], price[i - 1] + matrix[i - 1][j - weight[i - 1]]);
            }
            else
            {
                matrix[i][j] = matrix[i - 1][j];
            }
        }
    }

    int x = weight.size();
    int y = capacity;
    int index = status.size() - 1;

    while (x != 0)
    {
        if (matrix[x][y] == matrix[x - 1][y])
        {
            status[index] = false;
            x = x - 1;
            index--;
        }
        else
        {
            status[index] = true;
            x = x - 1;
            y = y - weight[x];
            index--;
        }
    }

    return matrix[weight.size()][capacity];
}

int main()
{
    int capacity;
    cout << "Enter the capacity of Knapsack: ";
    cin >> capacity;
    int n;
    cout << "Enter the total number of distinct elements: ";
    cin >> n;
    vector<int> price(n);
    vector<int> weight(n);
    vector<bool> status(n, false);

    for (int i = 0; i < n; i++)
    {
        cout << "Enter weight of item " << i + 1 << " : ";
        cin >> weight[i];
        cout << "Enter price of item " << i + 1 << " : ";
        cin >> price[i];
    }

    int answer = knapsack(price, weight, capacity, n - 1, status);

    for (int i = 0; i < status.size(); i++)
    {
        if (status[i] == true)
        {
            cout << "Item " << i + 1 << " : Taken";
        }
        else
        {
            cout << "Item " << i + 1 << " : Not Taken";
        }
        cout << endl;
    }
    cout << "Maximum profit is: " << answer << endl;

    return 0;
}
/*
Analysis: The above code runs in O(m*n), where n is the number of different object required and m is the capacity of knapsack
*/