/**************************************************************************
    @brief        Counting the total number of inversions in an given array
**************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

int global_count = 0;

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
            global_count += mid - p; // Inversions
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
    int n;
    cout << "Enter number of elements: " ;
    cin >> n;
    vector<int> v(n);

    cout << "Enter elements of array: " ;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    MergeSort(v, 0, v.size());

    cout << "Total number of inversions: " << global_count;

    return 0;
}
/*
Analysis: The above code runs in O(nlog(n)). The implementation is same as merge sort except for the step where we count number of inversions.
*/