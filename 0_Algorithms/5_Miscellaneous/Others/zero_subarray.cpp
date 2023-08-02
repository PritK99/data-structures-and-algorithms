#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

struct solution {
        int max ;
        int max_i ;
        int max_j ;
    } ;

struct solution maxSubArray(vector <int> nums)
{
    struct solution s ;
    int n = nums.size() ;
    s.max = s.max_i = s.max_j = 0;

    int curr = 0;

    for (int i = 0 ; i < n ; i++)
    {
        
    }

    return s ;
}

int main()
{
    int n;
    cout << "Please enter the length of array: ";
    cin >> n;
    vector <int> nums(n) ;
    cout << "Please enter the array: " ;
    for (int i = 0 ; i < n ; i++)
    {
        cin >> nums[i] ;
    }

    struct solution max_solution = maxSubArray(nums);

    cout << "The maximum size of subarray is: " << max_solution.max << endl ;
    cout << "The subarray goes from " << max_solution.max_i << " to " << max_solution.max_j << endl ;
    return 0;
}
/*
Analysis: The above algorithm runs in O(n)
*/