/***********************************************************************************
    @brief        Finding the longest substring such that sum of digits in first half and second half are equal.
************************************************************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * Function Name: check
 * Input: string and start and end indices
 * Output: True if the sum of digits in first half and second half are equal
 * Logic: To evaluate a substring. This is used only for recursive approach.
 * Example Call: check("9036", 0, 3)
 */
bool check(string s, int start, int end)
{
    int a = 0, b = 0;
    int mid = (start+end)/2;

    for (int i = start; i <= mid; i++)
    {
        a += (s[i] - '0');
    }
    for (int i = mid + 1; i <= end; i++)
    {
        b += (s[i] - '0');
    }

    if (a == b)
    {
        return true;
    }
    return false;
}
/*
 * Function Name: moveGen
 * Input: string s
 * Output: The longest substring with equal sum of digits in first half and second half
 * Logic: Iterates through all possible substrings and checks if their sum of digits is equal. Keeps track of the maximum valid substring found.
 * Example Call: moveGen("9036")
 */
string moveGen(string s)
{
    int max_str_i = 0, max_str_j = 0;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i + 1; j < s.length(); j += 2)
        {
            if (j - i + 1 < max_str_j - max_str_i + 1)
            {
                continue;
            }

            if (check(s, i, j))
            {
                if (j - i + 1 > max_str_j - max_str_i + 1)
                {
                    max_str_i = i;
                    max_str_j = j;
                }
            }
        }
    }

    if (max_str_j == 0)
    {
        return "";
    }

    string max_str = s.substr(max_str_i, max_str_j - max_str_i + 1);

    return max_str;
}

/*
 * Function Name: dp
 * Input: string s
 * Output: The longest substring with equal sum of digits in first half and second half
 * Logic: Utilizes dynamic programming to efficiently compute the sum of digits in all substrings. Iterates through substrings, checks if their sum of digits is equal, and updates the maximum substring.
 * Example Call: dp("9036")
 */
string dp(string s)
{
    int max_str_i = 0, max_str_j = 0;
    vector<vector <int>> cache (s.length(), vector <int> (s.length(), 0));

    for (int i = 0; i < s.length(); i++)
    {
        cache[i][i] = s[i]-'0';
    }

    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i+1; j < s.length(); j++)
        {
            cache[i][j] = cache[i][j-1] + (s[j]-'0');
            if ((j-i)%2 != 0)
            {
                int mid = (j+i)/2;
                if (cache[i][mid] == (cache[i][j]/2) && j - i + 1 > max_str_j - max_str_i + 1)
                {
                    max_str_i = i;
                    max_str_j = j;
                }
            }
        }
    }

    if (max_str_j == 0)
    {
        return "";
    }

    string max_str = s.substr(max_str_i, max_str_j - max_str_i + 1);

    return max_str;
}

int main()
{
    string s = "946723";
    // string rec_answer = moveGen(s);
    string dp_answer = dp(s);
    // cout << rec_answer << " " << rec_answer.size() << endl;
    cout << dp_answer << " " << dp_answer.size() << endl;
    return 0;
}

/*
Analysis: The recursive code runs in O(n^3) time and the dp code runs in O(n^2) time with O(n^2) space.
*/