#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
 * Function Name: pallindrome
 * Input: 2 strings
 * Output: Returns the length of longest common substring in two strings
 * Logic: Creates a 2D matrix and calculates longest common substring using dynamic programming
 * Example Call: pallindrome(string1, string2)
 */
void pallindrome(string string1)
{
    int x = string1.length();
    string string2 = string1;
    reverse(string2.begin(), string2.end()); // reversing the string 2

    int matrix[x + 1][x + 1] = {0};

    for (int i = 0; i < x + 1; i++)
    {
        matrix[i][0] = 0;
    }

    for (int j = 0; j < x + 1; j++)
    {
        matrix[0][j] = 0;
    }

    for (int i = 1; i < x + 1; i++)
    {
        for (int j = 1; j < x + 1; j++)
        {
            if (string1[i - 1] == string2[j - 1])
            {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            }
            else
            {
                matrix[i][j] = 0;
            }
        }
    }

    for (int i = 0 ; i < x+1 ;i++)
    {
        for (int j = 0 ; j < x+1; j++)
        {
            cout << matrix[i][j] << " " ;
        }
        cout << endl ;
    }
    cout << endl ;

    int max = 0 ; 
    int max_i = 0 , max_j = 0 ;

    for (int i = 0 ; i < x+1 ; i++)
    {
        for (int j = 0 ; j < x+1 ; j++)
        {
            if (matrix[i][j] > max)
            {
                max = matrix[i][j] ;
                max_i = i ;
                max_j = j ;
            }
        }
    }

    vector<char> result;

    cout << max_i << " " << max_j << " " << max << endl ;

    if (max_i == max_j || max_i > max_j)
    {
        for (int i = max; i > 0 ; i--)
        {
            result.push_back(string2[max_j-1]);
            max_i -- ;
            max_j -- ;
        }
    }
    else
    {
        for (int i = max; i > 0 ; i--)
        {
            result.push_back(string1[max_i-1]);
            max_i -- ;
            max_j -- ;
        }
    }

    for (int i = 0; i < result.size() ; i++)
    {
        cout << result[i] ;
    }
    cout << endl;

    
    // for (int i = 0; i < x + 1; i++)
    // {
    //     result.push_back(matrix[i][i]);
    // }

    

    // int max_length = *max_element(result.begin(), result.end()) ;
    // int index = distance(result.begin(), max_element(result.begin(), result.end()));

    // for (int i = index ; i > index-max_length ; i--)
    // {
    //     cout << string1[i-1] ;
    // }

    // int super_index = 0;
    // int super_count = 0;
    // int temp_index = 0;
    // int temp_count = 0;

    // for (int i = 0; i < x; i++)
    // {
    //     if (result[i + 1] - 1 == result[i])
    //     {
    //         if (temp_count == 0)
    //         {
    //             temp_index = i;
    //         }
    //         temp_count++;
    //         if (super_count < temp_count)
    //         {
    //             super_index = temp_index;
    //             super_count = temp_count;
    //         }
    //     }
    //     else
    //     {
    //         temp_count = 0;
    //     }
    // }

    // cout << super_count << " " << super_index ;

    // for (int i = 0; i < super_count; i++)
    // {
    //     cout << string1[super_index + i];
    // }
    // cout << endl;
}

int main()
{

    string string1;
    cout << "Please enter the sequence: ";
    cin >> string1;

    pallindrome(string1);

    return 0;
}