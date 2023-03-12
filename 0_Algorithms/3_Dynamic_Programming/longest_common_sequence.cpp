#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

int lcs(string string1, string string2)
{
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
        cout << i << " " << j << endl ;
        int temp = matrix[i][j];

        if (i == 0)
        {
            j = j - 1;
        }
        else if (j == 0)
        {
            i = i - 1;
        }
        else
        {
            int x = min(matrix[i - 1][j], matrix[i - 1][j - 1], matrix[i][j - 1]);
            if (matrix[i - 1][j - 1] == x)
            {
                if (x == temp)
                {
                    cout << string1[i-1] << " " << string2[j-1] << endl;
                    counter++;
                }
                else if (matrix[i][j - 1] == x )
                {
                    j = j - 1;
                    continue ;
                }
                else if (matrix[i-1][j] == x )
            {
                i = i - 1;
                continue ;
            }
                i--;
                j--;
            }
            else if (matrix[i][j - 1] == x)
            {
                j = j - 1;
            }
            else
            {
                i = i - 1;
            }
        }
    }

    cout << counter << endl;

    return matrix[x][y];
}

int main()
{

    string string1;
    cin >> string1;

    string string2;

    cin >> string2;

    int total_cost = lcs(string1, string2);

    return 0;
}