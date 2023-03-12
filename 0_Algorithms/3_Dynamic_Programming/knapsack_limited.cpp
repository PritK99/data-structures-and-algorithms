#include <iostream>
#include <vector>

using namespace std;

int knapsack(vector<int> weight, vector<int> price, int capacity, int n)
{
    int matrix[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            matrix[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= capacity; j++)
        {
            if (j >= weight[i])
            {
                matrix[i][j] = max(matrix[i - 1][j], matrix[i - 1][j] + price[j]);
            }
        }
    }

    // Printing the matrix
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return matrix[n][capacity];
}

int main()
{
    int capacity, n;
    cout << "Please enter total capacity of bag: ";
    cin >> capacity;
    cout << "Please enter total number of distinct objects: ";
    cin >> n;

    vector<int> price(n);
    vector<int> weight(n);

    for (int i = 0; i < n; i++)
    {
        cout << "Enter weight of object " << i + 1 << ": ";
        cin >> weight[i];
        cout << "Enter price of object " << i + 1 << ": ";
        cin >> price[i];
    }

    int result = knapsack(weight, price, capacity, n);

    cout << "Total profit: " << result;
}