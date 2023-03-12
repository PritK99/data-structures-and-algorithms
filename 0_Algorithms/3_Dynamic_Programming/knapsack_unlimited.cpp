#include <iostream>
#include <vector>

using namespace std;

int knapsack(vector<int> objects, vector<int> price, int n, int size)
{
    vector<int> result(size + 1);
    result[0] = 0; // for a bag with zero capacity
    for (int i = 1; i <= size; i++)
    {
        int total = INT_MIN;
        for (int j = 0; j < n; j++)
        {
            if (objects[j] <= i)
            {
                total = max(total, price[j] + result[i - objects[j]]);
            }
        }
        if (total == INT_MIN)
        {
            result[i] = 0;
        }
        else
        {
            result[i] = total;
        }
    }

    return result[size] ;
}

int main()
{
    int size;
    cout << "Please enter the capacity of bag: ";
    cin >> size;
    int n;
    cout << "Please enter number of different objects: ";
    cin >> n;
    vector<int> objects;
    vector<int> price;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cout << "Enter weight and price of object " << i + 1 << ": ";
        cin >> x >> y;
        objects.push_back(x);
        price.push_back(y);
    }

    int loot = knapsack(objects, price, n, size);

    cout << "The maximum loot is: " << loot;
}