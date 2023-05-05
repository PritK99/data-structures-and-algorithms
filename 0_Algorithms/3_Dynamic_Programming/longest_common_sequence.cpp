#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * Function Name: LCS
 * Input: 2 strings
 * Output: Returns the length of longest common substring in two strings
 * Logic: Creates a 2D matrix and calculates longest common substring using dynamic programming
 * Example Call: LCS(string1, string2)
 */
int LCS(string string1, string string2)
{
    int x = string1.length();
    int y = string2.length();
    int matrix[x + 1][y + 1] = {0};

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

    return matrix[x][y];
}

int main()
{

    string string1;
    cout << "Please enter first sequence: " ;
    cin >> string1;

    string string2;
    cout << "Please enter second sequence: " ;
    cin >> string2;

    int lcs = LCS(string1, string2);

    cout << "The longest common sequence among two strings is of length: " << lcs ;

    return 0;
}