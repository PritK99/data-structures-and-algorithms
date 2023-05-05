/********************************************************************************
    @brief        A naive implementation of longest even length substring problem
*********************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int size = s.length();
    vector<int> nums(size);

    // converting string to vector for ease
    for (int i = 0; i < size; i++)
    {
        nums[i] = s[i] - '0';
    }

    int max_len = 0, k = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; (j < size); j += 2) // only even strings are considered
        {
            int k = j - i ;
            if (k < max_len) //only those sub strings whose length is greater than current maximum are considered 
            {
                continue;
            }

            int lsum = 0, rsum = 0;
            for (int p = i; p <= i + (k / 2); p++)
            {
                lsum += nums[p];
            }
            for (int p = i + (k / 2) + 1; p <= j; p++)
            {
                rsum += nums[p];
            }

            if (lsum == rsum)
            {
                if (k > max_len)
                {
                    max_len = k;
                }
            }
        }
    }

    if (max_len != 0 )
    {
        max_len = max_len + 1; // Indexing starts from 0
    }

    cout << max_len;
}
/*
Analysis: The above code runs in O(n^3), where n is length of string.
*/