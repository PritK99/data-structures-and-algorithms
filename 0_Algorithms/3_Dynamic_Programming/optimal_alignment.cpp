/***********************************************************************************
    @brief        Using dynamic programming for optimal alignment of 2 strings along with edit distance
************************************************************************************/

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
void edit_distance(string string1, string string2)
{
    string result1 = "", result2 = "";

    int x = string1.length();
    int y = string2.length();
    int matrix[x + 1][y + 1] = {0};

    for (int i = 0; i < x + 1; i++)
    {
        matrix[i][0] = i;
    }

    for (int j = 0; j < y + 1; j++)
    {
        matrix[0][j] = j;
    }

    for (int i = 1; i < x + 1; i++)
    {
        for (int j = 1; j < y + 1; j++)
        {
            if (string1[i - 1] == string2[j - 1])
            {
                matrix[i][j] = min(matrix[i - 1][j - 1], matrix[i][j - 1] + 1, matrix[i - 1][j] + 1);
            }
            else
            {
                matrix[i][j] = min(matrix[i - 1][j - 1], matrix[i][j - 1], matrix[i - 1][j]) + 1;
            }
        }
    }

    int i = x, j = y, counter = 0;
    while (i > 0 || j > 0)
    {
        int temp = matrix[i][j];

        if (i == 0)
        {
            result2 = result2 + string2[j - 1];
            result1 = result1 + "_";
            j = j - 1;
        }
        else if (j == 0)
        {
            result1 = result1 + string1[i - 1];
            result2 = result2 + "_";
            i = i - 1;
        }
        else
        {
            int x = min(matrix[i - 1][j], matrix[i - 1][j - 1], matrix[i][j - 1]);
            if (matrix[i - 1][j - 1] == x)
            {
                result1 = result1 + string1[i - 1];
                result2 = result2 + string2[j - 1];
                i--;
                j--;
            }
            else if (matrix[i][j - 1] == x)
            {
                result2 = result2 + string2[j - 1];
                result1 = result1 + "_";
                j = j - 1;
            }
            else
            {
                result1 = result1 + string1[i - 1];
                result2 = result2 + "_";
                i = i - 1;
            }
        }
    }

    cout << "edit distance is: " << matrix[x][y] << endl;
    cout << result1 << endl
         << result2;
}

int main()
{
    string string1, string2;

    cin >> string1;
    cin >> string2;

    edit_distance(string1, string2);

    return 0;
}

/*
Analysis: The above code runs in O(m*n), where m and n are length of string1 and string2 respectively.
*/