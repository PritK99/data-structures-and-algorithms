/**********************************
    @brief        Kadanes Algorithm
***********************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

struct solution {
        int max ;
        int max_i ;
        int max_j ;
    } ;

/*
 * Function Name: maxSubArray
 * Input: Takes the array as input
 * Output: return struct solution
 * Logic: This function finds the subarray with maximum sum
 * Example Call: maxSubArray(nums)
 */
struct solution maxSubArray(vector<int>& nums) {
        struct solution max_solution ;
        max_solution.max_i = 0;
        max_solution.max_j = 0;
        max_solution.max = 0;

        bool reset = 0;
        bool super_reset = 0;
        bool init = 0 ;
        int temp_i = 0;

        int curr = 0;

        int n = nums.size() ;

        for (int i = 0; i < n ; i++)
        {
            curr = curr + nums[i];
            if (reset == 1)
            {
                reset = 0;
                super_reset = 1;
                temp_i = i;
            }
            if (curr <= 0)
            {
                curr = 0 ;
                reset = 1 ;
            }
            if (curr > max_solution.max)
            {
                max_solution.max = curr;
                if (max_solution.max_i == 0 && max_solution.max_j == 0 && init == 0)
                {
                    init = 1 ;
                    max_solution.max_i = max_solution.max_j = i ;
                }
                else if (super_reset == 1)
                {
                    max_solution.max_i = temp_i;
                    max_solution.max_j = i ;
                    super_reset = 0 ;
                }
                else
                {
                    max_solution.max_j = i ;
                }
            }
        }

        if (max_solution.max == 0)
        {
            max_solution.max = *max_element(nums.begin(), nums.end()) ;
        }

        return max_solution;  
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

    cout << "The maximum value of subarray is: " << max_solution.max << endl ;
    cout << "The maximum subarray goes from " << max_solution.max_i << " to " << max_solution.max_j << endl ;
    return 0;
}
/*
Analysis: The above algorithm runs in O(n)
*/