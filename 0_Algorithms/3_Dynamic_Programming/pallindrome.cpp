/******************************************************************************************************
    @brief        Using dynamic programming for optimal alignment of 2 strings along with edit distance
*******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * Function Name: min
 * Input: 3 int values which are to be compared
 * Output: Returns the minimum of 3 numbers
 * Logic: To get the minimum of 3 given numbers
 * Example Call: min(5, 8, 18)
 */
int min(int x, int y, int z)
{
    if (x <= y && x <= z)
    {
        return x;
    }
    else
    {
        return min(y, z);
    }
}

/*
 * Function Name: edit_distance
 * Input: 2 strings
 * Output: Optimal alignment between two strings along with their edit distance
 * Logic: Creates a 2D matrix to calculate edit distance and then backtracks to find the optimal alignment
 * Example Call: edit_distance(string1, string2)
 */
int pallindrome(string string1, string string2)
{
    string result = "";

    int x = string1.length();
    int y = string2.length();

    int matrix[x + 1][y + 1];

    for (int i = 0; i < x + 1; i++)
    {
        matrix[i][0] = 0;
    }

    for (int j = 0; j < y + 1; j++)
    {
        matrix[0][j] = 0;
    }

    for (int i = 1; i < x + 1; i++)
    {
        for (int j = 1; j < y + 1; j++)
        {
            if (string1[i - 1] == string2[j - 1])
            {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            }
            else
            {
                matrix[i][j] = max(matrix[i][j - 1], matrix[i - 1][j]);
            }
        }
    }

    for (int i = 0; i < x + 1; i++)
    {
        for (int j = 0; j < y + 1; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return matrix[x][y];
}

int main()
{
    string string1, string2;

    cin >> string1;
    cin >> string2;

    pallindrome(string1, string2);

    return 0;
}

/*
Analysis: The above code runs in O(m*n), where m and n are length of string1 and string2 respectively.
*/