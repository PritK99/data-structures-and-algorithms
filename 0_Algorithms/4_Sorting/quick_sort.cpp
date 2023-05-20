#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Swap(int &i, int &j)
{
    int temp = i;
    i = j;
    j = temp;
}

int Partition(vector<int> &v, int pivot, int i, int j)
{
    if (i == j)
    {
        return i;
    }

    while (i <= j)
    {
        if (v[i] > v[pivot] && v[j] < v[pivot])
        {
            swap(v[i], v[j]);
            i++;
            j--;
        }
        else if (v[i] <= v[pivot])
        {
            i++;
        }
        else if (v[j] > v[pivot])
        {
            j--;
        }
    }

    Swap(v[pivot], v[i - 1]);
    return i - 1;
}

void QuickSort(vector<int> &v, int pivot, int begin, int end)
{
    if (end <= begin)
    {
        return;
    }

    int m = Partition(v, pivot, begin, end); // m represents position of partition

    QuickSort(v, begin, begin, m - 1);
    QuickSort(v, m + 1, m + 1, end);
}

int main()
{
    string s;
    getline(cin, s);

    int num = 0;
    vector<int> v;

    /*Taking input from the user and storing it in a vector of int*/
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == ' ')
            v.push_back(num), num = 0;
        else
            num = num * 10 + (s[i] - '0');
    }
    v.push_back(num);

    int pivot = 0; // Initially the pivot element is element at 0th index

    QuickSort(v, pivot, 0, v.size() - 1);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}