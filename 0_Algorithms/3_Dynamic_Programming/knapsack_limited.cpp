#include <iostream>
#include <vector>

using namespace std;

int knapsack(vector<vector<int>> &matrix, vector<int> price, vector<int> weight, int capacity, int n)
{
    if (capacity == 0 || n < 0)
    {
        return 0;
    }

    int x = 0, y = 0;

    if (weight[n] <= capacity)
    {
        if (matrix[capacity - weight[n]][n] == 0)
        {
            x = price[n] + knapsack(matrix, price, weight, capacity - weight[n], n - 1);
            matrix[capacity - weight[n]][n] = x;
        }
        else
        {
            x = matrix[capacity - weight[n]][n];
        }
    }

    if (matrix[capacity][n] == 0)
    {
        y = knapsack(matrix, price, weight, capacity, n - 1);
        matrix[capacity][n] = y;
    }
    else
    {
        y = matrix[capacity][n];
    }

    return max(x, y);
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

    for (int i = 0; i < n; i++)
    {
        cout << "Enter weight of item " << i << " : ";
        cin >> weight[i];
        cout << "Enter price of item " << i << " : ";
        cin >> price[i];
    }

    vector<vector<int>> matrix(capacity + 1, vector<int>(weight.size() + 1, 0));

    int answer = knapsack(matrix, price, weight, capacity, n - 1);

    cout << "Maximum profit: " << answer << endl;

    return 0;
}