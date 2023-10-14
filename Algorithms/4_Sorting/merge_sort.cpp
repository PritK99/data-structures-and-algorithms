/****************************************
    @brief        Implementing Merge Sort
*****************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
 * Function Name: Merge
 * Input: Requires two sorted portions of array defined by left, mid and right
 * Output: returns the merged vector which is sorted
 * Logic: This function merges two sorted arrays and counts the number of inversions
 * Example Call: Merge(A, 0, 4, 2)
 */
void Merge(vector<int> &A, int left, int right, int mid)
{
    int p = left;
    int q = mid;

    vector<int> merged;

    while (p < mid && q < right)
    {
        if (A[p] <= A[q])
        {
            merged.push_back(A[p]);
            p++;
        }
        else
        {
            merged.push_back(A[q]);
            q++;
        }
    }

    while (p < mid)
    {
        merged.push_back(A[p]);
        p++;
    }
    while (q < right)
    {
        merged.push_back(A[q]);
        q++;
    }

    for (int i = 0; i < merged.size(); i++)
    {
        A[left + i] = merged[i];
    }
}

/*
 * Function Name: MergeSort
 * Input: Requires a vector, starting index and ending index
 * Output: returns the sorted array
 * Logic: Recursively divides the given vector in two halves and passes them to merge function
 * Example Call: MergeSort(A, 0, 5)
 */
void MergeSort(vector<int> &A, int begin, int end)
{
    if (end - begin == 1)
    {
        return;
    }
    int mid = floor((end - begin) / 2);
    MergeSort(A, begin, begin + mid);
    MergeSort(A, begin + mid, end);
    Merge(A, begin, end, begin + mid);
}

int main()
{
    cout << "Enter the elements: " ;

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

    MergeSort(v, 0, v.size());

    cout << "The sorted array is: ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
/*
Analysis: The above code runs in O(nlog(n))
*/