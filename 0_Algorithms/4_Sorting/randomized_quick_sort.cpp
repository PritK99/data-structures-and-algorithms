/***************************************************
    @brief        Implementing Randomized Quick Sort
****************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

void Swap(int &i, int &j)
{
    int temp = i;
    i = j;
    j = temp;
}

void random(int l, int r, vector <int> &v)
{
    srand((unsigned)time(NULL));

    int random = l + (rand() % r);

    int temp = v[random] ;
    v[random] = v[l] ;
    v[l] = temp ;
}

/*
 * Function Name: Parition
 * Input: Requires a vector, index of pivot element, starting index and ending element
 * Output: returns the position of pivot element in sorted array
 * Logic: Keeps elements smaller than pivot to its left and larger to its right
 * Example Call: Partition(v, 0, 0, v.size()-1)
 */
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
        else if (v[j] >= v[pivot])
        {
            j--;
        }
    }

    Swap(v[pivot], v[i - 1]);
    return i - 1;
}

/*
 * Function Name: QuickSort
 * Input: Requires a vector, index of pivot element, starting element and ending element
 * Logic: Divides the array as per partition by pivot and creates a sorted array
 * Example Call:  QuickSort(v, pivot, 0, v.size() - 1)
 */
void QuickSort(vector<int> &v, int pivot, int begin, int end)
{
    if (end <= begin)
    {
        return;
    }

    int m = Partition(v, pivot, begin, end); // m represents position of partition

    random(begin, m, v) ;
    QuickSort(v, begin, begin, m - 1);

    // random(m+1, end+1, v) ;
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

    random(0, v.size(), v) ;

    int pivot = 0; 

    cout << endl ;

    QuickSort(v, pivot, 0, v.size() - 1);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}
/*
Analysis: The above code runs averagely in O(nlog(n)) and O(n^2) in worst cases
*/