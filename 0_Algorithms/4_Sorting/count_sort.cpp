/****************************************
    @brief        Implementing Count Sort
*****************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;

    string s;
    getline(cin, s);

    int num = 0;
    vector<int> v;

    // Taking input from the user and storing it in a vector of int
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == ' ')
            v.push_back(num), num = 0;
        else
            num = num * 10 + (s[i] - '0');
    }
    v.push_back(num);

    int max = *max_element(v.begin(), v.end());
    vector<int> range(max + 1, 0);

    // This calculates the number of occurences
    for (int i = 0; i < v.size(); i++)
    {
        range[v[i]]++;
    }

    /*This calculates the starting position of each integer*/
    for (int i = 1; i < range.size(); i++)
    {
        range[i] = range[i] + range[i - 1];
    }

    // Shift the array to left side
    rotate(range.begin(), range.begin() + range.size() - 1, range.end());
    range[0] = 0;

    // copy the elements from v to result vector as per their positions
    vector<int> result(v.size());
    for (int i = 0; i < v.size(); i++)
    {
        result[range[v[i]]] = v[i];
        range[v[i]]++;
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}
/*
Analysis: The above algorithn runs in O(n)
*/